#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n;



int main() {

    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
	

    cin>>n;


    vector<int> arr(n,0);

    for(int i = 0; i < n ;i++){
        cin>>arr[i];
    }

    sort(arr.begin(),arr.end());

    int tmp = 1001;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == tmp){
            continue;
        }
        else{
            cout<<arr[i]<<" ";
            tmp = arr[i];
        }

    }

    cout<<endl;




	return 0;
}