#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximumProduct(vector<int> &nums)
{
    sort(nums.begin(),nums.end());
    int len = nums.size();
    int s = nums[len-1] * nums[len-2] * nums[len-3];
    s = max(s, nums[len-1] * nums[1] * nums[0]);
    return s;
}
int main(int argc, char *argv[])
{
    vector<int> x = {1,2,3,4};
    int a = maximumProduct(x);
    printf("%d",a);
}
