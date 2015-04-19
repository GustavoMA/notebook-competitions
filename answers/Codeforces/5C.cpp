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
#define MAX_N 1000010
#define MAX_M 10
#define MOD 1000000007
#define EPS 1e-4

/**
*** Codeforces - 5C
*** http://codeforces.com/problemset/problem/5/C
*** Author: Gustavo Monteiro Alves - GustavoMA
**/


int d[MAX_N], c[MAX_N];
stack<int> s;

int main() {
    string a;
    cin >> a;
    for (int i = 0; i < (int) a.size(); i++) {
        if (a[i] == '(') {
            s.push(i);
            d[i] = -2;
            c[i] = -2;
        } else {
            if (s.empty()) {
                d[i] = -1;
                c[i] = -1;
            } else {
                d[i] = s.top();
                s.pop();

                if (a[d[i] - 1] == ')' && c[d[i] - 1] != -1) {
                    c[i] = c[d[i] - 1];
                } else {
                    c[i] = d[i];
                }
            }
        }
    }

    int mx = 0;
    for (int i = 0; i < (int) a.size(); i++) {
        if (c[i] == -1 || c[i] == -2) continue;
        mx = max(mx, i - c[i] + 1);
    }
    int cnt = 0;
    for (int i = 0; i < (int) a.size(); i++) {
        if (c[i] == -1 || c[i] == -2) continue;
        if ((i - c[i] + 1) == mx) cnt++;
    }
    
    if(mx) printf("%d %d\n",mx, cnt);
    else printf("0 1\n");

    return 0;
}