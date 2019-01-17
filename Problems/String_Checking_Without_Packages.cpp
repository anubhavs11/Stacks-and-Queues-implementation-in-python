#include<iostream>
using namespace std;

bool stringCheck(char *s){
	
	char str[sizeof(s)];
	int count=0;
	for (int i = 0; s[i]!='\0'; ++i){
		count++;
	}
	for (int i = 0; i < count; ++i)	{
		str[i] = s[count-i-1];
	}

	bool flag = true;
	for (int i = 0; i<count-1; ++i){
		if(str[i+1]-str[i]!=s[i+1]-s[i]){
			flag = false;
		}	
	}
	return flag;
}

int main(){

	char s[] = "abba";
	cout<<stringCheck(s);
}	