#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public: void maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return;
        int minPrice = prices[0];
        int maxProfit = 0;
        
        for(int i = 1; i < n; i++) {
                maxProfit = max(maxProfit, prices[i] - minPrice);
                minPrice = min(minPrice, prices[i]);   
        }
        cout<<"Stock bought at: "<<minPrice<<endl;
        cout<<"Stock sold at: "<<minPrice + maxProfit<<endl;
        cout << "Maximum Profit: " << maxProfit << endl;
    }
};
int main() {
    Solution solution;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    solution.maxProfit(prices);
    return 0;
}