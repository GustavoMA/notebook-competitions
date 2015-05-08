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
#define MAX_N 510
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-4

/**
*** URI - 1148 - Países em Guerra
*** https://www.urionlinejudge.com.br/judge/pt/problems/view/1148
*** Tag: Floyd Marshall
*** Author: Gustavo Monteiro Alves - GustavoMA
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

int pos_process(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1 ; j <= n; j++) {
            if (m_adj[i][j] != INF && m_adj[j][i] != INF) {
                m_adj[i][j] = 0;
                m_adj[j][i] = 0;
            }
        }
    }
}

int main() {
    while(true) {
        int n, e;
        scanf(" %d %d", &n, &e);
        if (!n && !e) break;
        pre_process(n);
        for (int i = 1; i <= e; i++) {
            int x, y, h;
            scanf(" %d %d %d", &x, &y, &h);
            m_adj[x][y] = h;
        }
        pos_process(n);
        floyd_marshall(n);
        int k;
        scanf(" %d", &k);
        for (int i = 0; i < k; i++) {
            int x, y;
            scanf(" %d %d", &x, &y);
            if (m_adj[x][y]>=INF) {
                printf("Nao e possivel entregar a carta\n");
            } else {
                cout << m_adj[x][y] << endl;
            }
        }
        cout << endl;
    }
}
