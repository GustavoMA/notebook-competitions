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
*** UVa - 10034 - Freckles
*** http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=975
*** Tag: Minimum spanning tree
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
double Kruskal(int n) {
    build_union_find(n);
    sort(edges.begin(), edges.end());
    double mn = 0;
    for (int i = 0; i < (int) edges.size(); i++) {
        int v = edges[i].sc.fi;
        int u = edges[i].sc.sc;
        double w = edges[i].fi;
        if (!is_same_set(v, u)) {
            mn += w;
            union_set(v, u);
        }
    }
    return mn;
}

inline double hypot(double dx, double dy) {
    return sqrt(dx*dx + dy*dy);
}
double dist_2d(pair<double, double> p1, pair<double, double> p2) {
    return hypot(p1.fi - p2.fi, p1.sc - p2.sc);
}

vector<pair<double, double> > points;
map<pair<double, double> , int> M;

int main() {
    int t;
    scanf(" %d", &t);

    while(t--) {
        //cout << t << endl;
        edges.clear();
        points.clear();
        M.clear();

        int n;
        scanf(" %d", &n);
        int l = 0;
        for (int i = 0; i < n; i++) {
            double a, b;
            scanf(" %lf %lf", &a, &b);
            pair<double,double> p = mp(a, b);
            points.pb(p);
            if (M[p] == 0) M[p] = l++;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                edges.pb(mp(dist_2d(points[i], points[j]) , mp(M[points[i]], M[points[j]])));
            }
        }
        double mn = Kruskal(l);
        printf("%.2lf\n", mn);
        if (t != 0) printf("\n");
    }
    return 0;
}
