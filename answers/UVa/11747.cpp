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
#define MAX_N 1001
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-4

/**
*** UVa - 11747 - Heavy Cycle Edges
*** http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2847
*** Tag: Minimum Spanning Tree
*** Author: Gustavo Monteiro Alves - GustavoMA
**/

int p[MAX_N], rank[MAX_N], size[MAX_N];

inline void build_union_find(int n) {
	for (int i = 0; i < n; i++) {
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
vi ans;
int Kruskal(int n) {
    build_union_find(n);
    sort(edges.begin(), edges.end());
    int mn = 0;
    for (int i = 0; i < (int) edges.size(); i++) {
        int v = edges[i].sc.fi;
        int u = edges[i].sc.sc;
        int w = edges[i].fi;
        if (!is_same_set(v, u)) {
            mn += w;
            union_set(v, u);
        } else{
            ans.pb(w);
        }
    }
    return mn;
}

int main() {
    int m, n;
    while(1) {
        edges.clear();
        ans.clear();
        scanf(" %d %d", &n, &m);
        if (!n && !m) break;
        int tot = 0;
        for (int i = 0; i < m; i++) {
            int a, b, c;
            scanf(" %d %d %d", &a, &b, &c);
            tot += c;
            edges.pb(mp(c, mp(a,b)));
        }
        int mn = Kruskal(n);
        if (tot == mn) {
            printf("forest\n");
        } else {
            printf("%d", ans[0]);
            for (int i = 1; i < (int) ans.size(); i++) {
                //if (!used[i]) {
                    printf(" %d", ans[i]);
                //}
            }
            printf("\n");
        }
        //cout << tot << " " << mn << endl;
    }
}
