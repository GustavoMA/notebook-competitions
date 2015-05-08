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
#define MAX_M 10
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-4

/**
*** UVa - 10801 - Lift Hopping
*** uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1742
*** Tag: Dijkstra
*** Author: Gustavo Monteiro Alves - GustavoMA
**/
int m_adj[MAX_N][MAX_N];
int dist[MAX_N];
int T[MAX_M];

void pre_process() {
    for (int i = 0; i <= 99; i++) {
        dist[i] = INF;
        for (int j = 0; j <= 99; j++) {
            m_adj[i][j] = INF;
        }
    }
}

priority_queue<ii, vector<ii>, greater<ii> > PQ;

int Dijkstra(int root) {
    dist[root] = 0;
    PQ.push(ii(0, root));
    while(!PQ.empty()) {
        int v = PQ.top().sc;
        int di = PQ.top().fi;
        PQ.pop();
        //cout << v << endl;
        if (di > dist[v]) continue;
        for (int u = 0; u <= 99; u++) {
            //if (m_adj[v][u] >= INF) continue;

            int d = m_adj[v][u];
            if (d + dist[v] < dist[u]) {
                dist[u] = d + dist[v];
                PQ.push(ii(dist[u], u));
            }
        }
    }
}

int main() {
    int n, k;
    while(scanf("%d %d\n", &n, &k) != EOF) {
        pre_process();
        for (int i = 0; i < n; i++) scanf(" %d", &T[i]);
        scanf("\n");
        for (int i = 0; i < n; i++) {
            string a;
            getline(cin, a);
            stringstream ss;
            ss << a;
            vi aps;
            int ap;
            while(ss >> ap) {
                aps.pb(ap);
            }
            for (int k = 0; k < aps.size(); k++) {
                for (int j = 0; j < aps.size(); j++) {
                    if (k == j) continue;
                    m_adj[aps[k]][aps[j]] = min(m_adj[aps[k]][aps[j]], abs(aps[k]-aps[j])*T[i] + 60);
                }
            }
        }

        Dijkstra(0);
        if (dist[k] >= INF) {
            printf("IMPOSSIBLE\n");
        } else if (k == 0) {
            printf("%d\n", 0);
        } else {
            printf("%d\n", dist[k] - 60);
        }
    }
}
