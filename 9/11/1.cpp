#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string new_id) {
    string answer = "";


    //1단계

    for(int i = 0; i < new_id.length(); i++){

        if(new_id[i] >=65 && new_id[i] <= 90){
            new_id[i] += 32;
        }

    }
    

    //2단계

    for(int i = 0; i < new_id.length(); i++){
        if(new_id[i] >=97 && new_id[i] <= 122)
            continue;
        else if(new_id[i] >= 48 && new_id[i] <= 57)
            continue;
        else if(new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
            continue;
        else{
            new_id.erase(new_id.begin()+i,new_id.begin()+i+1);
            --i;
        }
    }
    // 3단계

    for(int i = 0; i < new_id.length()-1; i++){
        if(new_id[i] == '.'){
            if(new_id[i+1] == '.'){
                new_id.erase(new_id.begin()+i,new_id.begin()+i+1);
                --i;
            }
        }
    }

    // 4단계

    if(new_id[0] == '.'){
        new_id.erase(new_id.begin(),new_id.begin()+1);
    }
    

    if(new_id[new_id.length()-1] == '.'){
        new_id.erase(new_id.end()-1,new_id.end());
    }
    // 5단계
    if(new_id == ""){
        new_id += 'a';
    }


    //6단계

    if(new_id.length() >= 16){
        new_id.erase(new_id.begin()+15,new_id.end());
    }

    if(new_id[new_id.length()-1] == '.'){
        new_id.erase(new_id.end()-1,new_id.end());
    }
    //7단계

    while(new_id.length() < 3){
        new_id += new_id[new_id.length()-1];
    }
    answer = new_id;

    return answer;
}