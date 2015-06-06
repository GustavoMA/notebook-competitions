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
*** UVa - 11733 - Airports
*** http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2833
*** Tag: Minimum Spanning Tree
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
int dis;
int Kruskal(int n) {
    build_union_find(n);
    dis = n;
    sort(edges.begin(), edges.end());
    int mn = 0;
    for (int i = 0; i < (int) edges.size(); i++) {
        int v = edges[i].sc.fi;
        int u = edges[i].sc.sc;
        int w = edges[i].fi;
        if (!is_same_set(v, u)) {
            mn += w;
            union_set(v, u);
            dis--;
        }
    }
    return mn;
}

int main() {
    int t;
    scanf(" %d", &t);
    for (int _t = 1; _t <= t; _t++) {
        edges.clear();
        int n, m, a;
        scanf(" %d %d %d", &n, &m, &a);
        for (int i = 0; i < m; i++) {
            int u, v, w;
            scanf(" %d %d %d", &u, &v, &w);
            if(w < a) edges.pb(mp(w, mp(u,v)));
        }
        int mn = Kruskal(n) + dis * a;
        printf("Case #%d: %d %d\n", _t, mn, dis);
    }
}
