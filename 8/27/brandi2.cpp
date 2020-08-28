#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>

using namespace std;

int T
long long int n,m;

int main() {
	
    cin>>T;
    for(int testcase = 0 ; testcase < T; testcase++){
        cin>>n>>m;
        // n : 시즌한정 m : 일반  , 시즌한정 최소 5개 , 총 12개

        int ans = 0;

        int seasons = n/5;
        int seasonsRemain = n%5;

        int normal = m/7;
        int normalRemain = m%7;

        if(seasons <= normal){
            ans = seasons;
        }
        else{
            int tmp = seasons - normal;
            int remain = tmp*5 + seasonsRemain + normalRemain;
            ans = normal + remain/12;
        }





        cout<<ans<<endl;

    }



	return 0;
}