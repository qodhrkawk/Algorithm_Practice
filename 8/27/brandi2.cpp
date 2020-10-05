#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>

using namespace std;

int T;
long long int n,m;

int main() {
	
    cin>>T;
    for(int testcase = 0 ; testcase < T; testcase++){
        cin>>n>>m;
        // n : 시즌한정 m : 일반  , 시즌한정 최소 5개 , 총 12개

        long long ans = 0;

        long long seasons = n/5;
        long long seasonsRemain = n%5;

        long long normal = m/7;
        long long normalRemain = m%7;

        if(seasons <= normal){
            ans = seasons;
        }
        else{
            long long tmp = seasons - normal;
            long long remain = tmp*5 + seasonsRemain + normalRemain;
            ans = normal + remain/12;
        }



        cout<<ans<<endl;

    }



	return 0;
}