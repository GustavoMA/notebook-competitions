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
*** Codeforces - 437 - A. The Child and Homework
*** http://codeforces.com/contest/437/problem/A
*** Tag: Implementation
*** Author: Gustavo Monteiro Alves - GustavoMA
**/

int main() {
    string A, B, C, D;
    cin >> A >> B >> C >> D;
    int a, b, c, d;
    a = A.size()-2; b = B.size()-2; c= C.size()-2; d = D.size()-2;
    bool A1 = (a >= 2*b && a>= 2*c && a >= 2*d) || (2*a <= b && 2*a <= c && 2*a <= d);
    bool B1 = (b >= 2*a && b >= 2*c && b >= 2*d)|| (2*b <= a && 2*b <= c && 2*b <= d);
    bool C1 = (c >= 2*b && c>= 2*d && c >= 2*a ) || (2*c <= b && 2*c <= d && 2*c <= a);
    bool D1 = (d >= 2*b && d>= 2*c && d >= 2*a ) || (2*d <= a && 2*d <= c && 2*d <= b);

    if (A1 && !B1 && !C1 && !D1) cout << "A" << endl;
    else if (!A1 && B1 && !C1 && !D1) cout << "B" << endl;
    else if (!A1 && !B1 && !C1 && D1) cout << "D" << endl;


    else {
        cout << "C" << endl;
    }
    return 0;
}
