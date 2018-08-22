#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int i=0;
        for(int j=1; j<nums.size(); j++)
        {
            if(nums[i]!=nums[j])
            {
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};

// class Solution
// {
// public:
//     int removeDuplicates(vector<int>& nums)
//     {
//         if (nums.empty()) return 0;
//         vector<int>::iterator it1 = nums.begin();
//         vector<int>::iterator it2 = nums.begin()+1;
//         while(it2 != nums.end())
//         {
//             if(*it1 == *it2)
//             {
//                 nums.erase(it2);
//             }
//             else
//             {
//                 it1++;
//                 it2++;
//             }
//         }
//         return nums.size();
//     }
// };

int main(int argc, char* argv[])
{
    vector<int>nums = {1,1,2,3,4,4,4,5,6,7};
    Solution solution;
    int len = solution.removeDuplicates(nums);

    for(int i=0;i<len;i++)
    {
        cout<<nums[i];
    }
    return 0;
}
