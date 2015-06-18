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
*** Codeforces - 346 - A. Alice and Bob
*** http://codeforces.com/problemset/problem/346/A
*** Tag: Games, Number Theory
*** Author: Gustavo Monteiro Alves - GustavoMA
**/

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main(int argc, char const *argv[]) {
    int n;
    scanf(" %d", &n);
    int gcd_v = 0;
    int mx = -1;
    for (int i = 0; i < n; i++) {
        int temp;
        scanf(" %d", &temp);
        gcd_v = gcd(temp, gcd_v);
        mx = max(mx, temp);
    }
    int m = mx/gcd_v - n;
    if (m&1) printf("Alice\n");
    else printf("Bob\n");
    return 0;
}
