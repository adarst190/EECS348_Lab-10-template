#include <iostream>
#include <fstream>
#include <iomanip>
#include "calculator.hpp"

double addDouble(double result){        //Function to add -123.456 to the result of the parse_number function
    return result + (-123.456);
}

void readFile(std::string filename){        //Function to read the file and parse the numbers
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
            std::cout << "Invalid number: " << line << "\n" << std::endl;
        } else {
            std::cout << "Valid number: " << result << std::endl;
            std::cout << "Result of adding -123.456: " << addDouble(result) << "\n" << std::endl; // Call the addDouble function to add -123.456
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
