#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[51][51];

int n,m,k;
int res = 0;


void changeLine(int j){
    for(int i = 0; i < n;i++){
        dp[i][j] = (dp[i][j]+1)%2;
    }
    
}


int checkOns(){
    int res = 0;
    for(int r = 0; r<n; r++){
        bool on = true;
        for(int c = 0; c<m; c++){
            if(dp[r][c] == 0){
                on = false;
                break;
            }
        }

        if(on)
            res++;
    }

    return res;
}

void dfs(vector<int> tmp,int length){

    if(length == k){
        for(int i = 0; i < k; i++){
            changeLine(tmp[i]);
        }
        res = max(res,checkOns());
        for(int i = 0; i < k; i++){
            changeLine(tmp[i]);
        }
        return;
    }
    else{
        for(int i = 0; i < n;i++){
            vector<int> input = tmp;
            input.push_back(i);
            dfs(input,length+1);
        }
    }



}



int main() {


    

    cin>>n>>m;


    for(int i = 0;i < n; i++){
        string s;
        cin>>s;
        for(int j = 0; j < m;j++){
            dp[i][j] = s[j]-48;
        }
    }
    cin>>k;

    
    vector<int> tmp;

    dfs(tmp,0);

    cout<<res<<endl;


	return 0;
}