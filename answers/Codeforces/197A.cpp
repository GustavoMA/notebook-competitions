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
*** Codeforces - 197 - A. Plate Game
*** http://codeforces.com/problemset/problem/197/A
*** Tag: Game
*** Author: Gustavo Monteiro Alves - GustavoMA
**/

int main(int argc, char const *argv[]) {
    int a, b, r;
    scanf(" %d %d %d", &a, &b, &r);
    if (2*r <= a && 2*r <= b) {
        printf("First\n");
    } else {
        printf("Second\n");
    }
    return 0;
}
