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
*** Codeforces - 276 - B. Little Girl and Game
*** http://codeforces.com/problemset/problem/276/B
*** Tag: Game, Greedy
*** Author: Gustavo Monteiro Alves - GustavoMA
**/

int cnt[500];

int main(int argc, char const *argv[]) {
    string a;
    cin >> a;
    for (int i = 0; i < (int) a.size(); i++) cnt[a[i]]++;
    int odds = 0;
    for (int i = 0; i < 500; i++) if (cnt[i]&1) odds++;
    if (odds == 0 || odds&1) printf("First\n");
    else printf("Second\n");
    return 0;
}
