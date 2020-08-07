#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int ans = 0;
string first = "";
string second = "";
string relation = "";
vector<int> nums(0,0);


bool check(string line,int n){
    int firstIdx = 0;
    int secondIdx = 0;
    for(int i = 0; i <n;i++){
        for(int j = 0; j < 8; j++){
            if(first[i] == line[j])
                firstIdx = j;
            if(second[i] == line[j])
                secondIdx = j;

        }

        if(relation[i] == '='){
            if(abs(firstIdx-secondIdx) != nums[i]+1){
                return false;
            }


        }
        else if (relation[i] == '<'){
            
            if(abs(firstIdx-secondIdx) >= nums[i]+1){
                return false;
            }


        }

        else if(relation[i] == '>'){
             if(abs(firstIdx-secondIdx) <= nums[i]+1){
                return false;
            }
        }
    }

    return true;
}


void permutation(string origin, int start, int end,int n){
   
    if(start == end){
        if(check(origin,n) == true){
            ans++;
        }
  
    }

    else {
        for(int i = start; i<=end; i++){
            swap(origin[start],origin[i]);
            permutation(origin,start+1,end,n);
            swap(origin[start],origin[i]);

        }


    }

}


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    
   


    for (auto d : data){
        first += d[0];
        second += d[2];
        relation += d[3];
        nums.push_back(d[4]-48);
    }
    string origin = "ACFJMNRT";

    permutation(origin,0,7,n);


    return ans;
}



