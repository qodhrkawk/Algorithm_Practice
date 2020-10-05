#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    vector<int> cleared(N+2,0);
    vector<int> visited(N+2,0);

    for(int i = 0; i < stages.size(); i++){
        visited[stages[i]]++;    
        for(int j = 1; j< stages[i]; j++){
            cleared[j]++;
            visited[j]++;
        }


    }

    vector<vector<double>> percent;


    for(int i = 1; i <= N; i++){
        vector<double> tmp;
        tmp.push_back(double(double(cleared[i])/double(visited[i])));
        tmp.push_back(i);
        percent.push_back(tmp);

    }

    sort(percent.begin(),percent.end());


    for(int i = 0; i <percent.size(); i++){
        answer.push_back(int(percent[i][1]));
    }


    return answer;
}