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
*** SPOJ - KGSS - Maximum Sum
*** http://www.spoj.com/problems/KGSS/
*** Tag: Segment Tree
*** Author: Gustavo Monteiro Alves - GustavoMA
**/

struct Node {
    int max1;
    int max2;
};

// Segtree starting from 1 to n
Node tree[4*MAX_N];
int arr[MAX_N];
int n;

void build_segtree(int node, int l, int r) {
    if (l == r) {
        tree[node].max1 = arr[l];
        tree[node].max2 = -1;
        return;
    }

    build_segtree(left(node),  l, mid(l, r));
    build_segtree(right(node), mid(l,r)+1, r);
    
    tree[node].max1 = max(tree[left(node)].max1 , tree[right(node)].max1);

    int min_max1 = min(tree[left(node)].max1 , tree[right(node)].max1);
    int max_max2 = max(tree[left(node)].max2 , tree[right(node)].max2);
    
    tree[node].max2 = max(min_max1, max_max2);    
}

void update_segtree(int node, int l, int r, int i) {
    if (i > r || i < l) return;
    if (i == r && i == l) {
        tree[node].max1 = arr[l];
        tree[node].max2 = -1;
        return;   
    }

    update_segtree(left(node),  l, mid(l, r) , i);
    update_segtree(right(node), mid(l,r)+1, r, i);

    tree[node].max1 = max(tree[left(node)].max1 , tree[right(node)].max1);

    int min_max1 = min(tree[left(node)].max1 , tree[right(node)].max1);
    int max_max2 = max(tree[left(node)].max2 , tree[right(node)].max2);
    tree[node].max2 = max(min_max1, max_max2); 
}

Node query_segtree(int node, int l, int r, int i, int j) {
    if (i > r || j < l) {
        Node a;
        a.max1 = -1;
        a.max2 = -1;
        return a;
    }
    
    if (l >= i && r <= j) return tree[node];

    Node l_query = query_segtree(left(node) ,     l     , mid(l, r), i, j);
    Node r_query = query_segtree(right(node), mid(l,r)+1,    r     , i, j);

    Node ret;

    ret.max1 = max(l_query.max1, r_query.max1);

    int min_max1 = min(l_query.max1, r_query.max1);
    int max_max2 = max(l_query.max2, r_query.max2);

    ret.max2 = max(min_max1, max_max2);

    return ret;        
 }

int main() {    
    scanf(" %d", &n);
    for (int i = 1; i <= n; i++) scanf(" %d", &arr[i]);
    build_segtree(1,1,n);
    int k;
    scanf(" %d", &k);
    while(k--) {
        char a;
        int b, c;
        scanf(" %c %d %d", &a, &b, &c);

        /*for (int i = 1; i < 20; i++) {
            printf("Node %d: %d %d\n", i, tree[i].max1, tree[i].max2);
        }*/

        if (a == 'U') {
            arr[b] = c;
            update_segtree(1, 1, n, b);
        } else {
            Node no = query_segtree(1, 1, n, b, c);
            int suma = no.max1 + no.max2;
            printf("%d\n", suma);
        }
    }    
    return 0;
}
