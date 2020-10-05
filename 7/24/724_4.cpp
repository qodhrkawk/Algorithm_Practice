#include <string>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

string convert(int num,int size){
    string ans;

    for(int i = size-1; i >=0; i--){
        if(num >= pow(2,i)){
            num-=pow(2,i);
            ans+="#";
        }
        else{
            ans+=" ";
        }

    }



    return ans;


}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    vector<string> res1;
    vector<string> res2;

    



    for(int i = 0; i <n; i++){
        res1.push_back(convert(arr1[i],n));
        res2.push_back(convert(arr2[i],n));
        

    }

    for(int i = 0; i < n ; i++){
        string tmp;
        for(int j = 0; j < n;  j++){
        
        if(res1[i][j] == '#' || res2[i][j] == '#'){
            tmp += "#";
        }
        else{
            tmp += " ";
        }
        }
        answer.push_back(tmp);

    }
    



    return answer;
}



int main(){
    int a = 8;
    cout<< convert(a,7)<<endl;



    return 0;
}