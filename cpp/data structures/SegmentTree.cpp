/**
*** Segment Tree of sum without classes
*** Author: Gustavo Monteiro Alves - GustavoMA
*** Segtree starting from 1 to n
**/
#define left(x) x*2
#define right(x) x*2 + 1
#define pai(x) x/2
#define mid(a, b) (a + b)/2

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
    tree[node] = tree[left(node)] + tree[right(node)];
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
    tree[node] = tree[left(node)] + tree[right(node)];
}

int query_segtree(int i, int j, int node=1, int l=1, int r=n) {
    //Out of range, use neutral element or a flag
    if (i > r || j < l) return 0;
    //Totally in range
    if (l >= i && r <= j) return tree[node];

    int l_query = query_segtree(i, j, left(node) ,     l     , mid(l, r));
    int r_query = query_segtree(i, j, right(node), mid(l,r)+1,    r     );

    return l_query + r_query;
 }
