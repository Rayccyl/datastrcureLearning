#include <iostream>
#include <stack>
#include <map>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    string in;
    cin >> in;
    char cend;
    in += '$';
    double num = 0;
    char opToIn;
    stack<double> STACKnum;
    stack<char> STACKops;
    STACKops.push('$');
    stringstream ss(in);
    map<char, int> priority{
        {'+', 1},
        {'-', 1},
        {'*', 2},
        {'/', 2},
        {')', 0},
        {'$', -1}};
    double num1, num2 = 0;
    bool skipOpIn = false;
    do
    {
        if (isdigit(ss.peek()))
        {
            ss >> num;
            STACKnum.push(num);
        }
        // 3+3*3*3*5*8-3/6
        else
        {
            if ((!skipOpIn || ss.peek() == '$') && opToIn != '$')
                ss >> opToIn;
            if (priority[opToIn] > priority[STACKops.top()] || opToIn == '(')
            {
                STACKops.push(opToIn);
                skipOpIn = false;
            }
            else
            {
            A:
                skipOpIn = true;
                if (opToIn == '$' && STACKops.top() == '$')
                {
                    STACKops.pop();
                    ss >> cend;
                    break;
                }
                if (opToIn == ')' && STACKops.top() == '(')
                {
                    STACKops.pop();
                    skipOpIn = false;
                    continue;
                }
                num1 = STACKnum.top();
                STACKnum.pop();
                num2 = STACKnum.top();
                STACKnum.pop();
                switch (STACKops.top())
                {
                case '+':
                    STACKnum.push(num2 + num1);
                    STACKops.pop();
                    break;
                case '-':
                    STACKnum.push(num2 - num1);
                    STACKops.pop();
                    break;
                case '*':
                    STACKnum.push(num2 * num1);
                    STACKops.pop();
                    break;
                case '/':
                if(num1==0) {
                    cout<<"error";
                    return 1;
                }
                    STACKnum.push(num2 / num1);
                    STACKops.pop();
                    break;
                case '(':
                    if (STACKops.empty() || STACKops.top() == ')')
                        STACKops.pop();
                    else
                        return 1;
                }
                if (priority[opToIn] <= priority[STACKops.top()])
                    goto A;
                else
                    STACKops.push(opToIn);
                skipOpIn = false;
            }
        }
    } while (!ss.eof());

    cout << STACKnum.top();
    return 0;
}