#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string toBinary(int n){
    string binary = "";
    while(n>0){
        if(n%2 ==0){
            binary+= '0';
        }
        else{
            binary += '1';
        }
        n = n/2;
        
    }
    reverse(binary.begin(),binary.end());


    return binary;
}


int solution(int n) {
    int answer = n;

    string binary = toBinary(n);
    
    int ones = count(binary.begin(),binary.end(),'1');
    int alls = binary.length();

    while(1){
        answer++;
        string tmp = toBinary(answer);
        if(count(tmp.begin(),tmp.end(),'1') == ones){
            break;
        }


    }


    




    return answer;
}



int main(){

    int a = 78;

    cout<<solution(a)<<endl;;


    return 0;
}