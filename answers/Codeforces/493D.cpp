#include <bits/stdc++.h>

using namespace std;

typedef long long            ll;
typedef unsigned long long  ull;
typedef pair<int, int>       ii;
typedef vector<int>          vi;
typedef vector<ll>          vll;
typedef vector<ii>          vii;

#define INF 1000000000
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define sc second
#define MAX_N 100000

/**
*** Codeforces - 493 - D. Vasya and Chess
*** http://codeforces.com/contest/493/problem/D
*** Tag: Game
*** Author: Gustavo Monteiro Alves - GustavoMA
**/

int main() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << "white" << endl;
        cout << "1 2" << endl;
    } else {
        cout << "black" << endl;
    }
    return 0;
}
