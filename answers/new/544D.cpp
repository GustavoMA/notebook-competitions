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
#define MAX_N 4000
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-4
//freopen ("in.txt", "r", stdin);
//freopen ("out.txt","w", stdout);

/**
*** Codeforces - 544 - D. Destroying Roads
*** http://codeforces.com/contest/544/problem/D
*** Tag: Graph, BF
*** Author: Gustavo Monteiro Alves - GustavoMA
**/

//Matrix of adj. starting from 1 to n
int d[MAX_N][MAX_N];

void pre_process(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1 ; j <= n; j++) {
            d[i][j] = (i == j) ? 0 : INF;
        }
    }
}

void floyd_marshall(int n) {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j<= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main() {
    int n, m;
    cin >> n >> m;
    pre_process(n);
    for (int i = 1; i <= m; i++) {
        int a,b;
        cin >> a >> b;
        d[a][b] = 1;
        d[b][a] = 1;
    }
    floyd_marshall(n);
    int s[2], t[2], l[2];
    cin >> s[0] >> t[0] >> l[0];
    cin >> s[1] >> t[1] >> l[1];
    int ans = m + 1;
    for (int iter = 0; iter < 2; iter++) {
        swap(s[0], t[0]);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int v[] = {d[s[0]][i] + d[i][j] + d[j][t[0]],
                           d[s[1]][i] + d[i][j] + d[j][t[1]]};
                if (v[0] <= l[0] && v[1] <= l[1]) {
                    ans = min(ans, v[0]+v[1]-d[i][j]);
                }
            }
        }
    }
    if (d[s[0]][t[0]] <= l[0] && d[s[1]][t[1]] <= l[1]) {
        ans = min(ans, d[s[0]][t[0]] + d[s[1]][t[1]]); 
      }

      if (ans > m) {
        ans = -1;
      } else {
        ans = m - ans;
      }

      printf("%d\n", ans);
}
