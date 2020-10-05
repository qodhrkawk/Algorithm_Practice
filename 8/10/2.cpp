#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    vector<vector<int>> networks(computers.size(),vector<int> (0,0));
    vector<int> root(n,-1);

    for(int i = 0; i < computers.size(); i++){
    
        for(int j = 0 ; j < computers[i].size(); j++){
            if(i==j){
                networks[i].push_back(i);
                root[i] = i;
                break;
            }
            if(computers[i][j] == 1){
                if(root[j] == -1){
                    networks[j].push_back(i);
                    root[i] = j;
                }
                else{
                    networks[root[j]].push_back(i);
                    root[i] = root[j];
                }

                break;
                
            } 
        }



    }

    for(int i = 0 ; i <networks.size(); i++){
        if(networks[i].size() > 0)
            answer++;
    }




    return answer;
}

