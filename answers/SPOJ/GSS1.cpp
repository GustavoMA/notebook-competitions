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
*** SPOJ - GSS1 - Can you answer these queries I
*** http://www.spoj.com/problems/GSS1/
*** Tip: https://kartikkukreja.wordpress.com/2014/11/09/a-simple-approach-to-segment-trees/
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

/**
*** Segment Tree
*** Author: Gustavo Monteiro Alves - GustavoMA
*** Segtree starting from 1 to n
**/
struct Node {
    int prefixMaxSum, suffixMaxSum, maxSum, sum;
    bool flag;
    
    void assignLeaf(int val) {
        prefixMaxSum = suffixMaxSum = maxSum = sum = val;
        flag = false;
    } 

    void flagNode() {
        flag = true;
    }

    void merge(Node& left, Node& right) {
        sum = left.sum + right.sum;
        prefixMaxSum = max(left.prefixMaxSum, left.sum + right.prefixMaxSum);  
        suffixMaxSum = max(right.suffixMaxSum, right.sum + left.suffixMaxSum);
        maxSum = max(prefixMaxSum, max(suffixMaxSum, max(left.maxSum, max(right.maxSum, left.suffixMaxSum + right.prefixMaxSum))));
        flag = false;    
    }

    int getValue() {
        return maxSum;
    }
};

Node tree[4*MAX_N];
int arr[MAX_N];
int n;

void build_segtree(int node=1, int l=1, int r=n) {
    if (l == r) {
        tree[node].assignLeaf(arr[l]);
        return;
    }
    
    build_segtree(left(node),  l, mid(l, r));
    build_segtree(right(node), mid(l,r)+1, r);
    
    tree[node].merge(tree[left(node)], tree[right(node)]);
}

Node query_segtree(int i, int j, int node=1, int l=1, int r=n) {
    //Out of range, use neutral element or a flag
    if (i > r || j < l) {
        Node ret;
        ret.flagNode();
        return ret;
    }
    //Totally in range
    if (l >= i && r <= j) return tree[node];

    Node l_query = query_segtree(i, j, left(node) ,     l     , mid(l, r));
    Node r_query = query_segtree(i, j, right(node), mid(l,r)+1,    r     );

    if (l_query.flag && r_query.flag) return l_query;
    if (l_query.flag) return r_query;
    if (r_query.flag) return l_query;

    Node ret;
    ret.merge(l_query, r_query);

    return ret;        
 }

 int main() {
    scanf(" %d", &n);
    for (int i = 1; i <= n; i++) scanf(" %d", &arr[i]);
    build_segtree();
    int k;
    scanf(" %d", &k);
    for (int i = 0; i < k; i++) {
        int a, b;
        scanf(" %d %d", &a, &b);
        printf("%d\n", query_segtree(min(a,b),max(a,b)).getValue());
    }
 }