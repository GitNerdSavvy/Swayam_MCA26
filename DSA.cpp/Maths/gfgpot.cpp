#include <bits/stdc++.h>
using namespace std;

int func(vector<int> &arr, int a, int b)
{
    int n = arr.size();
    int l = 0, sm = -1e8, mx = -1e8;
    for (int r = 0; r < n; r++)
    {
        sm += arr[r];
        int w = r - l + 1;
        if (w >= a && w <= b)
            mx = max(mx, sm);
        while (w > b)
        {
            sm -= arr[l];
            l++;
            mx = max(mx, sm);
        }
    }
    return mx;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int a, b;
    cin >> a >> b;
    cout << func(arr, a, b);
}