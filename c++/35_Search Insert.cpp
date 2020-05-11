#include <iostream>
#include <vector>

int searchInsert(vector<int>& nums, int target)
{
    if(nums.empty()) return 0;
    else if(target > nums.back()) return nums.size();
    for(int i=0; i<nums.size(); i++)
    {
        if(nums[i] >= target)
            return i;
    }
}
