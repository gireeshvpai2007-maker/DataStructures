#include<stdlib.h>
#include<stack>
#include<iostream>
#include<stdio.h>
using namespace std;
int evalprefix(char s[])
{
    stack<int> st;

    int len = 0;

    while (s[len] != '\0')
        len++;

    for (int i = len - 1; i >= 0; i--)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            int first = st.top();
            st.pop();

            int second = st.top();
            st.pop();

            switch (s[i])
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
int main()
{
    cout<<"Enter the string\n";
    char *c=(char *)calloc(30,sizeof(char));
    cin>>c;
    cout<<"The evaluation of prefix "<<evalprefix(c);
   return 0;
}