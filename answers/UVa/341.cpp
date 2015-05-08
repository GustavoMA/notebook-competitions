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
#define MAX_N 12
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-4

/**
*** UVa - 341 - Non-Stop Travel
*** http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=277
*** Tag: Floyd-Marshall
*** Author: Gustavo Monteiro Alves - GustavoMA
**/

/**
*** Floyd Marshall algorithm
*** Author: Gustavo Monteiro Alves - GustavoMA
*** Matrix of adj. starting from 1 to n
**/

int m_adj[MAX_N][MAX_N];
vi path[MAX_N][MAX_N];

void pre_process(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1 ; j <= n; j++) {
            m_adj[i][j] = (i == j) ? 0 : INF;
            path[i][j].clear();
            path[i][j].pb(i);
            path[i][j].pb(j);
        }
    }
}

void floyd_marshall(int n) {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j<= n; j++) {
                if (m_adj[i][k] + m_adj[k][j] < m_adj[i][j]) {

                    //cout << "DEBUG BEGIN" << endl;
                    //cout << "i = " << i << " j = " << j << endl;
                    //cout << path[i][j].size() << endl;
                    path[i][j].clear();
                    //cout << path[i][j].size() << endl;
                    path[i][j].insert(path[i][j].end(), path[i][k].begin(), path[i][k].end());
                    //cout << path[i][j].size() << endl;
                    path[i][j].insert(path[i][j].end(), path[k][j].begin()+1, path[k][j].end());
                    //cout << path[i][j].size() << endl;
                    //cout << "DEBUG END" << endl;
                }
                m_adj[i][j] = min(m_adj[i][j], m_adj[i][k] + m_adj[k][j]);
            }
}

int main() {
    int n, caso = 1;
    while(true) {
        scanf(" %d", &n);
        if (!n) break;
        pre_process(n   );
        for (int i = 1; i <= n; i++) {
            int e;
            scanf(" %d", &e);
            for (int j = 1; j <= e; j++) {
                int a, b;
                scanf(" %d %d", &a, &b);
                m_adj[i][a] = b;
            }
        }
        floyd_marshall(n);
        int a, b;
        scanf(" %d %d", &a, &b);
        printf("Case %d: Path =", caso++);
        for (int i = 0; i < path[a][b].size(); i++) {
            printf(" %d", path[a][b][i]);
        }
        printf("; %d second delay\n", m_adj[a][b]);
    }
}
