#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "wunzip: file1 [file2 ...]" << std::endl;
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        std::ifstream file(argv[i], std::ios::binary);
        int count;
        char ch;

        if (!file.is_open()) {
            std::cout << "wunzip: cannot open file" << std::endl;
            return 1;
        }

        // each record is: 4-byte count, then 1-byte character
        while (file.read((char*)&count, 4)) {
            if (!file.read(&ch, 1)) {
                std::cerr << "Corrupt input: count without a character." << std::endl;
                return 1;
            }
            std::cout << std::string(count, ch);
        }
    }

    return 0;
}