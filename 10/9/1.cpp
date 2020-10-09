#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;





int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin>>n;
    queue<int> st;

    for(int t = 0; t<n; t++){
        string s;
        int num;
        cin>>s;

        if(s == "push"){
            cin>>num;
            st.push(num);
        }
        else if(s == "front"){
            if(st.empty()){
                cout<<-1<<endl;
            }
            else{
                cout<<st.front()<<endl;
            }
            
        }
        else if(s == "size"){
            cout<<st.size()<<endl;
        }
        else if(s == "pop"){
            if(st.empty()){
                cout<<-1<<endl;
            }
            else{
                cout<<st.front()<<endl;
                st.pop();
            }
        }
        else if(s == "empty"){
            if(st.empty()){
                cout<<1<<endl;
            }
            else{
                cout<<0<<endl;
            }
        }
        else if(s=="back"){
            if(st.empty()){
                cout<<-1<<endl;
            }
            else{
                cout<<st.back()<<endl;
            }
        }


    }


	return 0;
}