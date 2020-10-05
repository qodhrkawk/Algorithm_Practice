#include <string>
#include <vector>
#include <iostream>

using namespace std;





int solution(int m, int n, vector<vector<int> > puddles) {
    int answer = 0;




    int methods[101][101];

    for(int j = 1; j <= n; j++){
        for(int i = 1; i<= m; i++){
            methods[j][i] =1;

        }

    }


    for(int i = 0; i < puddles.size(); i++){
        methods[puddles[i][1]][puddles[i][0]] = 0; 

        if(puddles[i][0]==1){
            for(int j = puddles[i][1]; j<=n; j++){
                methods[j][1] = 0;

            }
        }
        if(puddles[i][1]==1){
            for(int j = puddles[i][0]; j<=m; j++){
                methods[1][j] = 0;

            }

        }

    }

    for(int i = 2; i<= m;i++){
        for(int j = 2; j<= n; j++){
            if(methods[j][i]!=0){
                methods[j][i] = (methods[j-1][i]+methods[j][i-1])%1000000007;

            }
            
        }

    }
    
    answer = methods[n][m];



    return answer;
}



