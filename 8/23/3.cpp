#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;




int main(){

    string s1 = "";
    string s2 = "";


    cin>>s1>>s2;



    vector<vector<int> > dp(s1.length()+1,vector<int> (s2.length()+1,0));


    for(int i = 1; i <= s2.length(); i++){
        char pivot = s2[i];

        for(int j = 1; j <= s1.length(); j++){
            
            if(s1[j] == pivot){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }


        }

    }

    cout<<dp[s1.length()][s2.length()]<<endl;





    return 0;
}