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

//read files 
//freopen ("in.txt", "r", stdin);
//freopen ("out.txt","w", stdout);

#define left(x) x*2
#define right(x) x*2 + 1
#define pai(x) x/2
#define mid(a, b) (a + b)/2

/**
*** SPOJ - TOPOLAND - To Poland
*** http://www.spoj.com/problems/TOPOLAND/
*** Tag: Segment Tree
*** Author: Gustavo Monteiro Alves - GustavoMA
**/
int tree[4*MAX_N];
int arr[MAX_N];
int n;
void build_segtree(int node=1, int l=1, int r=n) {
    if (l == r) {
        tree[node] = arr[l];
        return;
    }
    build_segtree(left(node),  l, mid(l, r));
    build_segtree(right(node), mid(l,r)+1, r);
    tree[node] = max(tree[left(node)],tree[right(node)]);
}

void update_segtree(int i, int node=1, int l=1, int r=n) {
    //Out of range
    if (i > r || i < l) return;
    //In range
    if (i == r && i == l) {
        tree[node] = arr[l];
        return;   
    }
    update_segtree(i, left(node),  l, mid(l, r) );
    update_segtree(i, right(node), mid(l,r)+1, r);
    tree[node] = max(tree[left(node)], tree[right(node)]);   
}

int query_segtree(int i, int j, int node=1, int l=1, int r=n) {
    //Out of range, use neutral element or a flag
    if (i > r || j < l) return 0;
    //Totally in range
    if (l >= i && r <= j) return tree[node];

    int l_query = query_segtree(i, j, left(node) ,     l     , mid(l, r));
    int r_query = query_segtree(i, j, right(node), mid(l,r)+1,    r     );

    return max(l_query, r_query);        
 }

 int main() {
    int t, caso = 0;
    scanf(" %d", &t);
    while(t--) {
        printf("Testcase %d:\n", caso++);
        int m;
        scanf(" %d %d", &n, &m);
        for (int i = 1; i <= n; i++) scanf(" %d", &arr[i]);
        build_segtree();
        int q;
        scanf(" %d", &q);
        for (int j = 0; j < q; j++) {
            char a;
            scanf(" %c", &a);
            if (a == 'A') {
                int b;
                scanf(" %d", &b);
                m += b;
            } else {
                int b, c;
                scanf(" %d %d", &b, &c);
                if (a == 'B') {
                    arr[++b] = c;
                    update_segtree(b);
                } else {
                    int val = query_segtree(++b, ++c);
                    //printf("%d %d %d\n", a, b, val);
                    printf("%d\n", abs(val - m));
                }
            }
        }
        printf("\n");
    }
}