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
#define MAX_N 100010
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-4

/**
*** Codeforces - 574 - C. Bear and Poker
*** http://codeforces.com/contest/574/problem/C
*** Tag:
*** Author: Gustavo Monteiro Alves - GustavoMA
**/

//read files
//freopen ("in.txt", "r", stdin);
//freopen ("out.txt","w", stdout);

int bids[MAX_N];

int main() {
    int n;
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &bids[i]);
        while(bids[i] % 2 == 0) bids[i] /= 2;
        while(bids[i] % 3 == 0) bids[i] /= 3;
    }
    for (int i = 1; i < n; i++) {
        if (bids[i-1] != bids[i]) {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}
