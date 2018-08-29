#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums)
    {
        set<int> s;
        for(int i=0; i<nums.size(); i++)
        {
            s.insert(nums[i]);
            if(s.size() >3)
                s.erase(s.begin());
        }
        return s.size()==3 ? *s.begin() : *s.rbegin();
    }
};

int thirdMax(vector<int>& nums)
{
    int max = INT_MIN,middle = INT_MIN,min = INT_MIN;
    for(int i=0; i<nums.size(); i++)
    {
        if(nums[i]>max)
        {
            min = middle;
            middle = max;
            max = nums[i];
        }
        else if(nums[i]<max && nums[i]>middle)
        {
            min = middle;
            middle = nums[i];
        }
        else if(nums[i]<middle && nums[i]>min)
        {
            min = nums[i];
        }
    }
    return (min == INT_MIN || min == middle)? max : min;
}
