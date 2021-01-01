#include <iostream>


using namespace std;

int n,t;
const int MAX = 1025;


int map[MAX][MAX];


int main() {

    ios_base::sync_with_stdio(0);

    cin.tie(0);
    cout.tie(0);


    cin>>n>>t;

    for(int i = 1; i<= n;i++){
        for(int j = 1; j<=n; j++){
            int num;
            cin>>num;

            map[i][j] = map[i-1][j] + map[i][j-1] - map[i-1][j-1] + num;

        }
    }  



    for(int test = 0; test<t; test++){
        int x1,x2,y1,y2;

        cin>>y1>>x1>>y2>>x2;

        cout<<map[y2][x2] - map[y1-1][x2] - map[y2][x1-1] + map[y1-1][x1-1]<<"\n";

    }





	return 0;
}