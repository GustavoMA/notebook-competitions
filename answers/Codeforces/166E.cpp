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
#define MAX_M 2
#define MAX_N 10000010
#define MOD 1000000007

/**
*** Codeforces 166 - E. Tetrahedron
*** http://codeforces.com/problemset/problem/166/E
*** Author: Gustavo Monteiro Alves - GustavoMA
**/

int main() {
    int n;
    scanf(" %d", &n);
    ll A = 0L, B = 0L, C = 0L;
    ll D = 1L;
    for (int i = 1; i <= n; i++) {
        ll Di = (A % MOD + B % MOD + C % MOD) % MOD;
        ll Ai = (D % MOD + B % MOD + C % MOD) % MOD;
        ll Bi = (D % MOD + A % MOD + C % MOD) % MOD;
        ll Ci = (D % MOD + A % MOD + B % MOD) % MOD;
        A = Ai;
        B = Bi;
        C = Ci;
        D = Di;
    }
    printf("%Ld\n", D);
}
