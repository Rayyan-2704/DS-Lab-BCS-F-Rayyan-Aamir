/* Infix To Postfix Conversion using Stack */
#include <iostream>
#include <stack>
using namespace std;

class Solution
{
    int priority(char c)
    {
        if (c == '^')
            return 3;
        else if (c == '/' || c == '*')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        else
            return -1;
    }

public:
    string infixToPostfix(string s)
    {
        string ans = "";
        stack<char> st;
        for (char c : s)
        {
            if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
                ans += c;
            else if (c == '(')
                st.push(c);
            else if (c == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }
                if (!st.empty())
                    st.pop();
            }
            else
            {
                while (!st.empty() && st.top() != '(' &&
                       (priority(c) < priority(st.top()) ||
                        (priority(c) == priority(st.top()) && c != '^')))
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }

        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};

int main()
{
    Solution obj;
    string expr;

    cout << "Enter an infix expression: ";
    cin >> expr;

    string result = obj.infixToPostfix(expr);
    cout << "Postfix Expression: " << result << endl;

    // Optional: quick test cases
    // cout << "\nExample Tests:\n";
    // cout << "A+B*C  --> " << obj.infixToPostfix("A+B*C") << endl;
    // cout << "(A+B)*C  --> " << obj.infixToPostfix("(A+B)*C") << endl;
    // cout << "A^B^C  --> " << obj.infixToPostfix("A^B^C") << endl;
    // cout << "A+B*C^D  --> " << obj.infixToPostfix("A+B*C^D") << endl;
    // cout << "(A+B)*(C+D)  --> " << obj.infixToPostfix("(A+B)*(C+D)") << endl;

    return 0;
}