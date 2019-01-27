/*
	Nicholas DiMaria
*/

#include <iostream>
#include <random>
using namespace std;

double choose(int n, int r) {
	static double memo[500][500] = {0};
    if (r==0)
        return 1;
    else if(n==r)
        return 1;
    else if (memo[n][r]!=0)
        return memo[n][r];
    else
        return memo[n][r]=choose(n-1,r-1) + choose(n-1,r);
}

int main() {

	int n=0;
	int r=0;
	for(n=0; n<=500;n++){
			for(r=0; r<=n;r++){
					choose(n,r);
			}
	}
	
  int numTrials = 100000000;
	//  cin >> numTrials;
	default_random_engine generator;
	uniform_int_distribution<int> distribution(0,500);

  for (int i = 0; i < numTrials; i++) {
		int n = distribution(generator);
		uniform_int_distribution<int> rdist(0,n);
		int r = rdist(generator);
    choose(n,r);
	}
}
