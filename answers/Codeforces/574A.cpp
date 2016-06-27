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
*** Codeforces - 574 - A. Bear and Elections
*** http://codeforces.com/problemset/problem/574/A
*** Tag:
*** Author: Gustavo Monteiro Alves - GustavoMA
**/

//read files
//freopen ("in.txt", "r", stdin);
//freopen ("out.txt","w", stdout);

priority_queue<int> pq;

int main(int argc, char const *argv[]) {
    int n, bear;
    scanf(" %d %d", &n, &bear);

    for (int i = 1; i < n; i++) {
        int temp;
        scanf(" %d", &temp);
        pq.push(temp);
    }
    int val = 0;
    while(pq.top() >= bear) {
        int temp = pq.top(); pq.pop();
        pq.push(temp-1);
        val++; bear++;
    }
    printf("%d\n", val);
    return 0;
}
