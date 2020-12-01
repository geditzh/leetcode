#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main(int argc, char *argv[])
{
    cout << "type\t\t" << "size\t\t" << endl;
    cout << "char max\t\t";
    int a = (numeric_limits<char>::max)();
    cout << a << endl;
    cout << "long min\t\t";
    cout << numeric_limits<long>::max() << endl;
    return 0;
}