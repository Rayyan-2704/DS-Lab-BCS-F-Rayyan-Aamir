/* Infix to Prefix Conversion using Stack */
#include <iostream>
#include <stack>
#include <algorithm>
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

public:
    string infixToPrefix(string s)
    {
        reverse(s.begin(), s.end());

        for (char &c : s)
        {
            if (c == '(')
                c = ')';
            else if (c == ')')
                c = '(';
        }

        string ans = infixToPostfix(s);
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{
    Solution obj;
    string expr;

    cout << "Enter an infix expression: ";
    cin >> expr;

    string result = obj.infixToPrefix(expr);
    cout << "Prefix Expression: " << result << endl;

    return 0;
}