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
#define MAX_N 10100
#define MOD 1000000007

/**
*** UVA 10491 - Cows and Cars
*** http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1432
*** Tip: http://www.questtosolve.com/browse.php?pid=10491
*** Author: Gustavo Monteiro Alves - GustavoMA
**/


int main() {
    double cow, car, show;
    while (scanf(" %lf %lf %lf", &cow, &car, &show) != EOF) {
        double p = ( cow / (cow + car) ) * ( (car)   / (cow + car - show - 1) ) + 
                   ( car / (cow + car) ) * ( (car-1) / (cow + car - show - 1) );
        printf("%0.5lf\n", p);        
    }
    return 0;
}