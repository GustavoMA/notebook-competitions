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
#define INF 1000000010
#define LINF 1000000000000000010
#define MAX_N 100100
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-4

/**
*** Codeforces - 686 - A. Free Ice Cream
*** http://codeforces.com/contest/686/problem/A
*** Tag:
*** Author: Gustavo Monteiro Alves - GustavoMA
**/

//read files
//freopen ("in.txt", "r", stdin);
//freopen ("out.txt","w", stdout);

int main() {
    int n, dis = 0;
    ll x;
    scanf(" %d %lld", &n, &x);
    for (int i = 0; i < n; i++) {
        char flag;
        ll ice;
        scanf(" %c %lld", &flag, &ice);
        if (flag == '+') x += ice;
        if (flag == '-') {
            if (ice <= x) {
                x -= ice;
            } else {
                dis++;
            }
        }
    }
    printf("%lld %d\n", x, dis);
    return 0;
}
