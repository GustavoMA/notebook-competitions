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
#define MAX_N 550
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-4
//freopen ("in.txt", "r", stdin);
//freopen ("out.txt","w", stdout);

/**
*** Codeforces - 544 - C. Writing Code
*** http://codeforces.com/contest/544/problem/C
*** Tag: DP
*** Author: Gustavo Monteiro Alves - GustavoMA
**/

int bug[MAX_N];
int dp[5][MAX_N][MAX_N];

int main() {
    int n, m,b, mod;
    cin >> n >> m >> b >> mod;
    for (int i = 0; i < n; i++) cin >> bug[i];

    dp[0][0][0] = 1;
    for (int it = 1; it <= n; it ++) {
        int i = it & 1;
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= b; k++) {
                dp[i][j][k] = dp[i ^ 1][j][k] % mod;
                if (j > 0 && k >= bug[it-1])
                    dp[i][j][k] = (dp[i][j][k] + dp[i][j-1][k-bug[it-1]]) % mod;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= b; i++) {
        ans = (ans + dp[n&1][m][i]) % mod;
    }
    cout << ans << endl;
}
