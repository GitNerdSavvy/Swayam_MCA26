// wap to enter any number and print reverse of that number




#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
    int a,b;
   
    while(n--){
    	cin >> a;
      b=0;
    
    
    while(a){
    	
    	b=b*10+a%10;
    	a=a/10;
    }
    
    
    cout<<b<<endl;
  }  
    return 0;

}