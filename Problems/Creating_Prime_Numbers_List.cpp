#include <cmath>
#include <vector>
using namespace std;

int main() {
	  int t;
	  cin>>t;
	  vector<int> p;
	  p.push_back(2);
    int n;
    n=1000000;// limit to check for prime numbers
    bool flag;
    for(int i=3;i<=n;i++){
        flag = true;
        for(int j=0;j<p.size();j++){ 
            if(i%p[j]==0){ 
                flag = false;
                break;
            }
            if(p[j]*p[j]>i){
                break;
            }
        }
        if(flag){
            p.push_back(i);
        }
    }      
	return 0;
}
