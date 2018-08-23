#include <iostream>
#include <vector>

using namespace std;

// class Solution
// {
// public:
//     int removeElement(vector<int>& nums, int val)
//     {
//         if (nums.empty()) return 0;
//         vector<int>::iterator it = nums.begin();
//         while(it != nums.end())
//         {
//             if(*it == val)
//             {
//                 nums.erase(it);
//             }
//             else it++;
//         }
//         return nums.size();
//     }
// };

class Solution
{
public:
    int removeElement(vector<int>& nums, int val)
    {
        if (nums.empty()) return 0;
        int index = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] != val)
                nums[index++] = nums[i];
        }
        return index+1;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    vector<int> nums = {7,4,4,5,6,3};
    int pro = solution.removeElement(nums,4);
    for(int a = 0; a<pro-1; a++)
    {
        cout<<nums[a];
    }
}
