#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool prime(int n , int c){
	if(n<=2)
		return n==2?true:false;
	else{
		if(n>=c*c){
			if(n%c==0)
				return false;
			else
				return prime(n,c+1);
		}
		else{
			return true;
		}
	}
}

int main(){
	cout<<prime(9,2);
}
