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
*** Codeforces - 538 - B. Quasi Binary
*** http://codeforces.com/contest/538/problem/B
*** Tag: Greedy
*** Author: Gustavo Monteiro Alves - GustavoMA
**/

vi li;

int findn(int num) {
    if ( num < 10 )
        return 1;
    if ( num < 100 )
        return 2;
    if ( num < 1000 )
        return 3;
    if ( num < 10000 )
        return 4;
    if ( num < 100000 )
        return 5;
    if ( num < 1000000 )
        return 6;
    if ( num < 10000000 )
        return 7;
    if ( num < 100000000 )
        return 8;
   //continue until max int
}

bool check(string a){
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != '0') return true;
    }
    return false;
}

int expo(int n, int e) {
    if (e == 0) return 1;
    if (e%2 == 1) return n*expo(n,e-1);
    int half = expo(n,e/2);
    return half*half;
}

int main() {
    int a;
    scanf(" %d", &a);
    int temp = 0;

    while (a != 0) {
        //cout << ceil(log10(a)) << endl;
        //cout << a << endl;
        for (int i = 0; i < findn(a); i++) {
            //cout << "i " << i<< endl;
            //cout << "expo " << expo(10, i) << endl;
            int digit = (a / expo(10, i)) % 10;

            //cout << digit << endl;
            if (digit > 0) {
                temp += expo(10, i);
                a -= expo(10, i);
            }
        }
        li.pb(temp);
        temp = 0;
    }

    printf("%d\n", (int) li.size());
    for (int i = 0; i < (int) li.size(); i++) {
        printf("%d ", li[i]);
    }
    printf("\n");
    return 0;
}
