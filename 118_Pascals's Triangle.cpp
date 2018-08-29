#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> res;
    if (numRows <= 0) return res;
    res.assign(numRows,vector<int>(1,1));
    for(int i=1; i<numRows; i++)
    {
        for(int j=1; j<i; j++)
        {
            res[i].push_back(res[i-1][j-1] + res[i-1][j]);
        }
        res[i].push_back(1);
    }
    return res;
}

int main(int argc, char *argv[])
{
    vector<vector<int>> a = generate(5);
    for(int i=0; i<a.size(); i++)
    {
        for(int j=0; j<a[i].size(); j++)
        {
            cout<<a[i][j];
        }
        cout<<endl;
    }
    return 0;
}
