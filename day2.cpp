#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file;
    std::string instruction;
    int horizontal = 0;
    int depth = 0;
    int num = 0;

    file.open("day-2-input.txt");
    while ( file >> instruction >> num) {
        if (instruction == "forward")
            horizontal += num;
        else if (instruction == "up") 
            depth -= num;
        else if (instruction == "down") 
            depth += num;
    }
    std::cout << depth * horizontal;
}