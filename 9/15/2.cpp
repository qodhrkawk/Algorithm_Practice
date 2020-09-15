#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>


using namespace std;

bool dp[10000] = {true,};

bool visited[10000] = {false, };

void bfs(){

    memset(visited,false,sizeof(visited));

    int a, b;

    cin>>a>>b;

    queue<pair<int,int> > q;

    q.push(make_pair(a,0));
    visited[a] = true;


    while(!q.empty()){

        int curNum = q.front().first;
        int curCnt = q.front().second;

        q.pop();    
    
        if(curNum == b){
            cout<<curCnt<<endl;;
            return;
        }

        for(int i = 0; i < 4; i++){
            int nNum;
            for(int j = 0;j < 10; j++){
                string s = to_string(curNum);
                s[i] = j + '0';
                nNum = stoi(s);

                if(dp[nNum] == false){
                    cout<<"called1"<<endl;
                    continue;

                }
                if(nNum <1000 || nNum>9999){
                    cout<<"called2"<<endl;
                    continue;

                }
                if(visited[nNum]){
                    cout<<"called3"<<endl;
                    continue;

                }

                visited[nNum] = true;
                q.push(make_pair(nNum,curCnt+1));
                



            }


        }



    }

    cout<<"Impossible"<<endl;
    return;



}



int main() {

    int testCase;

    cin>>testCase;

    dp[1] = false;
    for(int i = 2; i < 10000; i++){
        for(int j = 2; i*j< 10000; j++){
            dp[i*j] = false;
        }

    }




    for(int t = 0; t < testCase; t++){
        bfs();
    }



	return 0;
}