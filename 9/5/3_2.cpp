#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int n,k;

int MAX = 1000001;
vector<int> arr(MAX,0);


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>k;

    for(int i = 1; i<=n;i++){
        cin>>arr[i];
    }
    int s, e;
    for(int t = 0; t<k; t++){
        cin>>s>>e;
        vector<int> tmpVec;
        tmpVec.assign(arr.begin()+s,arr.begin()+e+1);

        sort(tmpVec.begin(),tmpVec.end());

        int now = tmpVec[0];
        int mult = 1;
        int res = 0;
        for(int i = 1; i< tmpVec.size(); i++){
            if(now != tmpVec[i]){
                res += now * (mult+1)*mult/2;
                now = tmpVec[i];
                mult = 1;
            }
            else{
                mult++;
            }


        }
        res += now * (mult+1)*mult/2;

        cout<<res<<endl;

    }
    

	
    return 0;
}