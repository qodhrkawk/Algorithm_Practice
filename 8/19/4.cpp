#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;





int main(){

    int n;

    cin>>n;

    vector<int> nums(10001,0);

    for(int i = 0; i <n; i++){
        int tmp;
        cin>>tmp;
        nums[tmp]++;
    }


    for(int i = 1; i < 10001; i++){
        if(nums[i]>0){

            for(int i = 0; i <nums[i]; i++){
                cout<<i<<endl;
            }

        }
        
    }




    return 0;
}