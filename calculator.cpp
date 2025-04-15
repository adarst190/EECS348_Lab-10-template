#include "calculator.hpp"
/*
Function will parse a double that is a string, and must check if
the double is valid without using std::stod or std::strtod.
*/

double parse_number(const std::string &expression){
    int i = 0;     //variable to count through digits of the string
    bool isNegative = false; //variable to check if the number is negative
    double result = 0.0; //variable to store the result of the number
    bool has_digits = false; //variable to check if the number has digits
    bool has_decimal = false; //variable to check if the number has a decimal point

    if(expression[i] == '-' || expression[i] == '+'){
        isNegative = (expression[i] == '-'); //check if the number is negative
        i++; //increment the index to check the next character
        if(i == expression.length()){
            return 0.0; //if the string is only a sign, return 0.0
        }
    }

    while(i < expression.length() && isdigit(expression[i])){
        result = result * 10 + (expression[i] - '0'); //convert the character to a digit and add it to the result
        has_digits = true; //set has_digits to true
        i++; //increment the index to check the next character
    }

    if(i < expression.length() && expression[i] == '.'){
        has_decimal = true; //set has_decimal to true
        i++; //increment the index to check the next character
    
        double fraction = 0.0; //variable to store the fraction part of the number
        double divisor = 10.0; //variable to store the divisor for the fraction part
        while(i < expression.length() && isdigit(expression[i])){
            fraction += (expression[i] - '0') / divisor; //convert the character to a digit and add it to the fraction
            divisor *= 10.0; //increment the divisor for the next digit
            i++; //increment the index to check the next character
        }

        result += fraction; //add the fraction to the result
    }

    if (i != expression.length()) {
        return 0.0; //if there are any invalid characters, return 0.0
    }
    if(isNegative){
        result = -result; //if the number is negative, make the result negative
    }
    return result; //return the result
}
