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
#define MAX_N 1000010
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-4

/**
*** Codeforces - 574 - D. Bear and Blocks 
*** http://codeforces.com/contest/574/problem/D
*** Tag:
*** Author: Gustavo Monteiro Alves - GustavoMA
**/

//read files
//freopen ("in.txt", "r", stdin);
//freopen ("out.txt","w", stdout);

int t[MAX_N], res[MAX_N];

int main() {
    int n;
    scanf(" %d", &n);
    for (int i = 1; i <= n; i++) {
        scanf(" %d", &t[i]);
    }
    int w = 0;
    for (int i = 1; i <= n; i++) {
        w = min(w, t[i]-i);
        res[i] = i + w;
    }
    w = n+1;
    for (int i = n; i >= 1; i--) {
        w = min(w, t[i]+i);
        res[i] = min(res[i], w-i);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, res[i]);
    }
    printf("%d\n", ans);
    return 0;
}
