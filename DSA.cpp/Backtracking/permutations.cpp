#include<bits/stdc++.h>
using namespace std;
void perma(string s,int i){
    if(i==s.size()-1){
        cout<<s<<"\n";
        return;
    }
    unordered_set<char> us;
    for(int j=i;j<s.size();j++){
        if(us.count(s[j])) continue;

        us.insert(s[j]);
        swap(s[i],s[j]);
        perma(s,i+1);
        swap(s[i],s[j]);
    }
}
int main(){
    string str;
    cin>>str;
    perma(str,0);
}