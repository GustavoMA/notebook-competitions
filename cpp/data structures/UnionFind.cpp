/**
*** Union Find without classes
*** Author: Gustavo Monteiro Alves - GustavoMA
**/
int p[MAX_N], rank[MAX_N], size[MAX_N];

// O(n)
inline void build_union_find() {
	for (int i = 0; i < n; i++) {
		p[i] = i;
		rank[i] = 0;
		size[i] = 1;
	}
}
// ~O(log n)
int find(int n) {
	return (p[n] == n) ? n : (p[n] = find(p[n]));
}
// O(1)
bool is_same_set(int i, int j) {
	return find(i) == find(j);
}
// ~O(log n)
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
// ~O(log n)
int size(int n) {
	return size[find(n)];
}
