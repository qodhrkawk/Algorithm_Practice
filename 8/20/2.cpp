#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>

using namespace std;





int main(){
    int n; 

    cin>>n;



    vector<vector<int> > arr(n,vector<int> (3,0));


    vector<pair<int,int> > people(n);
    vector<int> ans(n,0);

    for(int i= 0; i <n;i ++){
        cin>>people[i].first>>people[i].second;
    }

    
    for(int i = 0; i <n;i++){
        for(int j = 0; j<n; j++){
            if(people[i].first > people[j].first && people[i].second > people[j].second){
                ans[j]++;
            }

        }


    }


    for(int i = 0; i < n; i++){
        cout<<ans[i]+1<<" ";

    }
    cout<<endl;





}