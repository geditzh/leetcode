#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> res;
        vector<int> temp(nums.size(),0);
        for(int i=0; i<nums.size(); i++)
        {
            temp[nums[i]-1] = -1;
        }
        for(int i=0;i<nums.size(); i++)
        {
            if((temp[i]+1) != 0)
                res.push_back(i+1);
        }
        return res;
    }
};
int main(int argc, char *argv[])
{
    vector<int> a = {4,3,2,7,8,2,3,1};
    Solution s;
    vector<int>b = s.findDisappearedNumbers(a);
    for(vector<int>::iterator it = b.begin(); it != b.end(); it++)
    {
        cout<< *it;
    }
}
