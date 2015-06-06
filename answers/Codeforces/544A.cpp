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
#define MAX_N 300
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-4
//freopen ("in.txt", "r", stdin);
//freopen ("out.txt","w", stdout);

/**
*** Codeforces - 544 - A. Set of Strings
*** http://codeforces.com/problemset/problem/544/A
*** Tag: Implementation
*** Author: Gustavo Monteiro Alves - GustavoMA
**/

bool used[MAX_N];

int main() {
    int n;
    string a;
    cin >> n >> a;
    vi output;
    for (int i = 0; i < a.size(); i++) {
        if (!used[a[i]] && output.size() < n) {
            used[a[i]] = true;
            output.pb(i);
        }
    }
    if (output.size() < n) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        output.pb(a.size());
        int f = output[0];
        for (int j = 1; j < output.size(); j++) {
            int l = output[j];
            for (int i = f; i < l; i++) cout << a[i];
            cout << endl;
            f = l;
        }
    }
}
