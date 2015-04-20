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
#define MAX_N 100040

#define left(x) (x << 1)
#define right(x) ((x<<1) + 1)
#define pai(x) x/2
#define mid(a, b) ((a + b) >> 1)


/**
*** Timus - 1846. GCD 2010
*** http://acm.timus.ru/problem.aspx?space=1&num=1846
*** Tag: Segment Tree
*** Author: Gustavo Monteiro Alves - GustavoMA
**/
int gcd(int a, int b) {
    if(b==0) return a;
    return gcd(b, a % b);
}

int tree[4*MAX_N];

int arr[MAX_N];
int flag[MAX_N];

int n;

void update_segtree(int i, int k, int node=1, int l=1, int r=n) {
    //printf("node %d l %d r %d\n",node, l, r);
    //Out of range
    if (i > r || i < l) return;
    //In range
    if (r == l) {
        tree[node] = (k == 1) ? arr[i] : 0;
        return;   
    }
    update_segtree(i, k, left(node),  l, mid(l, r) );
    update_segtree(i, k, right(node), mid(l,r)+1, r);

    tree[node] = gcd(tree[left(node)], tree[right(node)]);   
}

int read_int() {
    char c;
    int result=0;
    
    do c = getchar();
    while(c < '0' or c > '9');
    
    do {
        result = result*10 + c-'0';
        c = getchar();
    } while(c >= '0' and c <= '9');
    
    return result;
}

void print_int(int x) {
    int inverse=0, zeroes=0;
    
    while(x%10==0) {
        x /= 10;
        zeroes++;
        if(x == 0)
            break;
    }
    
    while(x > 0) {
        inverse = inverse*10 + x%10;
        x /= 10;
    }
    
    while(inverse > 0) {
        putchar('0'+inverse%10);
        inverse /= 10;
    }
    
    while(zeroes--) putchar('0');
    putchar('\n');
}

map<int, int> T;
int queries[MAX_N];

int main() {
    int k;
    scanf(" %d", &k);
    
    n = 0;
    for (int i = 0; i < k; i++) {
        char c; int num;
        
        do c = getchar(); 
        while(c == '\n' || c == ' ');

        num = read_int();
        //scanf(" %c %d", &c, &num);
        //printf("llll %c\n", c);
        if (!T[num]) {
            T[num] = ++n;
            arr[n] = num;
        }
        queries[i] = (c == '+') ? num : -num;
    }

    for (int i = 0; i < k; i++) {
        int num = abs(queries[i]);

        if (queries[i] > 0) {
            if (flag[T[num]] == 0) update_segtree(T[num], 1);
            flag[T[num]]++;
        } else {
            if (flag[T[num]] == 1) update_segtree(T[num], -1);
            flag[T[num]]--;
        }
        print_int(tree[1] == 0 ? 1 : tree[1]);
        //printf("%d\n", tree[1] == 0 ? 1 : tree[1]);
    }
}