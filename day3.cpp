#include <iostream>
#include <fstream>
#include <string>
#include <vector>


int main() {
    std::ifstream file;
    std::string line;
    std::string gamma = "000000000000";
    std::string epsilon = "000000000000";
    std::vector<int> values(gamma.length(), 0);
    int g;
    int e;
    
    file.open("day-3-input.txt");
    while ( file >> line) {
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == '1')
                values[i] += 1;
            else
                values[i] -= 1;
             }
        }
        for (int i = 0; i < gamma.length(); i++) {
            if (values[i] > 0)
                gamma[i] = '1';
            else 
                epsilon[i] = '1';
        }   

        g = std::stoi(gamma,nullptr,2);
        e = std::stoi(epsilon,nullptr,2);
        std::cout << g * e; //1071734 is answer
}
