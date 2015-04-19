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

#define left(x) x*2
#define right(x) x*2 + 1
#define pai(x) x/2
#define mid(a, b) (a + b)/2

/**
*** Segment Tree of sum without classes
*** Author: Gustavo Monteiro Alves - GustavoMA
*** Segtree starting from 1 to n
**/
int tree[4*MAX_N];
int arr[MAX_N];
int n;
void build_segtree(int node, int l, int r) {
    if (l == r) {
        tree[node] = arr[l];
        return;
    }
    build_segtree(left(node),  l, mid(l, r));
    build_segtree(right(node), mid(l,r)+1, r);
    tree[node] = tree[left(node)] + tree[right(node)];
}

void update_segtree(int node, int l, int r, int i) {
    //Out of range
    if (i > r || i < l) return;
    //In range
    if (i == r && i == l) {
        tree[node] = arr[l];
        return;   
    }
    update_segtree(left(node),  l, mid(l, r) , i);
    update_segtree(right(node), mid(l,r)+1, r, i);
    tree[node] = tree[left(node)] + tree[right(node)];   
}

int query_segtree(int node, int l, int r, int i, int j) {
    //Out of range, use neutral element or a flag
    if (i > r || j < l) return 0;
    //Totally in range
    if (l >= i && r <= j) return tree[node];

    int l_query = query_segtree(left(node) ,     l     , mid(l, r), i, j);
    int r_query = query_segtree(right(node), mid(l,r)+1,    r     , i, j);

    return l_query + r_query;        
 }
