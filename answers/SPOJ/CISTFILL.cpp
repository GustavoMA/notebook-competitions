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
#define INF 2000000000
#define MAX_N 50100
#define MAX_M 10
#define MOD 1000000007
#define EPS 1e-4

/**
*** SPOJ - CISTFILL - Fill the Cisterns
*** http://www.spoj.com/problems/CISTFILL/
*** Tags: Binary Search
*** Author: Gustavo Monteiro Alves - GustavoMA
**/
ll n, v;
ll arr[MAX_M][MAX_N];

bool check(double m) {
    double vol = 0.0;
    ll x;
    for (int i = 0; i < n; i++) {
        x = arr[0][i] + arr[1][i];
        if (m >= x) {
            vol += arr[2][i] * arr[1][i];
        } else if (m < x && m > arr[0][i]) {
            vol += (m - arr[0][i]) * arr[2][i];
        }
    }
    return !(vol >= v);
}

double binary_search() {
    double left = 0.0;
    double right = 1040000.0;
    for (int i = 0; i < 40; i++) {
        double mid = (left + right)/2.0;
        //printf("DEBUG  mid = %lf\n", mid);
        if (check(mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return left;
}

int main() {
    int k;
    scanf(" %d", &k);
    while (k--) {
        ll tot = 0.0;
        scanf(" %Ld", &n);
        for (int i = 0; i < n; i++) {
            ll tmp1, tmp2;
            scanf(" %Ld %Ld %Ld %Ld", &arr[0][i], &arr[1][i], &tmp1, &tmp2);
            arr[2][i] = tmp1*tmp2;
            tot += tmp1*tmp2*arr[1][i];
        }
        scanf(" %Ld", &v);
        //printf("DEBUG tot = %Ld, v = %Ld \n", tot, v);
        if (tot < v) {
            printf("OVERFLOW\n");
        } else {
            printf("%.2lf\n", binary_search());
        }
    }    
    return 0;
}