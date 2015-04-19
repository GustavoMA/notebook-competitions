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
#define MAX_N 100010
#define MAX_M 100
#define MOD 1000000007
#define EPS 1e-4

#define left(x) x*2
#define right(x) x*2 + 1
#define pai(x) x/2
#define mid(a, b) (a + b)/2

/**
*** URI - 1301 Produto do Intervalo
*** https://www.urionlinejudge.com.br/judge/pt/problems/view/1301
*** Tag: Seg Tree
*** Author: Gustavo Monteiro Alves - GustavoMA
**/


// Segtree starting from 1 to n
int tree[4*MAX_N];
int arr[MAX_N];
int n;
void build_segtree(int node, int l, int r) {
    if (l == r) {
        tree[node] = (arr[l] == 0) ? 0 : ((arr[l] > 0) ? 1 : -1);
        return;
    }
    build_segtree(left(node),  l, mid(l, r));
    build_segtree(right(node), mid(l,r)+1, r);
    tree[node] = tree[left(node)] * tree[right(node)];
}

void update_segtree(int node, int l, int r, int i) {
    if (i > r || i < l) return;
    if (i == r && i == l) {
        tree[node] = (arr[l] == 0) ? 0 : ((arr[l] > 0) ? 1 : -1);
        return;   
    }
    update_segtree(left(node),  l, mid(l, r) , i);
    update_segtree(right(node), mid(l,r)+1, r, i);
    tree[node] = tree[left(node)] * tree[right(node)];   
}

int query_segtree(int node, int l, int r, int i, int j) {
    if (i > r || j < l) return 1;
    if (l >= i && r <= j) return tree[node];

    int l_query = query_segtree(left(node) ,     l     , mid(l, r), i, j);
    int r_query = query_segtree(right(node), mid(l,r)+1,    r     , i, j);

    return l_query * r_query;        
 }

int main() {    
    int k;
    while (scanf(" %d %d", &n, &k) != EOF) {
        for (int i = 1; i <= n; i++) scanf(" %d", &arr[i]);
        build_segtree(1, 1, n);
        for (int i = 0; i < k; i++) {
            char c;
            int a, b;
            scanf(" %c %d %d", &c, &a, &b);
            if (c == 'C') {
                arr[a] = b;
                update_segtree(1, 1, n, a);
            } else {
                int val = query_segtree(1, 1, n, a, b);
                //printf("%d\n",  val);
                if (val == 0) printf("0");
                else if (val < 0) printf("-");
                else if (val > 0) printf("+");
            }
        }
        printf("\n");
    }
    return 0;
}
