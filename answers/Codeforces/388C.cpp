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
//freopen ("in.txt", "r", stdin);
//freopen ("out.txt","w", stdout);

/**
*** Codeforces - 388 - C. Fox and Card Game
*** http://codeforces.com/problemset/problem/388/C
*** Tag: Game
*** Author: Gustavo Monteiro Alves - GustavoMA
**/

vi numbers;

int main(int argc, char const *argv[]) {
    int n;
    scanf(" %d", &n);
    int ciel = 0, jiro = 0;
    for (int i = 0; i < n; i++) {
        int m;
        scanf(" %d", &m);
        // cout << "M = " << m << endl;
        for (int j = 0; j < m / 2; j++) {
            int a;
            scanf(" %d", &a);
            // cout << "DEBUG ciel " <<a << endl;
            ciel += a;
        }
        if (m&1) {
            int a;
            scanf(" %d", &a);
            numbers.pb(a);
        }
        for (int j = 0; j < m / 2; j++) {
            int a;
            scanf(" %d", &a);
            // cout << "DEBUG jiro " <<a << endl;
            jiro += a;
        }
    }
    sort(numbers.begin(), numbers.end());
    reverse(numbers.begin(), numbers.end());
    for (int i = 0; i < (int) numbers.size(); i++) {
        if (i&1) {
            jiro += numbers[i];
        } else {
            ciel += numbers[i];
        }
    }
    cout << ciel << " " << jiro << endl;
    return 0;
}
