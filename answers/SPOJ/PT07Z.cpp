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
*** SPOJ - PT07Z - Longest path in a tree
*** http://www.spoj.com/problems/PT07Z/
*** Tag: graph
*** Author: Gustavo Monteiro Alves - GustavoMA
**/

vi adj_list[MAX_N];
int dist[MAX_N];
int used[MAX_N];

void dfs(int root, int d) {
    used[root] = 1;
    dist[root] = d;
    for (int i = 0; i < adj_list[root].size(); i++) {
        int v = adj_list[root][i];
        if (!used[v]) dfs(v, d+1);
    }
}

int main(int argc, char const *argv[]) {
    int n;
    scanf(" %d", &n);
    for (int i = 1; i <= n; i++) {
        int u, v;
        scanf(" %d %d", &u, &v);
        adj_list[u].pb(v);
        adj_list[v].pb(u);
    }
    memset(used, 0, sizeof used);
    dfs(1, 0);
    int mx = 0;
    int idx = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] > mx) {
            idx = i;
            mx = dist[i];
        }
    }
    memset(used, 0, sizeof used);
    dfs(idx, 0);
    mx = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] > mx) {
            idx = i;
            mx = dist[i];
        }
    }
    printf("%d\n", mx);
    return 0;
}
