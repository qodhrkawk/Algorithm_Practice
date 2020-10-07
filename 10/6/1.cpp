#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


bool check(int n){

    string s = to_string(n);
    if(s.length() == 1){
        return true;
    }
    int interval = s[1] - s[0];

    for(int i = 1; i < s.length(); i++){
        int temp = s[i]-s[i-1];

        if(temp != interval){
            return false;
        }

    }

    return true;

}




int main() {

    int n;

    cin>>n;

    int answer = 0;
    for(int i = 1; i <=n; i++){
        if(check(i))
            answer++;

    }

    cout<<answer<<endl;


	return 0;
}