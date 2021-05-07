

#include <iostream>
#include <string>

using namespace std;

string answer = "";

int D(int n) {
    return (2*n)%10000;
}

int S(int n) {

    if(n == 1) {
        return 9999;
    }
    return n-1;
}

int L(int n) {
    string s = to_string(n);
    string answer = "";
    for(int i = 1 ; i< s.length(); i++) {
        answer += s[i];
    }
    answer += s[0];

    return stoi(answer);
}

int R(int n) {
    string s = to_string(n);
    string answer = "";
    answer += s[s.length()-1];
    for(int i = 0 ; i< s.length()-1; i++) {
        answer += s[i];
    }
    
    return stoi(answer);
    
}



void dfs(int a, int b,string s,int recursionLimit){
    if(s.length() > recursionLimit) {
        return;
    }
    if(a == b) {
        answer = s;
        return;
    }
    else {
        dfs(D(a),b, s+'D',recursionLimit);
        dfs(S(a), b, s + 'S',recursionLimit);
        dfs(L(a), b, s + 'L',recursionLimit);
        dfs(R(a), b, s + 'R',recursionLimit);
    }
    return;
}


int main() {
    int t,a,b;

    cin>>t;

    for(int i = 0; i< t; i++) {
        cin>>a>>b;
        int recursionLimit = 0;
        while(answer == "") {
            recursionLimit += 1;
            dfs(a,b,"",recursionLimit);
        }
        cout<<answer<<endl;
        answer = "";
    }
    return 0;


}
