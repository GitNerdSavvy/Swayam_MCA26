#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
       int arr[n];
       for(int i=0;i<n;i++){
       	cin>>arr[i];
       }
       // k_beauty(arr,n);
       set<int>ans;
       for(int i=0;i<n;i++){
       	ans.insert(arr[i]);
       	
       }
       cout<<ans.size()<<endl;
    }
    return 0;
}
