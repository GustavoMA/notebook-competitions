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
#define MAX_N 10100
#define MOD 1000000007

/**
*** Codeforces 217 - A. Ice Skating
*** http://codeforces.com/problemset/problem/217/A
*** Author: Gustavo Monteiro Alves - GustavoMA
**/

/**
*** Union Find without classes
*** Author: Gustavo Monteiro Alves - GustavoMA
**/
int p[MAX_N], rank[MAX_N], size[MAX_N];
int n;
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
int set_size(int n) {
    return size[find(n)];
}

vii pairs;
set<int> components;

int main() {
    scanf(" %d", &n);
    build_union_find();
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf(" %d %d", &x, &y);
        pairs.pb(mp(x, y));
    }
    
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            if (i != j) 
                if (pairs[i].fi == pairs[j].fi ||
                    pairs[i].sc == pairs[j].sc    ){
                    union_set(i, j);
                }

    for (int i = 0; i < n; i++) 
        components.insert( find(i) );

    printf("%d\n", (int) (components.size()-1) ) ;
    return 0;
}