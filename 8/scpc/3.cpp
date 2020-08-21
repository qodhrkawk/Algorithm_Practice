/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/


#include <vector>
#include <algorithm>
#include <time.h>
#include <iostream>


using namespace std;

int Answer;

// vector<vector<int> > lines(1502,vector<int>(2002,0));
// vector<vector<int> > nexts(1502,vector<int>(2002,0));


int lines[1502][2002] = {0,};
int nexts[1502][2002] = {0,};


int bfs(int time, int start, int end,int deleted){
    int minimum = 3000;

    if(nexts[start][time] == -1){
        
        if(start == end){
            return deleted;

        }
        else{
            return -1;
        }

    }
    
    int first = bfs(nexts[start][time],start,end,deleted+1);

    if(first>=0){
        minimum = min(minimum,first);
    }
    

    int index = nexts[start][time];
    
    int tmp = -1;

    while(index >= 0){

        tmp = bfs(index,lines[start][index],end,deleted);

        if(tmp >= 0){
            minimum = min(minimum,tmp);
        }

        index = nexts[start][index];

        deleted++;
    }


    if(minimum == 3000){
        return -1;
    }


    return minimum;
    



}


int main(int argc, char** argv)
{
	int T, test_case;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    


	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		
        int n,k,m;

        cin>>n>>k>>m;

        int s, e;
        


        

        vector<int> ntmp(n+1,0);
        

        for(int i = 0; i <k; i++){
            cin>>s>>e;

            lines[s][i+1] = e;
            lines[e][i+1] = s;


            nexts[s][ntmp[s]] = i+1;
            nexts[e][ntmp[e]] = i+1;

            ntmp[s] = i+1;
            ntmp[e] = i+1;
        }

        for(int i = 1; i < n+1; i++){
            nexts[i][ntmp[i]] = -1;
        }



        for(int i = 0; i < m; i++){
            cin>>s>>e;
            Answer += bfs(0,s,e,0);
        }
        

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}