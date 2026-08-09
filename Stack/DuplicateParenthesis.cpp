#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
    bool hasDuplicate(string s)
    {
        stack<char> st;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ')')
            {
                st.push(s[i]);
            }
            else
            {
                int freq = 0;

                while (!st.empty() && st.top() != '(')
                {
                    freq++;
                    st.pop();
                }

                if (!st.empty())
                    st.pop();

                if (freq == 0)
                    return true;
            }
        }

        return false;
    }
};

int main()
{
    Solution S;

    string str ;
    cout << "Enter the string : ";
    cin >> str;

    bool a = S.hasDuplicate(str);

    if (a)
        cout << str << " has duplicate parenthesis";
    else
        cout << str << " doesn't have duplicate parenthesis";

    return 0;
}