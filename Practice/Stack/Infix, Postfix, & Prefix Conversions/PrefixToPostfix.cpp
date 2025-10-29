/* Prefix To Postfix Conversion using Stack */
#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    string Postfix(string s)
    {
        string ans = "";
        stack<string> st;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
                st.push(string(1, s[i]));
            else
            {
                string t1 = st.top();
                st.pop();
                string t2 = st.top();
                st.pop();

                string newString = t1 + t2 + string(1, s[i]);
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

    cout << "Enter an prefix expression: ";
    cin >> expr;

    string result = obj.Postfix(expr);
    cout << "Postfix Expression: " << result << endl;

    return 0;
}