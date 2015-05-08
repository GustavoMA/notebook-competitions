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
#define MAX_N 32
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-4

/**
*** UVa - 532 - Dungeon Master
*** http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=473
*** Tag: BFS
*** Author: Gustavo Monteiro Alves - GustavoMA
**/

int X[6] = {0, 0,0, 0,1,-1};
int Y[6] = {0, 0,1,-1,0, 0};
int Z[6] = {1,-1,0, 0,0, 0};

int dungeon[MAX_N][MAX_N][MAX_N];
int dist[MAX_N][MAX_N][MAX_N];

queue <int> Q;
void bfs(int x, int y, int z) {
    Q.push(x);Q.push(y);Q.push(z);
    dist[x][y][z] = 0;
    dungeon[x][y][z] = 0;
    while (!Q.empty()) {
        int _x = Q.front(); Q.pop();
        int _y = Q.front(); Q.pop();
        int _z = Q.front(); Q.pop();
        for (int i = 0; i < 6; i++) {
            if (dungeon[_x + X[i]][_y + Y[i]][_z + Z[i]]) {
                Q.push(_x + X[i]);
                Q.push(_y + Y[i]);
                Q.push(_z + Z[i]);
                dungeon[_x + X[i]][_y + Y[i]][_z + Z[i]] = 0;
                dist[_x + X[i]][_y + Y[i]][_z + Z[i]] = dist[_x][_y][_z] + 1;
            }
        }
    }
}

int main() {
    while (true) {
        memset(dungeon, 0, sizeof dungeon);
        int l, r, c;
        scanf(" %d %d %d", &l, &r, &c);
        if (!l && !r && !c) break;
        int xi, yi, zy;
        int xf, yf, zf;
        for (int k = 1; k <= l; k++) {
            for (int j = 1; j <= r; j++) {
                for (int i = 1; i <= c; i++) {
                    char ch;
                    scanf(" %c", &ch);
                    if (ch == 'S') {
                        xi = i; yi = j; zy = k;
                        dungeon[i][j][k] = 1;
                    }
                    if (ch == 'E') {
                        xf = i; yf = j; zf = k;
                        dungeon[i][j][k] = 1;
                    }
                    if (ch == '.') dungeon[i][j][k] = 1;
                }
            }
        }
        dist[xf][yf][zf] = INF;
        bfs(xi, yi, zy);
        if (dist[xf][yf][zf] < INF) {
            printf("Escaped in %d minute(s).\n", dist[xf][yf][zf]);
        } else {
            printf("Trapped!\n");
        }
        //cout << dist[xf][yf][zf] << endl;
    }
}
