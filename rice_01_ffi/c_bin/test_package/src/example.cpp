#include "rice01.h"
#include <vector>
#include <string>

int main() {
    rice01();

    std::vector<std::string> vec;
    vec.push_back("test_package");

    rice01_print_vector(vec);
}
