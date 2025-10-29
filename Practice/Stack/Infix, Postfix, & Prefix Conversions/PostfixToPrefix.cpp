/* Postfix To Prefix Conversion using Stack */
#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    string Prefix(string s)
    {
        string ans = "";
        stack<string> st;
        for (char c : s)
        {
            if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
                st.push(string(1, c));
            else
            {
                string t1 = st.top();
                st.pop();
                string t2 = st.top();
                st.pop();

                string newString = string(1, c) + t2 + t1;
                st.push(newString);
            }
        }

        return st.top();
    }
};

int main()
{
    Solution obj;
    string expr;

    cout << "Enter an postfix expression: ";
    cin >> expr;

    string result = obj.Prefix(expr);
    cout << "Prefix Expression: " << result << endl;

    return 0;
}