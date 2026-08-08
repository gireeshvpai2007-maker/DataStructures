#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;
class  Solution{
    public :bool isvalid(string s)
    {
        stack<char>st;
        for(int i=0;i<s.size();i++)
        {
           if(s[i]=='('||s[i]=='{'||s[i]=='[')
           {
               st.push(s[i]);
           }
           else
           {
               if(st.empty())
               {
                   return false;
               }
               char top=st.top();
               if((top=='(' && s[i]==')')||(top=='{' && s[i]=='}')||(top=='[' && s[i]==']'))
               {
                   st.pop();
               }
               else
               {
                   return false;
               }
           }
        }
        return st.empty();
    }
};
int main()
{
    Solution s;
    string str="()[]{}";
    if(s.isvalid(str))
    {
        cout<<"The given string is valid"<<endl;
    }
    else
    {
        cout<<"The given string is not valid"<<endl;
    }
}