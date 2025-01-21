import glob
import os
from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout, CMakeDeps


class rice02Recipe(ConanFile):
    name = "rice02"
    version = "1.0"
    package_type = "application"

    # Optional metadata
    license = "<Put the package license here>"
    author = "<Put your name here> <And your email here>"
    url = "<Package recipe repository url here, for issues about the package>"
    description = "<Description of rice02 package here>"
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
        rust_source_dir = os.path.abspath(os.path.join(self.source_folder, "..", "c"))
        rust_output_dir = os.path.join(rust_source_dir, "build", str(self.settings.build_type))
        self.output.info(rust_source_dir)
        cmake = CMake(self)
        cmake.configure(variables={"LIBS_DIR": rust_output_dir})
        if self.settings.os == "Windows":
            cmake.configure(
                variables={"LIBS": "ws2_32;userenv;ntdll;" + ";".join(glob.glob(f"{rust_output_dir}/*.lib"))}
            )
        elif self.settings.os == "Linux":
            cmake.configure(
                variables={"LIBS": "dl;pthread;m;" + ";".join(glob.glob(f"{rust_output_dir}/*.a"))}
            )
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    

    
