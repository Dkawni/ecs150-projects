#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "wzip: file1 [file2 ...]" << std::endl;
        return 1;
    }

    int count = 0;
    char prev = 0;
    char ch;

    for (int i = 1; i < argc; i++) {
        std::ifstream file(argv[i], std::ios::binary);

        if (!file.is_open()) {
            std::cout << "wzip: cannot open file" << std::endl;
            return 1;
        }

        while (file.read(&ch, 1)) {
            if (count > 0 && ch == prev) {
                count++;
            } else {
                if (count > 0) {
                    std::cout.write((char*)&count, 4);
                    std::cout.write(&prev, 1);
                }
                prev = ch;
                count = 1;
            }
        }
    }

    // write the final run
    if (count > 0) {
        std::cout.write((char*)&count, 4);
        std::cout.write(&prev, 1);
    }

    return 0;
}