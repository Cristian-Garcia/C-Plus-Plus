/** Name:     Cristian Garcia
    Project:  #1
    Due:      10/15/2015
    Course:   CS256.01

    Description:
              The purpose of this program is to evaluate a postfix
              expression provided by the user and to evaluate it. 
              I used the stack data structure and a lot of logic blocks
              to accomplish this task.
*/

// Sample expression: 4 5 * 6 + 2 * 1 – 6 / 4 2 + 3 * *

//necessary packages
#include <iostream>
#include <string>
#include <stack>

using namespace std;

//setting functions for program scope
int evaluate(string str);
int operate(int x, int y, char opr);
bool isOperator(char ch);
bool isNumber(char num);

int main() {
    
    string s;
    
    cout << "Enter an expression: ";
    getline(cin,s);
    
    int total = evaluate(s);
    cout << "Result: " << total << endl;

    cout << "Press any key to exit" << endl;
    char key = 0; cin >> key;

    return 0;

}

//postfix expression is processed and broken down char by char
int evaluate(string str) {

    //create stack 
    stack<int> stk;

    for(int i = 0; i < str.length(); i++){

        //ignore spaces
        if(str[i] == ' ')
            continue;
        //if operator found, pop two numbers from stack 
        else if(isOperator(str[i])){
            int y = stk.top(); stk.pop();
            int x = stk.top(); stk.pop();

            int total = operate(x, y, str[i]);

            stk.push(total);
        }
        //if number is found, push numbers into stack
        else if(isNumber(str[i])){
            int opd = 0;
            //for double-digit numbers
            while(i < str.length() && isNumber(str[i])){
                opd = (opd*10) + (str[i] - '0');
                i++;
            }
            i--;
            stk.push(opd);
        }
    }

    //return final result
    return stk.top();
}

//check if char is operator
bool isOperator(char ch) {
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
        return true;
    else
        return false;
}

//check if char is number
bool isNumber(char num){
    if(num >= '0' && num <= '9')
        return true;
    else
        return false;
}

//perform the math
int operate(int x, int y, char opr){
    
    if(opr == '+')
        return x + y;
    else if(opr == '-')
        return x - y;
    else if(opr == '*')
        return x * y;
    else if(opr == '/')
        return x / y;
    else
        return 0;

}

