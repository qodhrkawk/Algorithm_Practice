#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>

using namespace std;



int main(){

    int N,M;

    cin>>N>>M;

    int kn;

    cin>>kn;

    vector<int> knows(kn,0);
    for(int i = 0 ; i< kn ;i++){
        cin>>knows[i];
    }

    int ans = 0;

    for(int i = 0; i < M; i++){
        int tmp;
        cin>>tmp;
        vector<int> participants;

        for(int j = 0; j < tmp; j++){
            

        }


    }


    cout<<ans<<endl;

}