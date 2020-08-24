#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;




int main(){

    int T = 0;
    cin>> T;

    for(int testcase = 0 ; testcase<T; testcase++){
        int N,K;
        cin>>N>>K;


        vector<int> times(N+1,0);
        vector<int> costs(N+1,0);

        for(int i = 1; i<= N; i++){
            int tmp;
            cin>>tmp;
            times[i] =costs[i] =tmp;
        }


        for(int i = 0; i < K; i++){
            int s,e;
            cin>>s>>e;
            costs[e] = max(costs[s]+times[e] , costs[e]);

        }


        int res = 0;
    
        cin>>res;

        cout<<costs[res]<<endl;


    }
    





    return 0;
}