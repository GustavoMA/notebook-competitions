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
#define MAX_N 55
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-4

/**
*** UVa - 336 - A Node Too Far
*** http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=272
*** Tag: Floyd-Marshall
*** Author: Gustavo Monteiro Alves - GustavoMA
**/

/**
*** Floyd Marshall algorithm
*** Author: Gustavo Monteiro Alves - GustavoMA
*** Matrix of adj. starting from 1 to n
**/

int m_adj[MAX_N][MAX_N];

void pre_process(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1 ; j <= n; j++) {
            m_adj[i][j] = (i == j) ? 0 : INF;
        }
    }
}

void floyd_marshall(int n) {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j<= n; j++)
                m_adj[i][j] = min(m_adj[i][j], m_adj[i][k] + m_adj[k][j]);
}

map<int, int> M;

int main() {
    int caso = 1;
    while (true) {
        int t = 1;
        M.clear();
        int r;
        scanf(" %d", &r);
        if(!r) break;
        pre_process(30);
        for (int i = 0; i < r; i++) {
            int a, b;
            scanf(" %d %d", &a, &b);
            if (M[a] == 0) {
                M[a] = t++;
            }
            if (M[b] == 0) {
                M[b] = t++;
            }
            m_adj[M[a]][M[b]] = min(m_adj[M[a]][M[b]], 1);
            m_adj[M[b]][M[a]] = min(m_adj[M[b]][M[a]], 1);
        }
        floyd_marshall(t-1);
        while(true) {
            int a, b;
            scanf(" %d %d", &a, &b);
            if (!a && !b) break;
            int tot = 0;
            for (int i = 1; i <= t-1; i++) {
                //cout << "i= " << i << endl;
                if (m_adj[M[a]][i] > b) tot++;
            }
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", caso++, tot, a, b);
        }
    }
}
