#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int v,e;

vector<pair<int,pair<int,int> > > g;

int parent[10001];

int Find(int x){

    if(parent[x] == x){
        return x;
    }

    return parent[x] = Find(parent[x]);


}

void Union(int x, int y){

    x = Find(x);
    y = Find(y);

    if(x!=y)
        parent[y] = x;



}

bool sameParent(int x, int y){
    return Find(x) == Find(y);
}







int main() {
	
    cin>>v>>e;
    int answer = 0;

    for(int i = 0; i < e; i++){
        int start,end,cost;

        cin>>start>>end>>cost;

        g.push_back(make_pair(cost,make_pair(start,end)));
        

    }

    
    sort(g.begin(),g.end());

    for(int i = 1; i <= v; i++){
        parent[i] = i;
    }

    for(int i = 0; i<e ;i++){

        if(!sameParent(g[i].second.first,g[i].second.second)){
            answer += g[i].first;
            Union(g[i].second.first,g[i].second.second);

        }


    }

    cout<<answer<<endl;





	return 0;
}