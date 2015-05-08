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
*** UVa - 1056 - Degrees of Separation
*** http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3497
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

map<string, int> M;

int main() {
    int p, r, caso = 0;
    while(true) {
        M.clear();
        int c = 1;
        scanf(" %d %d", &p, &r);
        if (!p && !r) break;
        pre_process(p);
        for (int i = 0; i < r; i++) {
            string a, b;
            cin >> a >> b;
            if (M[a] == 0) M[a] = c++;
            if (M[b] == 0) M[b] = c++;

            m_adj[M[a]][M[b]] = 1;
            m_adj[M[b]][M[a]] = 1;
        }
        floyd_marshall(p);
        int mx = -INF;
        for (int i = 1; i <= p; i++) {
            for (int j = 1; j <= p; j++) {
                if (i == j) continue;
                mx = max(mx, m_adj[i][j]);
            }
        }
        if (mx >= INF) {
            printf("Network %d: DISCONNECTED\n\n", ++caso);
        } else {
            printf("Network %d: %d\n\n", ++caso, mx);
        }
    }
}
