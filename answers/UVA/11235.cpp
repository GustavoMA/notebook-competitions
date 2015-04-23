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
#define MAX_N 500100
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-4

/**
*** UVA - 11235 - Frequent values
*** http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2176
*** Tip: http://www.algorithmist.com/index.php/UVa_11235
*** Tip2: http://niceproblems.blogspot.com.br/2012/05/uva-11235-frequent-values.html
*** Tag: Segment Tree
*** Author: Gustavo Monteiro Alves - GustavoMA
**/

//read files 
//freopen ("in.txt", "r", stdin);
//freopen ("out.txt","w", stdout);

#define left(x) x*2
#define right(x) x*2 + 1
#define pai(x) x/2
#define mid(a, b) (a + b)/2

int tree[4*MAX_N];
int arr[MAX_N];
int cnt[MAX_N];
int start[MAX_N];
int n;
void build_segtree(int node=1, int l=1, int r=n) {
    if (l == r) {
        tree[node] = cnt[arr[l]];
        return;
    }
    build_segtree(left(node),  l, mid(l, r));
    build_segtree(right(node), mid(l,r)+1, r);
    tree[node] = max(tree[left(node)], tree[right(node)]);
}

int query_segtree(int i, int j, int node=1, int l=1, int r=n) {
    //Out of range, use neutral element or a flag
    if (i > r || j < l) return -INF;
    //Totally in range
    if (l >= i && r <= j) return tree[node];

    int l_query = query_segtree(i, j, left(node) ,     l     , mid(l, r));
    int r_query = query_segtree(i, j, right(node), mid(l,r)+1,    r     );

    return max(l_query, r_query);        
 }

 int main() {
    while(true) {
        memset(cnt, 0, sizeof cnt);
        memset(start, -1, sizeof start);
        
        scanf(" %d", &n);
        if (n==0) break;
        int q;
        scanf(" %d", &q);
        for (int i = 1; i <= n; i++) {
            scanf(" %d", &arr[i]);
            arr[i] += 100000;
            cnt[arr[i]] ++;
            if (cnt[arr[i]] == 1) start[arr[i]] = i;
        }
        build_segtree();
        for (int i = 0; i < q; i++) {
            int a, b;
            scanf(" %d %d", &a, &b);
            if (arr[a] == arr[b]) {
                printf("%d\n",b - a + 1);
            } else {
                int query1 = cnt[arr[a]] - a + start[arr[a]];
                int query2 = b - start[arr[b]] + 1;

                int new_a = start[arr[a]] + cnt[arr[a]];
                int new_b = start[arr[b]] - 1;

                int query3 = -INF;
                if (new_a <= new_b) query3 = query_segtree(new_a, new_b);
                int val = max(query1, max(query2, query3));
                printf("%d\n", val);
            }
        }
    }
    return 0;
 }