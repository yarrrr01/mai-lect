#include "Reformatting.h";

#include <iostream>

int main() {
    std::string fileName;
    std::cout << "Enter the path to the file: \n";
    std::cin >> fileName;

    Reformatting file(fileName);
    file.reformat();
    return 0;
}