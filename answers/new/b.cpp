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

vi l_n;
vi b_n;
vi ans;

int main() {
    int n, k, p, x, y;
    scanf(" %d %d %d %d %d", &n, &k, &p, &x, &y);
    for (int i = 0; i < k; i++) {
        int temp;
        scanf(" %d", &temp);
        if (temp < y) l_n.pb(temp);
        else b_n.pb(temp);
    }
    sort(l_n.begin(), l_n.end());
    int gug = l_n.size();
    for (int i = 0; i < n/2 - gug; i++) {
        l_n.pb(1);
        ans.pb(1);
    }
    sort(l_n.begin(), l_n.end());
    sort(b_n.begin(), b_n.end());

    gug = b_n.size();
    for (int i = 0; i < (n/2 - gug + 1); i++) {
        l_n.pb(y);
        ans.pb(y);
    }
    sort(b_n.begin(), b_n.end());

    //for (int i = 0; i < l_n.size(); i++) cout << l_n[i] << " ";
    //for (int i = 0; i < b_n.size(); i++) cout << b_n[i] << " ";
    //cout << endl;

    int tot = 0;
    for (int i = 0; i < l_n.size(); i++) tot += l_n[i];
    for (int i = 0; i < b_n.size(); i++) tot += b_n[i];
    if (tot <= x) {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}
