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

double memoa[MAX_N][MAX_N][MAX_N];
double memob[MAX_N][MAX_N][MAX_N];
double memoc[MAX_N][MAX_N][MAX_N];
// a -> b
// b -> c
// c -> a
double pd1(int a, int b, int c) {
    if (memoa[a][b][c] != -1) return memoa[a][b][c];
    if (b == 0 && c == 0) return 1;
    if (a == 0) return 0;
    if (b == 0) return 0;
    if (c == 0) return 1;
    return memoa[a][b][c] = (a*b) / (double) (a*b + a*c +b*c) * pd1(a  , b-1,  c) +
                            (a*c) / (double) (a*b + a*c +b*c) * pd1(a-1, b  ,  c) +
                            (b*c) / (double) (a*b + a*c +b*c) * pd1(a  , b  , c-1);
}
double pd2(int a, int b, int c) {
    if (memob[a][b][c] != -1) return memob[a][b][c];
    if (a == 0 && c == 0) return 1;
    if (b == 0) return 0;
    if (c == 0) return 0;
    if (a == 0) return 1;
    return memob[a][b][c] = (a*b) / (double) (a*b + a*c +b*c) * pd1(a  , b-1,  c) +
                            (a*c) / (double) (a*b + a*c +b*c) * pd1(a-1, b  ,  c) +
                            (b*c) / (double) (a*b + a*c +b*c) * pd1(a  , b  , c-1);
}
double pd3(int a, int b, int c) {
    if (memoc[a][b][c] != -1) return memoc[a][b][c];
    if (a == 0 && b == 0) return 1;
    if (c == 0) return 0;
    if (a == 0) return 0;
    if (b == 0) return 1;
    return memoc[a][b][c] = (a*b) / (double) (a*b + a*c +b*c) * pd1(a  , b-1,  c) +
                            (a*c) / (double) (a*b + a*c +b*c) * pd1(a-1, b  ,  c) +
                            (b*c) / (double) (a*b + a*c +b*c) * pd1(a  , b  , c-1);
}
void clean() {
    for (int i = 0; i < 105; i++)
        for (int j = 0; j < 105; j++)
            for (int k = 0; k < 105; k++) {
                memoa[i][j][k] = -1.0;
                memob[i][j][k] = -1.0;
                memoc[i][j][k] = -1.0;
            }
}

int main() {
    clean();
    int a, b, c;
    cin >> a >> b >> c;
    printf("%.12f %.12f %.12f\n", pd1(a,b,c), pd2(a,b,c), pd3(a,b,c));
    return 0;
}
