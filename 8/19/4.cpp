#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;




int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n;
    vector<int> nums(10001,0);

    cin>>n;

    int tmp;
    for(int i = 0; i <n; i++){
        cin>>tmp;
        nums[tmp]++;
    }


    for(int i = 1; i <= 10000; i++){
        for(int j = 0; j < nums[i]; j++){
            cout<<i<<"\n";
        }
    }




    return 0;
}