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
#define MAX_N 110
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-4
//freopen ("in.txt", "r", stdin);
//freopen ("out.txt","w", stdout);

/**
*** UVa - 820 - Internet Bandwidth
*** https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=761
*** Tag: Flow
*** Author: Gustavo Monteiro Alves - GustavoMA
**/

int res[MAX_N][MAX_N], f, s, t, mf;  // global variables
vector<vi> adj_list;
vi p;  //BFS spanning tree

void augment(int v, int minEdge) {     // traverse BFS spanning tree from s to t
    if (v == s) {
        f = minEdge;
        return;
    }
    else if (p[v] != -1) {
        augment(p[v], min(minEdge, res[p[v]][v])); // recursive
        res[p[v]][v] -= f; res[v][p[v]] += f;
    }
}

void edmonds_karp() {
    mf = 0;              // mf stands for max_flow
    while (1) {              // O(VE^2) (actually O(V^3E) Edmonds Karp's algorithm
        f = 0;
        // run BFS
        bitset<MAX_N> visited;
        visited.set(s);
        queue<int> q; q.push(s);
        p.assign(MAX_N, -1);           // record the BFS spanning tree, from s to t
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (u == t) break;      // immediately stop BFS if we already reach sink t
            for (int i = 0; i < (int) adj_list[u].size(); i++) {
                int v = adj_list[u][i];
                if (res[u][v] > 0 && !visited.test(v)) {
                    visited.set(v);
                    q.push(v);
                    p[v] = u;
                }
            }
        }
        augment(t, INF);     // find the min edge weight `f' along this path, if any
        if (f == 0) break;      // we cannot send any more flow (`f' = 0), terminate
        mf += f;                 // we can still send a flow, increase the max flow!
    }
    //return mf;
}

int main() {
    int caso = 0;
    int n;
    while(scanf(" %d", &n), n){
        adj_list.assign(n, vi());
        memset(res, 0, sizeof res);

        int c;
        scanf(" %d %d %d", &s, &t, &c);
        s--;t--;

        for (int i = 0; i < c; i++) {
            int a, b, w;
            scanf(" %d %d %d", &a, &b, &w);
            a--;b--;
            adj_list[a].pb(b);
            adj_list[b].pb(a);
            res[a][b] = w;
            res[b][a] = w;
        }
        edmonds_karp();
        printf("Network %d\nThe bandwidth is %d.\n\n", ++caso, mf);
        //printf("Network %d\n", ++caso);
        //printf("The bandwidth is %d.\n\n", mf);
    }
    return 0;
}
