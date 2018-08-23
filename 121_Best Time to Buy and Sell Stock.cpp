#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        if(prices.size() <= 1) return 0;
        int low = prices[0];
        int profit = 0;
        for(int i=1; i<prices.size(); i++)
        {
            low = min(low, prices[i]);
            profit = max(profit, prices[i]-low);
        }
        return profit;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    vector<int> x = {7,4,4,5,6,3};
    int pro = solution.maxProfit(x);
    cout<<pro<<endl;
}
