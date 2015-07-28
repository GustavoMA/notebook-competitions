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
*** Codeforces - D. The Child and Zoo
*** http://codeforces.com/problemset/problem/437/D
*** Tag: Sorting, Union Find
*** Author: Gustavo Monteiro Alves - GustavoMA
**/

//Union Find
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

struct edge {
    int u, v, w;
    const bool operator<(edge other) const {
        return w > other.w;
    }
};

edge edges[MAX_N];
int a[MAX_N];

int main(int argc, char const *argv[]) {
    int n, m;
    scanf(" %d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf(" %d", &a[i]);
    }
    build_union_find(n);
    for (int i = 0; i < m; i++) {
        int x,y;
        scanf(" %d %d", &x, &y);
        edges[i].u = x;
        edges[i].v = y;
        edges[i].w = min(a[x],a[y]);
    }
    sort(edges, edges+m);
    double ans = 0.0;
    for (int i = 0; i < m; i++) {
        if(!is_same_set(edges[i].u, edges[i].v)) {
            ans += (double) union_size(edges[i].u) * (double) union_size(edges[i].v) * (double) edges[i].w;
            union_set(edges[i].u, edges[i].v);
        }
    }
    printf("%.6lf\n", ((2 * ans) / ((double) n * (double)(n - 1))) );
    return 0;
}
