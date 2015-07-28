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
//freopen ("in.txt", "r", stdin);
//freopen ("out.txt","w", stdout);

/**
*** Codeforces - C. The Child and Toy
*** http://codeforces.com/problemset/problem/437/C
*** Tag: Greedy
*** Author: Gustavo Monteiro Alves - GustavoMA
**/

int v[MAX_N];

int main(int argc, char const *argv[]) {
    int n, m;
    scanf(" %d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf(" %d", &v[i]);
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf(" %d %d", &x, &y);
        ans += min(v[x], v[y]);
    }
    printf("%d\n", ans);
    return 0;
}
