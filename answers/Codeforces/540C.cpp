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
#define MAX_N 550
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-4

/**
*** Codeforces - 540 - C. Ice Cave
*** http://codeforces.com/contest/540/problem/C
*** Tag: DFS
*** Author: Gustavo Monteiro Alves - GustavoMA
**/

int x[4] = { 0,  0, -1, 1};
int y[4] = {-1,  1,  0, 0};

int grid[MAX_N][MAX_N];
int i_f, j_f;
int flag = false;
void dfs(int i, int j) {
    if (flag) return;
    grid[i][j] = 0;
    for (int k = 0; k < 4; k++) {
        if (grid[i + x[k]][j + y[k]]) {
            dfs(i + x[k], j + y[k]);
        } else if (i + x[k] == i_f && j+y[k] == j_f) {
            flag = true;
            return;
        }
    }
    grid[i][j] = 1;
}

int main() {
    int n, m;
    scanf(" %d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char a;
            scanf(" %c", &a);
            if (a == '.') grid[i][j] = 1;
        }
    }
    int i_i, j_i;
    scanf(" %d %d", &i_i, &j_i);
    scanf(" %d %d", &i_f, &j_f);
    dfs(i_i, j_i);
    if (flag) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
