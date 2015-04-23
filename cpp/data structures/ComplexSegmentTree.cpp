/**
*** Complex Segment Tree of sum without classes
*** Author: Gustavo Monteiro Alves - GustavoMA
*** Segtree starting from 1 to n
**/
#define left(x) x*2
#define right(x) x*2 + 1
#define pai(x) x/2
#define mid(a, b) (a + b)/2

struct Node {
    int value;
    bool flag;

    void leaf(int val) {
        value = val;
        flag = false;
    }

    void flag_leaf() {
        flag = true;
    }

    void merge(Node& left, Node& right) {
        value = left.value + right.value;
        flag = false;
    }

    int get_value() {
        return value;
    }
};

Node tree[4*MAX_N];
int arr[MAX_N];
int n;
void build_segtree(int node=1, int l=1, int r=n) {
    if (l == r) {
        tree[node].leaf(arr[l]);
        return;
    }
    build_segtree(left(node),  l, mid(l, r));
    build_segtree(right(node), mid(l,r)+1, r);
    tree[node].merge(tree[left(node)], tree[right(node)]);
}

void update_segtree(int i, int node=1, int l=1, int r=n) {
    //Out of range
    if (i > r || i < l) return;
    //In range
    if (i == r && i == l) {
        tree[node].leaf(arr[l]);
        return;
    }
    update_segtree(i, left(node),  l, mid(l, r) );
    update_segtree(i, right(node), mid(l,r)+1, r);
    tree[node].merge(tree[left(node)], tree[right(node)]);
}

Node query_segtree(int i, int j, int node=1, int l=1, int r=n) {
    if (i > r || j < l) {
        Node no;
        no.flag_leaf();
        return no;
    }
    if (l >= i && r <= j) return tree[node];

    Node l_query = query_segtree(i, j, left(node) ,     l     , mid(l, r));
    Node r_query = query_segtree(i, j, right(node), mid(l,r)+1,    r     );

    if (l_query.flag && r_query.flag) return l_query;
    if (l_query.flag) return r_query;
    if (r_query.flag) return l_query;

    Node no;
    no.merge(l_query, r_query);
    return no;
}
