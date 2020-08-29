#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int m;
int INF = INT32_MAX;

vector<pair<int,int> > a[201];
int d[201];






int main() {


    cin>>n>>m;

    int s,e,w;
    for(int i = 0; i < m; i++){
        cin>>s>>e>>w;
        a[s-1].push_back(make_pair(e-1,w));

    }

    for(int i = 1; i <= n; i++){
        d[i] = INF;

    }

    d[0] = 0;
    bool cycle = false;

    for(int i = 0; i< n; i++){
        for(int j = 0; j < n; j++){

            for(auto& p : a[j]){
                int next = p.first;
                int distance = p.second;

                if(d[j] != INF && d[next] > d[j] + distance){
                    d[next] = d[j] + distance;

                    if(i == n-1){
                        cycle = true;
                    }

                }


            }



        }

    }

    if(cycle){
        cout<<"bug"<<endl;
    }
    else{
        if(d[n] == INF){
            cout<<"bug"<<endl;
        }
        else{
            cout<<d[n]<<endl;
        }

    }



 


	return 0;
}