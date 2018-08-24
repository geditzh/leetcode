#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// int maxSubArray(vector<int>& nums)
// {
//     if(nums.empty()) return 0;
//     int sum;
//     int target = nums.front();
//     for(int i=0; i<nums.size(); i++)
//     {
//         sum = 0;
//         for(int j=i; j<nums.size(); j++)
//         {
//             sum += nums[j];
//             if(sum >= target)
//                 target = sum;
//         }
//     }
//     return target;
// }

int maxSubArray(vector<int>& nums)
{
    int result = 0;
    int sum = 0;
    for(int i=0; i<nums.size(); i++)
    {
        sum = max(sum+nums[i], nums[i]);
        result = max(result, sum);
    }
    return result;
}
int main(int argc, char* argv[])
{
    vector<int> x = {-2,1,-3,4,-1,2,1,-5,4};
    int a = maxSubArray(x);
    cout<<a;
}
