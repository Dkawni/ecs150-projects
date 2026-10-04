#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>

void search(std::istream &in, const std::string &pattern) {
    std::string line;
    while (std::getline(in, line)) {
        if (line.find(pattern) != std::string::npos) {
            printf("%s\n", line.c_str());
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("wgrep: searchterm [file ...]\n");
        return 1;
    }

    std::string pattern = argv[1];

    if (argc == 2) {
        search(std::cin, pattern);
        return 0;
    }

    for (int i = 2; i < argc; i++) {
        std::ifstream file(argv[i]);
        if (!file.is_open()) {
            printf("wgrep: cannot open file\n");
            return 1;
        }
        search(file, pattern);
    }
    return 0;
}