
#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <time.h>


using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	// freopen("input.txt", "r", stdin);

	cin >> T;




	for(test_case = 0; test_case  < T; test_case++)
	{

		vector<int> answer;
		/////////////////////////////////////////////////////////////////////////////////////////////
        int n,k;

        cin>>n>>k;

        vector<int> a(n+1);
        vector<int> b(n+1);

        for(int i = 1; i<= n; i++){
            cin>>a[i];
        }

        for(int i = 1; i<= n; i++){
            cin>>b[i];
        }

        clock_t start,end;


        vector<vector<int> > dp(3001,vector<int> (3001,0));
        int ans1 = 0;
        int ans2 = 0;            


        long long tmp = k;

        start = clock();

        for(int i = 0; i<= n; i++){
            if(i ==0){
                    dp[i][0] = k;
                    tmp = k;
                    ans1++;
                }
            else{
                if(dp[i-1][0] > 0){
                    if(tmp+a[i] <= k){
                        tmp += a[i];
                        dp[i][0] = tmp;
                        
                        
                    }
                    else{
                        tmp = a[i];
                        dp[i][0] = -tmp;
                    }
                }

                else{
                    tmp = a[i];
                    dp[i][0] = tmp;
                }



            }
        }

        tmp = k;

        for(int j = 0; j<= n; j++){
            if(j ==0){
                    dp[0][j] = k;
                    tmp = k;
                }
            else{
                if(dp[0][j-1] > 0){
                    if(tmp+b[j] <= k){
                        tmp += b[j];
                        dp[0][j] = tmp;
                    }
                    else{
                        tmp = b[j];
                        dp[0][j] = -tmp;
                    }
                }

                else{
                    tmp = b[j];
                    dp[0][j] = tmp;
                }



            }



        }

        


        for(int i = 1; i<= n; i++ ){
            for(int j = 1; j<=n; j++){
                if(dp[i-1][j] < 0){
                    dp[i][j] = a[i];
                }
                if(dp[i-1][j] < 0){
                    if(dp[i][j]!= 0){
                        dp[i][j] = min(dp[i][j],b[j]);
                    }
                    else{
                        dp[i][j] = b[j];
                    }
                }

                if(dp[i-1][j] > 0 && dp [i][j-1] >0){
                    int temp1 = 0;
                    int temp2 = 0;
                    for(int x = i-1; x>= 0; x--){
                        if(dp[x][j]<0){
                            break;
                        }
                        temp1 += dp[x][j];
                    }    
                    for(int y = j-1; y>= 0; y--){
                        if(dp[i][y]<0){
                            break;
                        }
                        temp2 += dp[i][y];
                    }                     
                    if(temp1 + a[i] > k && temp2 + b[j] > k){
                        dp[i][j] = -1;
                    }

                    else{
                        dp[i][j] = max(temp1+a[i],temp2+b[j]);
                        
                    }



                }
            }
        }




        for(int i = 0 ; i <= n; i++){
            for(int j = 0; j <= n; j++){
                if(dp[i][j]>0)
                    ans1++;
                else
                    ans2++;

            }
        }


        end = clock();

        double result = (double) (end-start);

        cout<< result/CLOCKS_PER_SEC <<endl;

        answer.push_back(ans1-1);
        answer.push_back(ans2);


		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << answer[0] <<  " " << answer[1] << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}