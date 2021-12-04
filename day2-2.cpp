#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file;
    std::string instruction;
    int horizontal = 0;
    int depth = 0;
    int aim = 0;
    int num = 0;

    file.open("day-2-input.txt");
    while ( file >> instruction >> num) {
        if (instruction == "forward") {
            horizontal += num;
            depth += aim * num;
        }
        else if (instruction == "up") 
            aim -= num;
        else if (instruction == "down") 
            aim += num;
    }
    std::cout << depth * horizontal;
}