import glob
import os
import shutil
import subprocess
from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout, CMakeDeps


class diplomat_exampleRecipe(ConanFile):
    name = "diplomat_example"
    version = "1.0"
    package_type = "application"

    # Optional metadata
    license = "<Put the package license here>"
    author = "<Put your name here> <And your email here>"
    url = "<Package recipe repository url here, for issues about the package>"
    description = "<Description of diplomat_example package here>"
    topics = ("<Put some tag here>", "<here>", "<and here>")

    # Binary configuration
    settings = "os", "compiler", "build_type", "arch"

    # Sources are located in the same place as this recipe, copy them to the recipe
    exports_sources = "CMakeLists.txt", "src/*"

    def layout(self):
        cmake_layout(self)

    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()
        tc = CMakeToolchain(self)
        tc.generate()

    def build(self):
        rust_build_args = "--release" if self.settings.build_type == "Release" else "--"
        rust_source_dir = os.path.abspath(os.path.join(self.source_folder, "..", ".."))
        subprocess.run(
            ["cargo", "build", "-p", "diplomat-example", rust_build_args],
            check=True,
            cwd=rust_source_dir,
        )
        build_type = "release" if self.settings.build_type == "Release" else "debug"
        rust_output_dir = os.path.join(rust_source_dir, "target", build_type)
        cmake = CMake(self)
        cmake.configure(variables={"LIBS_DIR": rust_output_dir})
        if self.settings.os == "Windows":
            cmake.configure(
                variables={"LIBS": ";".join(glob.glob(f"{rust_output_dir}/*.dll.lib"))}
            )
        elif self.settings.os == "Linux":
            cmake.configure(
                variables={"LIBS": "dl;pthread;m;" + ";".join(glob.glob(f"{rust_output_dir}/*.a"))}
            )
        cmake.build()
        dst = os.path.join(self.build_folder, str(self.settings.build_type))
        if self.settings.os == "Windows":
            for file in glob.glob(f"{rust_output_dir}/*.dll"):
                shutil.copy(file, dst)

    def package(self):
        cmake = CMake(self)
        cmake.install()
