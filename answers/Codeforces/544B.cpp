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
*** Codeforces - 544 - B. Sea and Islands
*** http://codeforces.com/problemset/problem/544/B
*** Tag: Implementation
*** Author: Gustavo Monteiro Alves - GustavoMA
**/

int main() {
    int n, is;
    cin >> n >> is;
    if ( (n%2 == 0 && is <= n*n/2 ) ||
         (n%2 == 1 && is <= (n*n)/2 +1))  {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            //cout << "is = " << is << endl;
            for (int j = 0; j < n; j++) {
                if ( is > 0 && ((i % 2 == 0 && j % 2 == 0) ||
                          (i % 2 == 1 && j % 2 == 1))) {
                    cout << "L";
                    is--;
                } else {
                    cout << "S";
                }
            }
            cout << endl;
        }
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
