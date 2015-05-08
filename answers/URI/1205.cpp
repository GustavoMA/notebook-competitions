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
#define MAX_N 1010
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-4

/**
*** URI - 1205 - Cerco a Leningrado
*** https://www.urionlinejudge.com.br/judge/pt/problems/view/1205
*** Tag: Dijkstra
*** Author: Gustavo Monteiro Alves - GustavoMA
**/

double exp(double n, int e) {
    if (e == 0) return 1.0;
    if (e % 2  == 1) return n * exp(n, e-1);
    double half = exp(n, e/2);
    return half*half;
}

vi adj_list[MAX_N];
int shoot[MAX_N];
int germ[MAX_N];
priority_queue<ii, vector<ii>, greater<ii> > PQ;

void pre_process(int n) {
    for (int i = 1; i <= n; i++) {
        germ[i] = INF;
        shoot[i] = 0;
        adj_list[i].clear();
    }
}

void Dijkstra(int root) {
    PQ.push(mp(0, root));
    germ[root] = 0;

    while(!PQ.empty()) {
        int v = PQ.top().sc;
        int n = PQ.top().fi;
        PQ.pop();
        if (n > germ[v]) continue;

        for (int i = 0; i < (int) adj_list[v].size();i++) {
            int u = adj_list[v][i];
            if (germ[v] + shoot[v] < germ[u]) {
                germ[u] = germ[v] + shoot[v];
                PQ.push(mp(germ[u], u));
            }
        }
    }
}

int main() {
    int n, m, k;
    double p;
    while(scanf(" %d %d %d %lf", &n, &m, &k, &p) != EOF) {
        pre_process(n);
        for (int i = 0; i < m; i++) {
            int a,b;
            scanf(" %d %d", &a, &b);
            adj_list[a].pb(b);
            adj_list[b].pb(a);
        }
        int g;
        scanf(" %d", &g);
        for (int i = 0; i < g; i++) {
            int temp;
            scanf(" %d", &temp);
            shoot[temp]++;
        }
        int a, b;
        scanf(" %d %d", &a, &b);
        Dijkstra(a);
        int val = germ[b] + shoot[b];
        double ans = exp(p, val);
        if (val > k) {
            printf("0.000\n");
        } else {
            printf("%.3lf\n", ans);
        }
    }
    return 0;
}
