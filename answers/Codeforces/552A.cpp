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
#define MAX_N 100100
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-4
//freopen ("in.txt", "r", stdin);
//freopen ("out.txt","w", stdout);

/**
*** Codeforces - 552 - A. Vanya and Table
*** Link
*** Tag:
*** Author: Gustavo Monteiro Alves - GustavoMA
**/

int grid[102][102];

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x1, x2, y1, y2;
        cin >>  x1 >> y1 >> x2 >> y2;
        for (int x = x1; x <= x2; x++)
            for (int y = y1; y <= y2; y++)
                grid[x][y]++;
    }
    int tot = 0;
    for (int x = 1; x <= 100; x++)
        for (int y = 1; y <= 100; y++)
            tot += grid[x][y];

    cout << tot << endl;
    return 0;
}
