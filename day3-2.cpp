#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int getCount(std::vector<std::string> vec, int pos);

int main() {
    std::ifstream file;
    std::string line;
    std::vector<std::string> inputs;
    std::vector<std::string> oxygenRating;
    std::vector<std::string> c02Rating;
	int count;
	int oxygenDecimal;
	int co2Decimal;
    
    file.open("day-3-input.txt");
    while ( file >> line) {
        inputs.push_back(line);
        }
		
        oxygenRating = inputs;
        c02Rating = inputs;
	
        //oxygen search
			for (int j = 0; j < 12; j++)
             {
				 if (oxygenRating.size() == 1) break;
				 count = getCount(oxygenRating, j);
				
				 for (int i = oxygenRating.size() - 1; i >= 0; i--){
                    if ((count > 0 && oxygenRating[i][j] != '1') || (count < 0 && oxygenRating[i][j] != '0') || (count == 0 && oxygenRating[i][j] != '1')) {
						oxygenRating.erase(oxygenRating.begin()+i);
                    }
					
                }
				
           }   

       // c02 Search
	   for (int j = 0; j < 12; j++)
             {
				if (c02Rating.size() == 1) break;
				count = getCount(c02Rating, j);
				
               for (int i = c02Rating.size() - 1; i >= 0; i--) {
                    if ((count > 0 && c02Rating[i][j] != '0') || (count < 0 && c02Rating[i][j] != '1') || (count == 0 && c02Rating[i][j] != '0')) {
                        c02Rating.erase(c02Rating.begin()+i);
                    }
                }
           }   
      
		oxygenDecimal = std::stoi(oxygenRating[0],nullptr,2);
        co2Decimal = std::stoi(c02Rating[0],nullptr,2);
        std::cout << oxygenRating[0] << " * " <<  c02Rating[0] << " = " << oxygenDecimal * co2Decimal;
}

//utility function to find whether there are more zeros or ones in every position
int getCount(std::vector<std::string> vec, int pos) {
	int count = 0;
	for (int i = 0; i < vec.size(); i++) {
            if (vec[i][pos] == '1')
                count += 1;
            else
                count -= 1;
             }
	return count;
	
}

