#include "calculator.hpp"
/*
Function will parse a double that is a string, and must check if
the double is valid without using std::stod or std::strtod.
*/

double parse_number(const std::string &expression){
    int i = 0;     //variable to count through digits of the string
    bool isNegative = false; //variable to check if the number is negative
    double result = 0.0; //variable to store the result of the number
    double fraction = 0.0; //variable to store the fraction of the number
    double divisor = 10.0; //variable to divide the fraction by 10
    bool has_digits = false; //variable to check if the number has digits
    bool has_decimal = false; //variable to check if the number has a decimal point

    if(expression[i] == '-' || expression[i] == '+'){
        isNegative = (expression[i] == '-'); //check if the number is negative
        i++; //increment the index to check the next character
        if(i == expression.length()){
            return 0.0; //if the string is only a sign, return 0.0
        }
    }

    while(i < expression.length()){
        if(isdigit(expression[i])){
            has_digits = true; //set has_digits to true
            if(!has_decimal){
                result = result * 10.0 + (expression[i] - '0'); //if the number does not have a decimal point, multiply the result by 10
            }else{
                fraction += (expression[i] - '0') / divisor; //if the number has a decimal point, add the digit to the fraction
                divisor *= 10.0; //increment the divisor by 10
            }
        } else if(expression[i] == '.' && !has_decimal) {
            has_decimal = true; //set has_decimal to true
            if(i + 1 == expression.length()){
                return 0.0; //if the decimal point is the last character, return 0.0
            }
        } else {
            return 0.0; //if the character is not a digit or a decimal point, return 0.0
        }
        i++; //increment the index to check the next character
    }

    if (!has_digits) {
        return 0.0; //if the number does not have digits, return 0.0
    }
    
    result += fraction; //add the fraction to the result
    
    if(isNegative){
        result = -result; //if the number is negative, make the result negative
    }

    if(result == int(result)){
        return result+0.0; //if the result is an integer, return the result as a double
    }
    return result; //return the result
}
