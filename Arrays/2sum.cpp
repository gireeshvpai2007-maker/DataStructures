#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution{
    public : vector<vector<int>> twoSum(vector<int>& nums, int target)
    {   vector<vector<int>>ans;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            int first=nums[i];
            int second=target-first;
            if(mp.find(second)!=mp.end())
            {
                ans.push_back({mp[second], i});
            }
            mp[first]=i;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int>nums={2,7,11,15,-2,3,6};
    int target=9;
    vector<vector<int>>ans=s.twoSum(nums,target);
    cout<<"The indices of the two numbers that add up to the target are : ";
    for(int i=0;i<ans.size();i++)
    {
        cout<<"["<<ans[i][0]<<","<<ans[i][1]<<"] ";
    }
    cout<<endl;
}