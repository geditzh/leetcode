#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

vector<int> plusOne(vector<int>& digits)
{
    for(int i = digits.size()-1; i>=0; i--)
    {
        if(digits[i] == 9) digits[i] = 0;
        else
        {
            digits[i] += 1;
            return digits;
        }
    }
    if(digits.front() == 0) digits.insert(digits.begin(),1);
}

int main(int argc, char *argv[])
{
    vector<int>a = {5,6,2,0,0,2,4,9},b;
    b = PulsOne(a);
    for(vector<int>::iterator it=b.begin(); it != b.end(); it++)
    {
        cout<<*it;
    }
}
