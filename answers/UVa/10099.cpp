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
#define MAX_N 121
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-4
//freopen ("in.txt", "r", stdin);
//freopen ("out.txt","w", stdout);

/**
*** UVa - 10099 - The Tourist Guide
*** http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1040
*** Tag: Minmax, Maximum Spanning Tree
*** Author: Gustavo Monteiro Alves - GustavoMA
**/

int p[MAX_N], rank[MAX_N], size[MAX_N];

inline void build_union_find(int n) {
	for (int i = 1; i <= n; i++) {
		p[i] = i;
		rank[i] = 0;
		size[i] = 1;
	}
}
int find(int n) {
	return (p[n] == n) ? n : (p[n] = find(p[n]));
}
bool is_same_set(int i, int j) {
	return find(i) == find(j);
}
void union_set(int i, int j) {
	if (!is_same_set(i, j)) {
		int x = find(i), y = find(j);
		if (rank[x] > rank[y]) {
			p[y] = x;
			size[x] += size[y];
		} else {
			p[x] = y;
			size[y] += size[x];
			if(rank[x] == rank[y]) rank[y]++;
		}
	}
}
int union_size(int n) {
	return size[find(n)];
}

vector<pair<int, ii> > edges;
vii maximum_tree[MAX_N];
vi used;

int Kruskal(int n) {
    build_union_find(n);
    sort(edges.begin(), edges.end());
    reverse(edges.begin(), edges.end());
    int tot = 0;
    for (int i = 0; i < (int) edges.size(); i++) {
        int v = edges[i].sc.fi;
        int u = edges[i].sc.sc;
        int w = edges[i].fi;
        if (!is_same_set(v, u)) {
            tot += w;
            maximum_tree[v].pb(mp(u, w));
            maximum_tree[u].pb(mp(v, w));
            union_set(v, u);
        }
    }
    return tot;
}
int go;
int dfs(int u) {
    used[u] = 1;
    if (u == go) return -1;
    int mn = INF;
    for (int i = 0; i < (int) maximum_tree[u].size(); i++) {
        if (!used[maximum_tree[u][i].fi]) {
            int x = dfs(maximum_tree[u][i].fi);
            if (x == -1) return maximum_tree[u][i].sc;
            if (x != -2) return min(x, maximum_tree[u][i].sc);
        }
    }
    return -2;
}

int main() {
    int n, m;
    int caso = 0;
    while(1) {
        edges.clear();
        used.clear();
        scanf(" %d %d", &n, &m);
        for (int i = 1 ; i <= n; i++) maximum_tree[i].clear();
        if (!n && !m) break;
        used.assign(n+1, 0);
        for (int i=0 ; i < m; i++) {
            int a, b, c;
            scanf(" %d %d %d", &a, &b, &c);
            edges.pb(mp(c-1, mp(a,b)));
        }
        Kruskal(n);

        // for (int i = 1; i <= n; i++) {
        //     cout << i << "-> ";
        //     for (int j = 0; j < (int) maximum_tree[i].size(); j++) {
        //         cout << "(" << maximum_tree[i][j].fi << ", " << maximum_tree[i][j].sc << ") ";
        //     }
        //     cout << endl;
        // }

        int from, p;
        scanf(" %d %d %d", &from, &go, &p);
        double ans = ceil((double) p / (double) dfs(from));
        cout << "Scenario #" << ++caso << endl;
        cout << "Minimum Number of Trips = " << ans << endl<< endl;
    }
}
