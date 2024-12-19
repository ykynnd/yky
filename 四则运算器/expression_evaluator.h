#include <iostream>
#include <stack>
#include <cctype>
#include <string>
#include <sstream>
#include <cmath>
bool prio(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool higherPrio(char op1, char op2) {
    return prio(op1) > prio(op2);
}

std::pair<double, bool> evaluate(const std::string& expression) {
    std::stack<double> values;
    std::stack<char> ops;
    std::istringstream iss(expression);
	char c;
	std::string token;
	
	while (iss >> std::ws >> c) {
		if (c == 0) break;
        if (std::isdigit(c) || c == '.') {
            double val = 0;
            iss.putback(c);
            double temp;
            if (!(iss >> temp)) {
			return {0, false};
			}
            values.push(temp);
        } else if (c == '(') {
            ops.push(c);
        } else if (c == ')') {
            while (!ops.empty() && ops.top() != '(') {
                double val2 = values.top(); values.pop();
                double val1 = values.top(); values.pop();
                char op = ops.top(); 
				ops.pop();

                if (op == '+') values.push(val1 + val2);
                else if (op == '-') values.push(val1 - val2);
                else if (op == '*') values.push(val1 * val2);
                else if (op == '/') {
                    if (val2 == 0) return {0, false};
                    values.push(val1 / val2);
                }
            }
            if (!ops.empty() && ops.top() != '(') return {0, false};
            ops.pop();
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!ops.empty() && higherPrio(ops.top(), c)) {
                double val2 = values.top(); values.pop();
                double val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();

                if (op == '+') values.push(val1 + val2);
                else if (op == '-') values.push(val1 - val2);
                else if (op == '*') values.push(val1 * val2);
                else if (op == '/') {
                    if (val2 == 0) return {0, false};
                    values.push(val1 / val2);
                }
            }
            ops.push(c);
        }
    }
	if (ops.top() == '(' || ops.top() == ')') return {0, false};
    while (!ops.empty()) {
        double val2 = values.top(); 
		values.pop();
        double val1 = values.top(); 
		values.pop();
        char op = ops.top(); ops.pop();

        if (op == '+') values.push(val1 + val2);
        else if (op == '-') values.push(val1 - val2);
        else if (op == '*') values.push(val1 * val2);
        else if (op == '/') {
            if (val2 == 0) return {0, false};
            values.push(val1 / val2);
        }
    }

    if (values.size() != 1) return {0, false};
    return {values.top(), true};
}


