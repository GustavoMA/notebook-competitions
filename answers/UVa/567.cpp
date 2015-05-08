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
#define MAX_N 22
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-4

/**
*** UVa - 567 - Risk
*** http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=508
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

int main() {
    int k, caso = 1;
    while (scanf(" %d", &k) != EOF) {
        pre_process(20);
        for (int i = 0; i < k; i++) {
            int a;
            scanf(" %d", &a);
            m_adj[1][a] = 1;
            m_adj[a][1] = 1;
        }
        for (int i = 2; i <= 19; i++) {
            scanf(" %d", &k);
            for (int j = 0; j < k; j++) {
                int a;
                scanf(" %d", &a);
                m_adj[i][a] = 1;
                m_adj[a][i] = 1;
            }
        }
        floyd_marshall(20);
        int n;
        scanf(" %d", &n);
        printf("Test Set #%d\n", caso++);
        for (int i = 0; i < n; i++) {
            int g1, g2;
            scanf(" %d %d", &g1, &g2);
            printf("%2d to %2d: %d\n", g1, g2, m_adj[g1][g2]);
        }
        printf("\n");
    }
}
