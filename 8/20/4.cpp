#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>

using namespace std;



int main(){

    int n;
    cin>>n;

    vector<int> arr(n);

    for(int i = 0; i <n; i++){
        cin>>arr[i];
    }

    cout<<arr[0]*arr[n-1]<<endl;



    return 0;
}