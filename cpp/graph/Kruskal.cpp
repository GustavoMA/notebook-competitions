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
int Kruskal(int n) {
    build_union_find(n);
    sort(edges.begin(), edges.end());
	//reverse(edges.begin(), edges.end());
    int tot = 0;
    for (int i = 0; i < (int) edges.size(); i++) {
        int v = edges[i].sc.fi;
        int u = edges[i].sc.sc;
        int w = edges[i].fi;
        if (!is_same_set(v, u)) {
            tot += w;
            union_set(v, u);
        }
    }
    return tot;
}
