#ifndef INFIX_TO_POSTFIX_H_
#define INFIX_TO_POSTFIX_H_
#include <string>
#include <stdexcept>

class Infix_To_Postfix {
private:
	void process_operator(char op);    // function to process operators; @param operator
	bool is_operator(char ch) const {        // determines if character is an operator; @param character to be tested; returns true if character is operator
		return OPERATORS.find(ch) != std::string::npos;
	};
	int precedence(char op) const {           // determines precedence of operator; @param operator; returns precedence
		return PRECEDENCE[OPERATORS.find(op)];
	};
	static const std::string OPERATORS;     // fixed operators
	static const int PRECEDENCE[];          // fixed precedence for operators
	Stack<char> operator_stack;             // stack to hold operators
	std::string postfix;                    // string to hold postfix expression

public:
	std::string convert(const std::string& expression);  // @param infix string; returns postfix expression
};

class Syntax_error : public std::invalid_argument {     // class to throw syntax error message
public: 
	Syntax_error(std::string excpt) : std::invalid_argument(excpt) {}
};
#endif
