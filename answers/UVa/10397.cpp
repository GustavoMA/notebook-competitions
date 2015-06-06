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
*** UVa - 10397 - Connect the Campus
*** http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1338
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

vector<pair<double, ii> > edges;
double Kruskal(int n) {
    sort(edges.begin(), edges.end());
    //reverse(edges.begin(), edges.end());
    double tot = 0;
    for (int i = 0; i < (int) edges.size(); i++) {
        int v = edges[i].sc.fi;
        int u = edges[i].sc.sc;
        double w = edges[i].fi;
        if (!is_same_set(v, u)) {
            tot += w;
            union_set(v, u);
        }
    }
    return tot;
}

ii nodes[MAX_N];

inline double hypot(double dx, double dy) {
    return sqrt(dx*dx + dy*dy);
}
double dist_2d(ii p1, ii p2) {
    return hypot((double) (p1.fi - p2.fi), (double) (p1.sc - p2.sc));
}

int main() {
    int n;
    while (scanf(" %d" , &n) != EOF) {
        edges.clear();
        for (int i = 1; i <= n; i++) {
            scanf(" %d %d", &nodes[i].fi, &nodes[i].sc);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;
                edges.pb(mp(dist_2d(nodes[i], nodes[j]), mp(i,j)));
            }
        }
        int k;
        scanf(" %d", &k);
        build_union_find(n);
        for (int i = 0; i < k; i++) {
            int a, b;
            scanf(" %d %d", &a, &b);
            union_set(a, b);
        }
        double mn = Kruskal(n);
        printf("%.2lf\n", mn);
    }
}
