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
#define MAX_N 110
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-4

/**
*** UVa - 821 - Page Hopping
*** http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=762
*** Tag: Floyd-Marshall
*** Author: Gustavo Monteiro Alves - GustavoMA
**/

set<int> nodes;
set<int>::iterator it;
set<int>::iterator jt;

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
    int a, b, c=0;
    while(true) {
        pre_process(101);
        nodes.clear();
        scanf(" %d %d", &a, &b);
        if (!a  && !b) break;
        nodes.insert(a);
        nodes.insert(b);
        m_adj[a][b] = 1;
        while(true) {
            scanf(" %d %d", &a, &b);
            if (!a && !b) break;
            m_adj[a][b] = 1;
            nodes.insert(a);
            nodes.insert(b);
        }
        floyd_marshall(101);
        double pairs = (double) (nodes.size() * (nodes.size() - 1));
        double sum = 0;
        for (it = nodes.begin(); it != nodes.end(); it++) {
            int v = *it;
            for (jt = nodes.begin(); jt != nodes.end(); jt++) {
                int u = *jt;
                sum += (m_adj[v][u] <= INF) ? (double) m_adj[v][u] : 0;
            }
        }
        double val = sum/pairs;
        printf("Case %d: average length between pages = %.3lf clicks\n", ++c, val);
        //  cout << pairs << " " << sum << endl;
    }
    return 0;
}
