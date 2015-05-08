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
*** UVa 10784 - Diagonal
*** http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1725
*** Author: Gustavo Monteiro Alves - GustavoMA
**/

inline ll diagonals(ll n) {
    if (n&1) return n * ((n-3)/2);
    else return (n/2) * (n-3);
}

ll binary_search(ll n) {
    ll left = 1;
    ll right = 100000000;

    while (left < right) {
        ll mid = (left + right) / 2;
        if (diagonals(mid) >= n) right = mid;
        else left = mid + 1;
    }

    return left;
}

int main() {
    ll n, t = 0;
    while(true) {
        scanf(" %Ld", &n);
        if (n == 0LL) break;
        printf("Case %Ld: %Ld\n", ++t, binary_search(n));
    }
    return 0;
}
