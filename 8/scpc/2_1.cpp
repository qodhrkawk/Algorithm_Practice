/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <vector>
#include <algorithm>




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




        
        vector<vector<int> > dp (n+1,vector<int>(n+1,0));
        

        
        
        int ans1 = 0;
        int ans2 = 0;            

        a[0] = k;
        b[0] = k;

        vector<int> avec(n+1,0);
        vector<int> bvec(n+1,0);

        for(int i = 0; i<= n; i++){
            if(i ==0){
                avec[i] = k;
                bvec[i] = k;
                ans1++;

            }
            else{
                if(avec[i-1] > 0){
                    if(avec[i-1]+a[i] <= k){
                        avec[i] = avec[i-1]+a[i];
                        ans1++;
                    }
                    else{
                        avec[i] = -1;
                        ans2++;
                    }
                }

                else{
                    avec[i] = a[i];
                    ans1++;
                }


                if(bvec[i-1] > 0){
                    if(bvec[i-1]+b[i] <= k){
                        bvec[i] = bvec[i-1]+b[i];
                        ans1++;
                    }
                    else{
                        bvec[i] = -1;
                        ans2++;
                    }
                }

                else{
                    bvec[i] = b[i];
                    ans1++;
                }
            }

    
        }

        for(int i = 0 ; i <= n ; i++){
            dp[i][0] = avec[i];
            dp[0][i] = bvec[i];
        }
        
        


        for(int i = 1; i<= n; i++ ){
            for(int j = 1; j<=n; j++){
                if(dp[i-1][j] < 0 || dp[i][j-1] <0){
                    dp[i][j] = 1;
                    ans1++;
                }
    
                else{
                    int temp1 = 0;
                    int temp2 = 0;
                    for(int x = i-1; x>= 0; x--){
                        if(dp[x][j]<0){
                            break;
                        }
                        temp1 += a[x];
                    }

                    for(int y = j-1; y>= 0; y--){
                        if(dp[i][y]<0){
                            break;
                        }
                        temp2 += b[y];
                    }   

                    if(temp1 + a[i] > k && temp2 + b[j] > k ){
                        dp[i][j] = -1;
                        ans2++;
                    }
                    else{
                        dp[i][j] = 1;
                        ans1++;
                    }
                    
                }
            }
        }





		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << ans1 << " "<< ans2 << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}