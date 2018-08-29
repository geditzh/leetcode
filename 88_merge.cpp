#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    vector<int> num(m+n,0);
    int i=0,j=0,k=0;
    while(i<m && j<n)
    {
        if(nums1[i] <= nums2[j])
            num[k++] = nums1[i++];
        else
            num[k++] = nums2[j++];
    }
    while(i<m) num[k++] = nums1[i++];
    while(j<n) num[k++] = nums2[j++];
    nums1.assign(num.begin(),num.end());
}

int main(int argc, char *argv[])
{
    vector<int>nums1 = {1,2,3,0,0,0};
    vector<int>nums2 = {2,5,6};
    int m=3,n=3;
    merge(nums1,3,nums2,3);
    for(int i=0;i<nums1.size();i++)
    {
        cout<<nums1[i];
    }
    return 0;
}
