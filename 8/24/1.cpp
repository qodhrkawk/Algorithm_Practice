#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;




int main(){

    int T = 0;
    cin>> T;

    for(int testcase = 0 ; testcase<T; testcase++){
        
        vector<int> prev(1001,0);
        vector<int> times(1001,0);
        vector<vector<int> > nexts(1001);


        int N,K;

        cin>>N>>K;

        for(int i = 1; i <= N;i ++){
            cin>>times[i];
        }


        for(int i = 0; i < K ;i ++){
            int s, e;
            cin>>s>>e;

            prev[e]++;
            nexts[s].push_back(e);

        }

        queue<int> q;

        for(int i = 1; i<= N; i++){
            if(prev[i] == 0){
                q.push(i);
            }
        }

        int index;
        cin>>index;

        vector<int> res(1001,0);

        while(prev[index] != 0){
            int p = q.front();
            q.pop();

            for(auto i : nexts[p]){
                res[i] = max(res[i],res[p]+times[p]);
                prev[i]--;
                if(prev[i] == 0){
                    q.push(i);
                }

            }
        }

        cout<<res[index]+times[index]<<endl;






    }
    





    return 0;
}