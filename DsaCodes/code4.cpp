#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
   string s;
   
   while(n--){
   cin>>s;
   
   for(int i=s.length();i>=0;i--){
   	cout<<s[i];
   	
   	
   }
   cout<<' '<<endl;
   }
    return 0;
}