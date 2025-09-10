#include <iostream>
using namespace std;

int main()
{

    int a, b;
    // cout<<"Enter Any two Num:";
    cin >> a >> b;
    if (a == b)
    {
        cout << "Both are Equal";
    }

    else if (a > b)
        cout << "a is greater";
    else if (a < b)
        cout << "b is greater";
    else
        cout << "Both are not Equal";
    return 0;
}