#include <iostream>


using namespace std;

string s;

int dp[26] = {-1,};



int main() {

    cin>>s;

    for(int i = 0; i< 26;i++){
        dp[i] = -1;
    }

    for(int i = 0; i < s.length(); i++){
        if(dp[s[i]-97] == -1){
            dp[s[i]-97] = i;
        }


    }

    for(int i = 0; i< 26;i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;




	return 0;
}