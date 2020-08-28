#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>

using namespace std;

vector<int> nums(100001,0);
int n,k;


int main() {
	
    
    cin>>n>>k;

    if(n==k){
        cout<<1<<endl;
        return 0;
        
    }

    for(int i = 1; i <= n; i++){
        cin>>nums[i];
    }

    int minimum = INT32_MAX;
    int index = 0;
    for(int i = 1; i <= n; i++){
        if(minimum > nums[i]){
            index = i;
            minimum = nums[i];
        }
    }

    int left = index - 1;
    int right = n - index;

    int ans = n;

    for(int i = 1; i <= k; i++){

        double remainLeft = left - (i-1);
        double remainRight = right - (k-i);

        int tmp = 1 + ceil(remainLeft/(k-1)) + ceil(remainRight/(k-1));

        ans = min(ans,tmp);


    }





    cout<<ans<<endl;



	return 0;
}