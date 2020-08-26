#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;


vector<int> dp;
vector<bool> mal(10,false);

bool check(int now){

    if (now == 0) {
        if (mal[0]) {
            return false;
        }
        else {
            return true;
        }
    }
    
    while (now > 0) {
        if (mal[now % 10]) return false;
        now = now / 10;
        
    }

    return true;
}




int main(){

    int n,c;
    cin>>n>>c;

    int tmp;

    for(int i = 0; i < c; i++){
        cin>>tmp;
        mal[tmp] = true;
    }


    string st = to_string(n);

    int minimum = abs(n-100);
    for(int i = 0; i <= 1000000; i++){
        if(check(i)){
            int tmp = abs(n-i)+st.length();
            minimum = min(minimum,tmp);
        }

    }


    cout<<minimum<<endl;


    return 0;
}