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
#define MAX_N 'Z' - 'A' + 1
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-4

/**
*** UVa - 10171 - Meeting Prof. Miguel...
*** http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1112
*** Tag: Floyd-Marshall
*** Author: Gustavo Monteiro Alves - GustavoMA
**/

int M_m_adj[MAX_N][MAX_N];
int Y_m_adj[MAX_N][MAX_N];


void pre_process(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0 ; j < n; j++) {
            M_m_adj[i][j] = (i == j) ? 0 : INF;
            Y_m_adj[i][j] = (i == j) ? 0 : INF;
        }
    }
}

void floyd_marshall(int n) {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                M_m_adj[i][j] = min(M_m_adj[i][j], M_m_adj[i][k] + M_m_adj[k][j]);
                Y_m_adj[i][j] = min(Y_m_adj[i][j], Y_m_adj[i][k] + Y_m_adj[k][j]);
            }
}

int main() {
    int r;
    while(true) {
        scanf(" %d", &r);
        if(!r) break;
        pre_process('Z' - 'A' + 1);
        for (int i = 0; i < r; i++) {
            char a, b, c, d;
            int e;
            scanf(" %c %c %c %c %d", &a, &b, &c, &d, &e);
            if (a == 'M') {
                if (b == 'U') M_m_adj[c - 'A'][d - 'A'] = min(e, M_m_adj[c - 'A'][d - 'A']);
                if (b == 'B'){
                    M_m_adj[c - 'A'][d - 'A'] = min(e, M_m_adj[c - 'A'][d - 'A']);
                    M_m_adj[d - 'A'][c - 'A'] = min(e, M_m_adj[c - 'A'][d - 'A']);
                }
            }

            if (a == 'Y') {
                if (b == 'U') Y_m_adj[c - 'A'][d - 'A'] = min(e, Y_m_adj[c - 'A'][d - 'A']);
                if (b == 'B'){
                    Y_m_adj[c - 'A'][d - 'A'] = min(e, Y_m_adj[c - 'A'][d - 'A']);
                    Y_m_adj[d - 'A'][c - 'A'] = min(e, Y_m_adj[c - 'A'][d - 'A']);
                }
            }
        }
        floyd_marshall('Z' - 'A' + 1);
        int mn = INF;
        char p1, p2;
        scanf(" %c %c", &p1, &p2);
        for (int i = 'A'; i <= 'Z'; i++) {
            mn = min(mn, Y_m_adj[p1-'A'][i-'A'] + M_m_adj[p2-'A'][i-'A']);
        }
        vector<char> ans;
        for (int i = 'A'; i <= 'Z'; i++) {

            if (Y_m_adj[p1-'A'][i-'A'] + M_m_adj[p2-'A'][i-'A'] == mn) ans.pb(i);
        }
        if (mn >= INF) {
            printf("You will never meet.\n");
        } else {
            printf("%d", mn);
            for (int i = 0; i < (int) ans.size(); i++) {
                printf(" %c", ans[i]);
            }
            printf("\n");
        }
        //cout << mn << endl;
    }

}
