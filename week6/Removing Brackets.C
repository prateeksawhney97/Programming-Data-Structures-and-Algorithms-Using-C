// C++ program to simplify algebraic string
#include <bits/stdc++.h>
using namespace std;
 
// Function to simplify the string
char* simplify(string str)
{
    int len = str.length();
 
    // resultant string of max length equal
    // to length of input string
    char* res = new char(len);
    int index = 0, i = 0;
 
    // create empty stack
    stack<int> s;
    s.push(0);
 
    while (i < len) {
        if (str[i] == '+') {
 
            // If top is 1, flip the operator
            if (s.top() == 1)
                res[index++] = '-';
 
            // If top is 0, append the same operator
            if (s.top() == 0)
                res[index++] = '+';
 
        } else if (str[i] == '-') {
            if (s.top() == 1)
                res[index++] = '+';
            else if (s.top() == 0)
                res[index++] = '-';
        } else if (str[i] == '(' && i > 0) {
            if (str[i - 1] == '-') {
 
                // x is opposite to the top of stack
                int x = (s.top() == 1) ? 0 : 1;
                s.push(x);
            }
 
            // push value equal to top of the stack
            else if (str[i - 1] == '+')
                s.push(s.top());
        }
 
        // If closing parentheses pop the stack once
        else if (str[i] == ')')
            s.pop();
 
        // copy the character to the result
        else
            res[index++] = str[i];
        i++;
    }
    return res;
}
 
// Driver program
int main()
{
    string s1;
    getline(cin,s1);
    
    cout << simplify(s1);    
    return 0;
}
