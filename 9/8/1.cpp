#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n,m;


int parent[1000001];

int Find(int x){

    if(parent[x] == x){
        return x;

    }

    else{
        int p = Find(parent[x]);
        parent[x] = p;
        return p;
    }
}

void Union(int x, int y){

    x = Find(x);
    y = Find(y);

    if(x!=y){
        parent[y] = x;
    }




}






int main() {
	

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    scanf("%d %d", &n, &m);


    for(int i = 0; i<= n; i++){
        parent[i] = i;

    }

    int a,b,c;


    for(int t = 0 ; t< m; t++){
        scanf("%d %d %d", &a, &b, &c);
        if(a==0){
            Union(b,c);
        }
        else{

            int bp = Find(b);
            int cp = Find(c);
            if(bp == cp){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
        }


    }





	return 0;
}