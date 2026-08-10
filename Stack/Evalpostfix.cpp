#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution
{
public:
    int postfix(vector<string>& s)
    {
        stack<int> st;

        for (int i = 0; i < s.size(); i++)
        {
            // Operand
            if (s[i] >= "0" && s[i] <= "9")
            {
                st.push(stoi(s[i]));
            }
            // Operator
            else
            {
                int second = st.top();
                st.pop();

                int first = st.top();
                st.pop();

                switch (s[i][0])
                {
                    case '+':
                        st.push(first + second);
                        break;

                    case '-':
                        st.push(first - second);
                        break;

                    case '*':
                        st.push(first * second);
                        break;

                    case '/':
                        st.push(first / second);
                        break;
                }
            }
        }

        return st.top();
    }
};

int main()
{
    Solution s;

    vector<string> v;

    cout << "Enter the postfix expression (space-separated): ";

    string input;
    getline(cin, input);

    stringstream ss(input);
    string token;

    while (ss >> token)
    {
        v.push_back(token);
    }

    cout << "The value of the postfix expression is: ";
    cout << s.postfix(v) << endl;

    return 0;
}