#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

template<template<typename> class P = less>


struct compare_pair_second{
    template<class T1, class T2> bool operator()(const pair<T1,T2>&left, const pair<T1,T2> & right){
        return P<T2>()(left.second,right.second);
    }


};



int prim(vector<vector<pair<int,int> > > g,int start){

    vector<int> indices;
    int ans = 0;

    indices.push_back(start);

    

    while(indices.size()<g.size()){

        int v1 = -1;
        int v2 = -1;
        int min = 9999999999;
        for(int i = 0; i < indices.size(); i++){
            if(count(indices.begin(),indices.end(),g[indices[i]][0].first) > 0){
                    g[indices[i]].erase(g[indices[i]].begin());
                    continue;
                }
        
            if(g[indices[i]].size() >0){
                if(min>=g[indices[i]][0].second){
                    v1 = indices[i];
                    v2 = g[indices[i]][0].first;
                    min = g[indices[i]][0].second;
                }
            }
        }

        
        indices.push_back(v2);

        
        ans+=g[v1][0].second;
        g[v1].erase(g[v1].begin());
        for(auto it = g[v2].begin() ; it != g[v2].end(); ++it){
            if(it->first == v1){
                g[v2].erase(it);
                break;
            }
        }


    }

    


    return ans;
}  



int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    vector<map<int,int> > graph(n);
    vector<vector<pair<int,int> > > gVec;

    if(n==1)
        return 0;

    for(int i = 0 ;  i < costs.size(); i++){
        graph[costs[i][0]][costs[i][1]] = costs[i][2];
        graph[costs[i][1]][costs[i][0]] = costs[i][2];
    }    

    
    for(int i = 0; i <n;i++){
        vector<pair<int,int> > tmpVec;
        for(auto iter = graph[i].begin(); iter!= graph[i].end(); ++iter){
            tmpVec.emplace_back(make_pair(iter->first,iter->second));
        }
        
        sort(tmpVec.begin(),tmpVec.end(),compare_pair_second<less>());
        gVec.push_back(tmpVec);
    }

    answer = prim(gVec,0);



    return answer;
}