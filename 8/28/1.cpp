#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>

using namespace std;

int n, m;


int fairCuts(int n, int m){
    int ans = 0;
    int gets;

    while(m>0){

        if(n>m){
            n = n - n/m*m;
        }
        if(n == m || n == 0){
            return ans;
        }

        for(int i = 1 ; i < m; i++){
            if(n*(i+1) >= m){
                ans += i*n;
            
                gets = n*i;
                m = m - gets;
                break;
            }
        }

    }

    return ans;
}



int main() {
	
    cin>>n>>m;

    int ans = 0;

    
    ans += fairCuts(n,m);
    

    cout<<ans<<endl;



	return 0;
}