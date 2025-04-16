#include <iostream>
#include <fstream>
#include "calculator.hpp"

void readFile(std::string filename){
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Error opening file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        double result = parse_number(line); // Call the parse_number function to parse the number
        bool is_invalid = (result == 0.0 && line != "0" && line != "0.0" && line != "+0" && line != "-0" && line != "+0.0" && line != "-0.0");
        if (is_invalid) {
            std::cout << "Invalid number: " << line << std::endl;
        } else {
            std::cout << "Valid number: " << result << std::endl;
        }
    }

    file.close();
}

int main(int argc, char *argv[]) {
    std::string filename;
    std::cout << "Enter the name of the file to read: " << std::endl;
    std::cin >> filename;
    readFile(filename);

    // Run all unit tests in the file "tests.cpp"
    //::testing::InitGoogleTest(&argc, argv);
    //return RUN_ALL_TESTS();
}
