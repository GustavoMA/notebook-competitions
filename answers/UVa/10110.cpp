
#include <bits/stdc++.h>

using namespace std;

typedef long long      ll;
typedef pair<int, int> ii;
typedef vector<int>    vi;
typedef vector<ll>    vll;
typedef vector<ii>    vii;
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
#define INF 2000000000
#define MAX_N 100100

/**
*** UVa 10110 - Light, more light
*** http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1051
*** Tip: http://www.algorithmist.com/index.php/UVa_10110
*** Author: Gustavo Monteiro Alves - GustavoMA
**/


int main() {
	unsigned int n;
	while(true) {
		scanf(" %d", &n);
		if (n == 0) break;
		if ( (unsigned int) sqrt(n) * (unsigned int) sqrt(n) == n) {
			printf("yes\n");
		} else {
			printf("no\n");
		}
 	}
}

