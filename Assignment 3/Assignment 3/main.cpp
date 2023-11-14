#include "Stack.cpp"
#include "Infix_To_Postfix.h"
#include <string>
#include <iostream>
using namespace std;

const string OPEN = "([{";
const string CLOSE = ")]}";

bool is_open(char ch) {
    return OPEN.find(ch) != string::npos;
}

bool is_closed(char ch) {
    return CLOSE.find(ch) != string::npos;
}

bool is_balanced(const string& expression) {
    Stack<char> ops;                        // a stack for open bracket w/ out matches
    bool balanced = true;
    string::const_iterator iter = expression.begin();

    while (balanced && (iter != expression.end())) {
        char next_ch = *iter;
        if (is_open(next_ch)) {             // check if open bracket
            ops.push(next_ch);              // push to top of stack
        }
        else if (is_closed(next_ch)) {      // check if closed bracket
            if (ops.empty()) {              // check if stack is empty
                balanced = false;
            }
            else {
                char top_ch = ops.top();
                ops.pop();
                balanced = OPEN.find(top_ch) == CLOSE.find(next_ch);  // check if open and close brackets are balanced
            }
        }
        ++iter;
    }
    return balanced && ops.empty();
}

int main()
{
    Infix_To_Postfix in_to_post;            // makes object of class Infix_To_Postfix

    cout << "Enter an expression: "; 
    string expression;

    while (getline(cin, expression) && (expression != "")) {    // get user input, if user enters empty string, terminate 
        cout << "\nInfix Expression: " << expression;
        if (is_balanced(expression)) {                          // test user input for balanced
            try {
                string result = in_to_post.convert(expression);      // if balanced, convert to postfix expression
                cout << "\nPostfix Expression: " << result << endl;
            }
            catch (Syntax_error& ex) {
                cout << "\nSyntax Error: " << ex.what() << endl;
            }
        }
        else {                                                      // if not balanced, display message
            cout << " is not balanced.\n";
        }
        cout << "\nEnter another expression: ";                     // ask for another expression from user
    }
    return 0;
}

