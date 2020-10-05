#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


vector<pair<int,int> > startEnd;

int toSecond(string s){

    string si = s.substr(0,2);
    string bun = s.substr(3,2);
    string cho = s.substr(6,2);

    return stoi(si)*3600 + stoi(bun) * 60 + stoi(cho);

}

string toOrigin(int n){

    int si = n/3600;
    int forBun = n%3600;

    int bun = forBun/60;
    int cho = forBun%60;

    string res = "";

    string hour = to_string(si);
    if(hour.length() == 1){
        hour = '0'+hour; 
    }
    string min = to_string(bun);
    if(min.length() == 1){
        min = '0'+ min; 
    }
    string sec = to_string(cho);
    if(sec.length() == 1){
        sec = '0'+sec; 
    }


    res += hour + ":" + min + ":" + sec;

    return res;
}


string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";

    // sort(logs.begin(),logs.end());
    int total = toSecond(play_time);
    int adLen = toSecond(adv_time);
    long long int bestCase = 0;

    for(int i = 0; i < logs.size(); i++){
        string start = logs[i].substr(0,8);
        string end = logs[i].substr(9,8);
        startEnd.push_back(make_pair(toSecond(start),toSecond(end)));
    }

    sort(startEnd.begin(),startEnd.end());

    for(int i = 0; i < startEnd.size(); i++){
        
        int tmpEnd = startEnd[i].first + adLen;
        long long int tmpRes = min(startEnd[i].second,tmpEnd) - startEnd[i].first;

        if(tmpEnd > total){
            break;
        }

        for(int j = i+1; j<startEnd.size(); j++){
            if(startEnd[j].first < tmpEnd){
                tmpRes += min(startEnd[j].second,tmpEnd) - startEnd[j].first;
            }
            else{
                break;
            }

        }

        if(bestCase < tmpRes){
            bestCase = tmpRes;
            answer = toOrigin(startEnd[i].first);
        }


    }

    if(answer == ""){
        answer = "00:00:00";
    }

    return answer;
}