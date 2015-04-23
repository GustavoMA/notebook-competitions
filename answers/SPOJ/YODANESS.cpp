#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef long long           ll;
typedef pair <int , int>    ii;
typedef vector<ii>         vii;
typedef vector<int>         vi;
#define pb push_back
#define mp make_pair
#define INF 1000000000

#define MAXN 30010

/**
*** OLD SOLUTION - PRE REPOSITORY
*** SPOJ - YODANESS - Yodaness Level
*** http://www.spoj.com/problems/YODANESS/
*** Tag: BIT
*** Author: Gustavo Monteiro Alves - GustavoMA
**/

int BIT[MAXN];
ll A[MAXN];
map <string, int> mapa;
map <string, int>::iterator it;

void update(int i, int val) {
    while (i < MAXN) {
        BIT[i] += val;
        i += (i & -i);
    }
}

int read(int i) {
    int sum = 0;
    while (i > 0) {
        sum += BIT[i];
        i -= (i & -i);
    }
    return sum;
}

int main() {
    int k;
    scanf(" %d", &k);
    while(k--) {
        memset(BIT, 0, sizeof(BIT));
        string entrada;
        int n;
        scanf(" %d", &n);
        for(int i = 1; i<= n; i++) {
            cin >> entrada;
            mapa[entrada] = i;
        }
        for(int i = 0; i< n; i++) {
            cin >> entrada;
            A[i] = mapa[entrada];
        }
        ll cont = 0;
        for (int i = n-1; i>= 0; i--){
            cont += read(A[i]);
            update(A[i],1);
        }
        printf("%Ld\n", cont);
    }
    return 0;
}
