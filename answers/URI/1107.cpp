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
#define MAX_N 10100
#define MAX_M 10
#define MOD 1000000007
#define EPS 1e-4

/**
*** URI - 1107 - Escultura a Laser
*** https://www.urionlinejudge.com.br/judge/pt/problems/view/1107
*** Author: Gustavo Monteiro Alves - GustavoMA
**/

int arr[MAX_N];

int main() {
    int a, c;
    while (true) {
        scanf(" %d %d", &a, &c);
        if (a == 0 && c == 0) break;
        for (int i = 0; i < c; i++) {
            scanf(" %d", &arr[i]);
        }
        int r = a - arr[0];
        for (int i = 1; i < c; i++) {
            if (arr[i-1] > arr[i]) r += abs(arr[i-1] - arr[i]);
        }
        printf("%d\n", r);
    }
    return 0;
}