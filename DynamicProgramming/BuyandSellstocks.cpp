#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void maxProfit(const vector<int>& prices) {
        if (prices.empty()) {
            cout << "No stock prices available." << endl;
            return;
        }

        int minPrice = prices[0];
        int buyPrice = prices[0];
        int sellPrice = prices[0];
        int maximumProfit = 0;

        for (int i = 1; i < static_cast<int>(prices.size()); ++i) {
            int profit = prices[i] - minPrice;
            if (profit > maximumProfit) {
                maximumProfit = profit;
                buyPrice = minPrice;
                sellPrice = prices[i];
            }
            minPrice = min(minPrice, prices[i]);
        }

        cout << "Stock bought at: " << buyPrice << endl;
        cout << "Stock sold at: " << sellPrice << endl;
        cout << "Maximum Profit: " << maximumProfit << endl;
    }
};

int main() {
    Solution solution;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    solution.maxProfit(prices);
    return 0;
}