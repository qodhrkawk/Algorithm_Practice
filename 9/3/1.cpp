#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long int n,m,k,res;
vector<int> arr(1000001,0);


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m>>k;

    for(int i = 1; i<=n;i++){
        cin>>arr[i];
    }

    int a,b,c;

    for(int i = 0; i < m+k; i++){
        cin>>a>>b>>c;

        if(a == 1){
            arr[b] = c;
        }
        else{
            res = 0;
            for(int j = b; j<=c; j++){
                res += arr[j];
            }
            cout<<res<<endl;
        }
    

    }




	return 0;
}