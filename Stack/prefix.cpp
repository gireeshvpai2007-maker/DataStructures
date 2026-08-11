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
                return 1;
            }
            else
            {
                return 0;
            }
        }
        return p1>p2?1:0;
     }
     char * rev(char c[])
     {
        int len=0;
        for(int i=0;c[i]!='\0';i++)
        {
             len++;
        }
      int l=0;
      int r=len-1;
      char temp;
      while(l<r)
      {
         temp=c[l];c[l]=c[r];c[r]=temp;
         l++;
         r--;

      }
      return c;

     }
        string infixtoprefix(char s[])
        {
            stack<char>st;
            char ans[30];int j=0;
            rev(s);
            for(int i=0;s[i]!='\0';i++)
            {
                if(s[i]=='(')
                 s[i]=')';
                else if(s[i]==')')
                  s[i]='(';
                
            }
            for(int i=0;s[i]!='\0';i++)
            {
                if(isoperand(s[i]))
                {
                    ans[j++]=s[i];
                }
                else if(s[i]=='(')
                {
                    st.push(s[i]);
                }
                else if(s[i]==')')
                {
                    while(!st.empty() && st.top()!='(')
                    {
                        ans[j++]=st.top();
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
                        ans[j++]=st.top();
                        st.pop();
                    }
                    st.push(s[i]);
                }
            }
            while(!st.empty())
            {
                ans[j++]=st.top();
                st.pop();
            }
             ans[j] = '\0';
            rev(ans);
           
            return ans;
        }
};
int main()
{
    Solution s;
    char str[30];
    cout<<"Enter the infix expression : ";
    cin>>str;
    string ans=s.infixtoprefix(str);
    cout<<"The postfix expression is : "<<ans<<endl;
}