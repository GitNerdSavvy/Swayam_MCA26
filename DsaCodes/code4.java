class lcm{
	public static void main(String args[]){
		int a=15,b=20,c=30;
		int res=c;
		int i=1;
		while(i!=0){
			if(res%a ==0 && res%b ==0 && res%c ==0 ){
				System.out.print(res);
				break;
			}
			res=res*i;
			i++;
		}
	}
}