#include <string>
#include <vector>
#include <iostream>

using namespace std;
long long factorial(int n) {

	long long result = 1;
    if(n==0)
        return 1;
	for (int i = 1; i <= n; i++) {
		result *= i;
	}
	return result;

}


long long comb(int n, int a) {


	if (a == 0) {
		return 1;
	}
	

	return factorial(n) / (factorial(a)*factorial(n - a));
	

}


int solution(int n) {
	int answer = 0;
	long long tmp = 0;
	for (int i = 0; i <= n/2; i++) {
		tmp+=comb(n - i, i);
	}

	answer = tmp % 1000000007;




	return answer;
}