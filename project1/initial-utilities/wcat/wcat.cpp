#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        std::ifstream file(argv[i]);
        std::string str;
        char tmp;

        if (!file.is_open()) {
            std::cout << "wcat: cannot open file" << std::endl;
            return 1;
        }

        while (file.read(&tmp, 1 * sizeof(char))) {
            str += tmp;
        }

        std::cout << str;
    }
    return 0;
}