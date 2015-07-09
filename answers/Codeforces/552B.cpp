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

ll digits(ll n) {
    stringstream ss;
    ss << n;
    string str;
    ss >> str;
    ll r = 0, k = 9, sum = 0;
    for (int i = 1; i < str.size(); i++) {
        r += i * k;
        sum += k;
        k = k * 10;
    }

    r += str.size() * (n-sum);
    return r;
}

int main(int argc, char const *argv[]) {
    ll n;
    cin >> n;
    cout << digits(n) << endl;
    return 0;
}
