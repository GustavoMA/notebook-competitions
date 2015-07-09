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
#define MAX_N 2001
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-4
//freopen ("in.txt", "r", stdin);
//freopen ("out.txt","w", stdout);

/**
*** Codeforces - 551 - A. GukiZ and Contest
*** http://codeforces.com/problemset/problem/551/A
*** Tag: Brute Force, Implementation
*** Author: Gustavo Monteiro Alves - GustavoMA
**/

int arr[MAX_N];

int main(int argc, char const *argv[]) {
    int n;
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) if (arr[j] > arr[i]) cnt++;
        printf("%d ", cnt + 1);
    }
    printf("\n");
    return 0;
}
