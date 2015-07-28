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
*** Codeforces - B. The Child and Set
*** http://codeforces.com/problemset/problem/437/B
*** Tag: Greedy
*** Author: Gustavo Monteiro Alves - GustavoMA
**/

int exp(int n, int e) {
    if (e == 0) return 1;
    if (e % 2  == 1) return n * exp(n, e-1);
    int half = exp(n, e/2);
    return half*half;
}

int countzeros(int x) {
    int cnt = 0;
    while (!(x&1)) {
        cnt++;
        x = x >> 1;
    }
    return cnt;
}

int lowerBitValue(int x) {
    return exp(2, countzeros(x));
}

vi numbers;

int main(int argc, char const *argv[]) {
    int limit,  sum;
    scanf(" %d %d", &sum, &limit);
    for (int i = limit; i > 0; i--) {
        int x = lowerBitValue(i);
        if (x <= sum) {
            sum -= x;
            numbers.pb(i);
        }
    }

    if (sum > 0) printf("-1\n");
    else {
        printf("%d\n", numbers.size());
        for (int i = 0; i < (int) numbers.size(); i++) {
            printf("%d ", numbers[i]);
        }
        printf("\n");
    }
    return 0;
}
