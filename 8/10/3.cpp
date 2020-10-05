#include <string>
#include <vector>
#include <iostream>

using namespace std;


bool dfs(int start, vector<vector<int>>& computers){
   
    if(computers[start][start] == 0)
        return false;

    computers[start][start] = 0;
    for(int i = 0; i < computers.size(); i++ ){
        if(computers[start][i] == 1){
            dfs(i,computers);
        }



    }


    return true;

    




}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    

    for(int i = 0; i <n ; i++){

        if(computers[i][i] == 1 && dfs(i,computers)){
            answer++;
        }


    }



    return answer;
}


