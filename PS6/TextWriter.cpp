// Copyright [2023] Hunter Hasenfus

#include <string>
#include <iostream>
#include <cstdlib>
#include "RandWriter.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " k L" << std::endl;
        return 1;
    }
    int k = atoi(argv[1]);
    int L = atoi(argv[2]);
    std::string text;
    std::string line;
    while (std::getline(std::cin, line)) {
        text += line;
    }
    RandWriter rw(text, k);

    //std::cout << rw << rw.generate(text.substr(0, k), L) << std::endl;
    return 0;
}
