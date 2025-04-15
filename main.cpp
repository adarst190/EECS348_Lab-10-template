#include <iostream>
#include <fstream>
#include "calculator.hpp"


int main(int argc, char *argv[]) {
    std::string filename;
    std::cout << "Enter the name of the file to read: " << std::endl;
    std::cin >> filename;
    readFile(filename);

    // Run all unit tests in the file "tests.cpp"
    //::testing::InitGoogleTest(&argc, argv);
    //return RUN_ALL_TESTS();
}
