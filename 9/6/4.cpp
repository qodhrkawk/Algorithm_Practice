#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


int n,k;


int main() {
    
    cin>>n>>k;

    vector<int> arr(n,0);

    for(int i = 0;i <n;i++){
        arr[i] = i+1;
    }


    cout<<"<";

    int nowIdx  = 0;

    while(arr.size()>0){

        int s = arr.size();

        nowIdx = (nowIdx + k - 1)% s; 

        cout<<arr[nowIdx];

        arr.erase(arr.begin()+nowIdx, arr.begin()+nowIdx+1);

        if(arr.size()>0){
            cout<<", ";
        }
    }


    cout<<">"<<endl;

	return 0;
}