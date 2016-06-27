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
#define MAX_N 4010
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-4

/**
*** Codeforces - 574 - B. Bear and Three Musketeers
*** http://codeforces.com/problemset/problem/574/B
*** Tag:
*** Author: Gustavo Monteiro Alves - GustavoMA
**/

//read files
//freopen ("in.txt", "r", stdin);
//freopen ("out.txt","w", stdout);

int adj_mat [MAX_N][MAX_N];
int rec[MAX_N];

int main() {
    int n, m;
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf(" %d %d", &a, &b);
        adj_mat[a][b] = 1;
        adj_mat[b][a] = 1;
        rec[a]++;
        rec[b]++;
    }
    int ans = INF;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (adj_mat[i][j]) {
                for (int k = j + 1; k <= n; k++) {
                    if (adj_mat[i][k] && adj_mat[j][k]) {
                        ans = min(ans, rec[i] + rec[j] + rec[k]);
                    }
                }
            }
        }
    }
    if (ans == INF) printf("-1\n");
    else printf("%d\n", ans-6);
    return 0;
}
