#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;





int main(){
    
    int n;

    cin>>n;

    vector<int> rings(n,0);
    for(int i = 0;i <n; i++){
        cin>>rings[i];

    }

    
    for(int i = 1; i < rings.size(); i++){
        int first = rings[0];
        int under = rings[i];

        for(int j = under; j>=2; j--){
            if(first%j==0 && under%j == 0){
                first = first/j;
                under = under/j;
            }
        }
        cout<<first<<"/"<<under<<endl;

    }



}