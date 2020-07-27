#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;

    sort(citations.begin(),citations.end());

    int mid = ceil(double(citations.size()/2));

    answer = citations[mid-1];





    return answer;
}


int main(){
    cout<< ceil(2.5)<<endl;
    cout << ceil(double(5.0/2.0))<<endl;
    cout<<5/2<<endl;
    // cout<< "hello"<<endl;

    return 0;
}