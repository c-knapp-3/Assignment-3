#include "Stack.h"
#include "Infix_To_Postfix.h"
#include <cctype>
using std::string;

const string Infix_To_Postfix::OPERATORS = "+-*/%(){}[]";        // possible operators
const int Infix_To_Postfix::PRECEDENCE[] = { 1, 1, 2, 2, 2, -1, -1, -1, -1, -1, -1 }; // precedence for operators

string Infix_To_Postfix::convert(const std::string& expression) {
	postfix = "";
	while (!operator_stack.empty())
		operator_stack.pop();
	char next_token;

	for (int i = 0; i < expression.length(); i++) {  // goes through each character in infix expression
		next_token = expression[i];
		if (isalnum(next_token)) {                   // if char is number or alphabet it is added to postfix expression
			postfix += next_token;
			postfix += " ";
		}
		else if (is_operator(next_token)) {          // if char is an operator, function will process operation
			process_operator(next_token);
		}
		else if (next_token == ' ') {                // if char is a space, 
			postfix += "";                           // do not add anything
		}
		else {
			throw Syntax_error("Unexpected character encountered.");  // if char is not a number, alphabet or operator, throw syntax error
		}
	}

	while (!operator_stack.empty()) {              // iterate through the stack
		char op = operator_stack.top();
		operator_stack.pop();
		postfix += op;
		postfix += " ";
	}
	return postfix;                              // returns postfix expression
}

void Infix_To_Postfix::process_operator(char op) {
	if (operator_stack.empty() || (op == '(') || (op == '{') || (op == '[')) {  // if stack is empty or if open bracket, push onto stack
		operator_stack.push(op);
	}
	else {
		if (precedence(op) > precedence(operator_stack.top())) {  // if the operator's precedence is greater than that of the op on top of stack, push it to the the top of the stack
			operator_stack.push(op);
		}
		else {
			while (!operator_stack.empty() && operator_stack.top() != '(' && operator_stack.top() != '{' && operator_stack.top() != '[' // if stack is not empty and top is not an open bracket
				&& (precedence(op) <= precedence(operator_stack.top()))) {   // if precedence is less than the operator on the top of the stack's
				postfix += operator_stack.top();   // append operator on top of stack to postfix expression
				postfix += " ";
				operator_stack.pop();              // remove operator from stack
			}
			if (op == ')' || op == '}' || op == ']') {  // if current operator is a close bracket
				while (operator_stack.top() == '(' && operator_stack.top() == '{' && operator_stack.top() == '[') {  // pop and add to output operator from top of stack until a left side is reached
					postfix += operator_stack.top();
					postfix += " ";
					operator_stack.pop();
				}
				operator_stack.pop();
			}
			else {
				operator_stack.push(op);    // add to top of stack
			}
		}
	}
}