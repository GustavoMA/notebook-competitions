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
*** Codeforces - 540 - A. Combination Lock
*** http://codeforces.com/contest/540/problem/A
*** Tag: Bruteforce
*** Author: Gustavo Monteiro Alves - GustavoMA
**/

int int_mod(int a, int b) {
  return (a % b + b) % b;
}

int rotate(int a, int b) {
    if (a == b) return 0;
    int cnt1 = 0;
    int a1= a, b1 = b;
    while (a1 != b1) {
        cnt1++;
        a1 = int_mod(a1 + 1, 10);
    }
    int cnt2 = 0;
    int a2= a, b2 = b;
    while (a2 != b2) {
        cnt2++;
        a2 = int_mod(a2 - 1, 10);
    }
    return min(cnt1,cnt2);
}

int main() {
    int k;
    scanf(" %d", &k);
    string a, b;
    cin >> a >> b;
    int tot = 0;
    for (int i = 0; i < a.size(); i++) {
        tot += rotate(a[i] - '0', b[i]-'0');
    }
    cout << tot << endl;
    return 0;
}
