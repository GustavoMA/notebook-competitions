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
#define INF 2000000000
#define MAX_N 100100

/**
*** UVA 11503 - Virtual Friends
*** http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2498
*** Author: Gustavo Monteiro Alves - GustavoMA
**/

/**
*** Class to represent a Union Find structure
*** Author: Gustavo Monteiro Alves - GustavoMA
**/
class Union_Find {
	
public:
	int p[MAX_N], rank[MAX_N], size[MAX_N];

	// Constructor
	// O(n)
	Union_Find(int n) {
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
	int set_size(int n) {
		return size[find(n)];
	}
};




int main() {
	int k;
	scanf(" %d", &k);
	while(k--) {
		int n;
		Union_Find UF(MAX_N);
		map<string, int> M;

		scanf(" %d", &n);

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			string a, b;
			cin >> a >> b;
			int x = (M[a] == 0) ? M[a] = ++cnt : M[a];
			int y = (M[b] == 0) ? M[b] = ++cnt : M[b];
			UF.union_set(x, y);
			printf("%d\n", UF.set_size(x));
		}
	}
}

