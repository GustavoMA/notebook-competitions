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

/**
*** Codeforces - 551 - C. GukiZ hates Boxes
*** http://codeforces.com/contest/551/problem/C
*** Tag: Binary Search, Greedy
*** Author: Gustavo Monteiro Alves - GustavoMA
**/

ll a[MAX_N];
ll _a[MAX_N];

void temporary(int n) {
    for (int i = 0; i < n; i++) _a[i] = a[i];
}

int main() {
    ll n, m;
    cin >> n >> m;
    ll tot = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        tot += a[i];
    }
    ll l = 2, r = tot + n;
    while (l < r) {
        ll z = (l + r)/2;
        temporary(n);
        ll p = n - 1;
        for (int i = 0; i < m; i++) {
            while (p >= 0 && _a[p] == 0) p--;
            ll t = z - p - 1;
            if (t <= 0) break;
            while (p >= 0 && _a[p] <= t) t -= _a[p--];
            if (p >= 0) _a[p] -= t;
        }
        if (p < 0) r = z;
        else l = z + 1;
    }
    cout << r << endl;
    return 0;
}
