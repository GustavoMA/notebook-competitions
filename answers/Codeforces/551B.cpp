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
*** Codeforces - 551 - B. ZgukistringZ
*** http://codeforces.com/contest/551/problem/B
*** Tag: String
*** Author: Gustavo Monteiro Alves - GustavoMA
**/

//read files

int A[500], B[500], C[500];
int _A[500];

void build_temp() {
    for (int i = 'a'; i <= 'z'; i++) _A[i] = A[i];
}

void remover_b(int k) {
    build_temp();
    for (int i = 'a'; i <= 'z'; i++) _A[i] -= k*B[i];
}

void remover_c(int k) {
    for (int i = 'a'; i <= 'z'; i++) _A[i] -= k*C[i];
}

bool can_b(int k) {
    remover_b(k);
    for (int i = 'a'; i <= 'z'; i++) if (_A[i] < 0) return false;
    return true;
}

int cont_c() {
    int mn = INF;
    for (int i = 'a'; i <= 'z'; i++) if (C[i] != 0) mn = min(mn, _A[i]/C[i]);
    return mn;
}

int main() {
    string a, b, c;
    cin >> a >> b >> c;
    for (int i = 0; i < a.size(); i++) A[a[i]]++;
    for (int i = 0; i < b.size(); i++) B[b[i]]++;
    for (int i = 0; i < c.size(); i++) C[c[i]]++;
    int b_n = 0;
    int mx_b_n = -1;
    int mx_c_n = -1;
    while(can_b(b_n)) {
        int c_n = cont_c();
        if (mx_b_n == -1 && mx_c_n == -1) {
            mx_c_n = c_n;
            mx_b_n = b_n;
        } else if (mx_c_n + mx_b_n < c_n + b_n) {
            mx_c_n = c_n;
            mx_b_n = b_n;
        }
        b_n++;
    }
    for (int i = 0; i < mx_b_n; i++) cout << b;
    for (int i = 0; i < mx_c_n; i++) cout << c;
    remover_b(mx_b_n);
    remover_c(mx_c_n);
    for (int i = 'a'; i <= 'z'; i++) if (_A[i] > 0) for (int j = 0; j < _A[i]; j++) cout << ((char) i);
    cout << endl;
    return 0;
}
