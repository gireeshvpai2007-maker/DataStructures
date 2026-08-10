#include<iostream>
#include<stack>
#include<string>
using namespace std;
class Solution{
     public: int isoperand(char c)
     {
        if((c>='a' && c<='z')||(c>='A' && c<='Z')||(c>='0' && c<='9'))
        {
            return 1;
        }
        return 0;
     }
     int presedence(char c)
     {
        if( c=='^')
        {
            return 3;
        }
        else if(c=='*'||c=='/')
        {
            return 2;
        }
        else if(c=='+'||c=='-')
        {
            return 1;
        }
        else
        {
            return -1;
        }
     }
     int isoperator(char c)
     {
        if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
        {
            return 1;
        }
        return 0;
     }
     int hashigherprecedence(char c1,char c2)
     {
        int p1=presedence(c1);
        int p2=presedence(c2);
        if(p1==p2)
        {
            if(c1=='^')
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        return p1>p2?1:0;
     }
        string infixtopostfix(string s)
        {
            stack<char>st;
            string ans="";
            for(int i=0;i<s.size();i++)
            {
                if(isoperand(s[i]))
                {
                    ans+=s[i];
                }
                else if(s[i]=='(')
                {
                    st.push(s[i]);
                }
                else if(s[i]==')')
                {
                    while(!st.empty() && st.top()!='(')
                    {
                        ans+=st.top();
                        st.pop();
                    }
                    if(!st.empty())
                    {
                        st.pop();
                    }
                }
                else if(isoperator(s[i]))
                {
                    while(!st.empty() && isoperator(st.top()) && hashigherprecedence(st.top(),s[i]))
                    {
                        ans+=st.top();
                        st.pop();
                    }
                    st.push(s[i]);
                }
            }
            while(!st.empty())
            {
                ans+=st.top();
                st.pop();
            }
            return ans;
        }
};
int main()
{
    Solution s;
    string str;
    cout<<"Enter the infix expression : ";
    cin>>str;
    string ans=s.infixtopostfix(str);
    cout<<"The postfix expression is : "<<ans<<endl;
}