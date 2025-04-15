#include "calculator.hpp"
/*
Function will parse a double that is a string, and must check if
the double is valid without using std::stod or std::strtod.
*/

double parse_number(const std::string &expression){
    
}

void readFile(std::string filename){
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Error opening file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        parse_number(line);
    }

    file.close();
}