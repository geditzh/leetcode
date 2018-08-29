#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int profit = 0;
        for(int i=1; i<prices.size(); i++)
        {
            if(prices[i] > prices[i-1])
            {
                profit += prices[i]-prices[i-1];
            }
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
