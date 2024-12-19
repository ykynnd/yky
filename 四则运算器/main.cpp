#include <iostream>
#include <stack>
#include <cctype>
#include <string>
#include <sstream>
#include <cmath>
#include "expression_evaluator.h"

int main() {
    std::string expression;
    std::cout << "Enter an expression: ";
    std::getline(std::cin, expression);

    std::pair<double,bool>result = evaluate(expression);
    if (result.second) {
        std::cout << "Result: " << result.first << std::endl;
    } else {
        std::cout << "ILLEGAL" << std::endl;
    }

    return 0;
}