#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>

using namespace std;

int dfs(int r,int c,vector<vector<int> > arr ){
    int ans = 0;


    if(r == arr.size()-1 && c == arr[0].size()-1){
        return 1;
    }

    if(r<arr.size()-1 && c == arr[0].size()-1){
        if(arr[r][c] > arr[r+1][c]){
            ans += dfs(r+1,c,arr);
        }
        else{
            return 0;
        }
    }
    
    else if(c<arr[0].size()-1 && r == arr.size()-1){
        if(arr[r][c] > arr[r][c+1]){
            ans += dfs(r,c+1,arr);
        }
        else{
            return 0;
        }

    }

    else if(r<arr.size()-1 && c<arr[0].size()-1){
        if(arr[r][c] > arr[r+1][c]){
            ans += dfs(r+1,c,arr);
        }

        if(arr[r][c] > arr[r][c+1]){
            ans += dfs(r,c+1,arr);
        }

        else if(arr[r][c] <= arr[r+1][c]){
            return 0;
        }

    }    



}




int main(){
    
    int m,n;
    long long ans = 0;


    cin>>m>>n;

    vector<vector<int> > arr(m,vector<int> (n,0));
    vector<vector<int> > way(m,vector<int> (n,0));


    for(int i = 0; i < m; i++){
        for(int j = 0 ;j <n;j++){
            cin>>arr[i][j];
        }
    }

    way[0][0] = 1;

    for(int i = 0 ; i< m; i++){
        for(int j = 0; j<n; j++){

            if(j!=0){
                if(arr[i][j]<arr[i][j-1]){
                    way[i][j] += way[i][j-1];
                }

            }
            
            if(i!=0){
                if(arr[i][j]<arr[i-1][j]){
                    way[i][j] += way[i-1][j];
                }

            }


        }


    }

   
    for(int i = 0; i < m; i++){
        for(int j = 0; j<n; j++){
            cout<<way[i][j]<<" ";

        }
        cout<<endl;

    }
    

    cout<<dfs(0,0,arr)<<endl;;







}