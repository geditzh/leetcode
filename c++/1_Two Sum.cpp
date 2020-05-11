#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
{
       unordered_map<int, int>m;
        vector<int> res;
        for(int i = 0; i <nums.size(); i++)
        {
            m[nums[i]] = i;
            int t = target - nums[i];
            if(m.count(t) && m[t] != i)
            {
                res.push_back(m[t]);
                res.push_back(i);
                return res;
            }
        }

}
};


int main(int argc, char *argv[])
{
    vector<int> a  = {2,5,7,6},b;
    int target = 9;
    Solution solution;
    b = solution.twoSum(a,target);
    cout<<b[0]<<'\t'<<b[1]<<endl;
    return 0;
}
