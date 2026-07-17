#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threesum(vector<int>&nums,int target){
            vector<vector<int>> ans;
            int left,right;
            sort(nums.begin(),nums.end());
           for(int i=0;i<nums.size()-2;i++){
                if(i>0&&nums[i]==nums[i-1])
                    continue;
                    left=i+1;
                    right=nums.size()-1;
                    while(left<right)
                    {
                        long long sum=(long long)nums[i]+nums[left]+nums[right];
                        if(sum==target)
                        {
                            ans.push_back({nums[i],nums[left],nums[right]});
                            left++;
                            right--;
                            while(left<right&&nums[left]==nums[left+1]) left++;
                            while(left<right&&nums[right]==nums[right-1]) right--;  
                        }
                        else if(sum<target)
                            left++;
                        else
                            right--;
                    }
                  
           }
 return ans;
    }};
    int main(){
        Solution s;
        vector<int> nums={-1,0,1,2,-1,-4}; int target=0;
        vector<vector<int>> result = s.threesum(nums, target);
         for(int i=0;i<result.size();i++){
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j]<<" ";
            }
            cout<<endl;
        }
      return 0;
    }