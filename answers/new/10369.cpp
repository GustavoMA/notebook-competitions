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
*** UVa - 10369 - Arctic Network
*** http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1310
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

vector<pair<double, ii> > edges;
double Kruskal(int n, int s) {
    build_union_find(n);
    sort(edges.begin(), edges.end());
    //reverse(edges.begin(), edges.end());
    double tot = 0;
    int dis = n;
    //cout << "DEBUG " <<  edges.size() << endl;
    for (int i = 0; i < (int) edges.size(); i++) {
        int v = edges[i].sc.fi;
        int u = edges[i].sc.sc;
        double w = edges[i].fi;
        //cout << "v " << v << " u " << u << endl;
        //cout << "w " << w << endl;
        if (!is_same_set(v, u)) {
            tot += w;
            union_set(v, u);
            dis--;
        }
        if (dis == s) break;
    }
    return tot;
}

inline double hypot(double dx, double dy) {
    return sqrt(dx*dx + dy*dy);
}
double dist_2d(ii p1, ii p2) {
    return hypot((double)(p1.fi - p2.fi), (double)(p1.sc - p2.sc));
}

ii nodes[MAX_N];

int main() {
    int t;
    scanf(" %d", &t);
    for (int _t = 0; _t<t; _t++) {
        edges.clear();
        int s, n;
        scanf(" %d %d", &s, &n);
        for (int i = 0; i < n; i++) {
            scanf(" %d %d", &nodes[i].fi, &nodes[i].sc);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                edges.pb(mp(dist_2d(nodes[i], nodes[j]) ,mp(i, j)));
            }
        }
        double mn = Kruskal(n, s);
        printf("%lf\n", mn);
    }
}
