#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution
{   
    public:
    vector<vector<int>> Sum(vector<int>&v,int target)
    {vector<vector<int>>ans;
        sort(v.begin(),v.end());
        for(int i=0;i<v.size()-3;i++)
        {
            if(i>0&&v[i]==v[i-1])
                continue;
                for(int j=1;j<v.size()-2;j++)
                {
                    if(j>1&&v[j]==v[j-1])
                       continue;
                    int left=j+1;
                    int right=v.size()-1;
                    while(left<right)
                    {
                        int sum=v[i]+v[j]+v[left]+v[right];
                        if(sum==target)
                        {
                            ans.push_back({v[i],v[j],v[left],v[right]});
                            left++;
                            right--;
                             while(left<right && v[left]==v[left-1])
                                 left++;
                             while(left<right && v[right]==v[right+1])
                                 right--;
                            
                        }
                        else if(sum<target)
                        {
                            left++;
                        }
                        else
                           right--;
                        
                    }   
                }
        }
        return ans;

    }

};
int main()
{
    Solution S;
    vector<int>v={1,2,-3,4,-5,6,7,-8,9,10};
    int target=16;
    vector<vector<int>>ans=S.Sum(v,target);
    cout<<"Output :";
    cout<<"[";
    for(int i=0;i<ans.size();i++)
    {   cout<<"{";
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j];
            if(j==ans[i].size()-1)
            {
                cout<<"}";
            }
            else{
                cout<<" ,";
            }

        }
    }
return 0;
}