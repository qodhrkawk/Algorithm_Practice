#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int dp(vector<int> coins,int k){
    vector<int> methods(k+1,0);

    for(int i = 0 ; i< coins.size(); i++){
        methods[coins[i]]++;
    }

    



}




int main(){
    int n, k;

    cin>>n>>k;

    vector<int> coins;
    for(int i = 0; i <n ;i ++){
        int tmp = 0;
        cin>>tmp;
        coins.push_back(tmp);
    }


    return 0;
}