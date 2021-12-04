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
    std::vector<std::string> inputs;
    std::vector<std::string> oxygenRating;
    std::vector<std::string> c02Rating;

    
    int g;
    int e;
    
    file.open("day-3-input.txt");
    while ( file >> line) {
        inputs.push_back(line);
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == '1')
                values[i] += 1;
            else
                values[i] -= 1;
             }
        }
        oxygenRating = inputs;
        c02Rating = inputs;

        //oxygen search
        while (oxygenRating.size() != 1) {
            for (int i = oxygenRating.size() - 1; i >= 0; i--) {
                for (int j = 0; j < oxygenRating[i].length(); j++) {
                    if ((values[j] > 0 && oxygenRating[i][j] != '1') || (values[j] < 0 && oxygenRating[i][j] != '0') || (values[j] = 0 && oxygenRating[i][j] != '1')) {
                        oxygenRating.erase(oxygenRating.begin()+i);
                        i--;
                        if (oxygenRating.size() == 1) break;
                    }
                }
           }   
        }

        //c02 Search
        while (c02Rating.size() != 1) {
            for (int i = c02Rating.size() - 1; i >= 0; i--) {
                for (int j = 0; j < c02Rating[i].length(); j++) {
                    if ((values[j] > 0 && c02Rating[i][j] != '0') || (values[j] < 0 && c02Rating[i][j] != '1') || (values[j] = 0 && c02Rating[i][j] != '0')) {
                        c02Rating.erase(c02Rating.begin()+i);
                        i--;
                        if (c02Rating.size() == 1) break;
                    }
                }
           }   
        }
  
        std::cout << oxygenRating.size();
        std::cout << c02Rating.size();



}
