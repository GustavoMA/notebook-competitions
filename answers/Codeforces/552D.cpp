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

bool isTriangle(ii a, ii b, ii c) {
    int A = a.fi * b.sc + a.sc * c.fi + b.fi * c.sc - c.fi * b.sc - c.sc * a.fi - a.sc * b.fi;
    return A != 0;
}

vii points;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf(" %d %d", &a, &b);
        points.pb(mp(a,b));
        //cout << "LOL" << endl;
    }
    int tot = 0;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            for (int k = j+1; k < n; k++)
                if (isTriangle(points[i],points[j],points[k])) {
                    // cout << points[i].fi <<" " << points[j].fi <<" " << points[k].fi<<" " << endl;
                    // cout << points[i].sc <<" " << points[j].sc <<" " << points[k].sc<<" " << endl;
                    // cout << endl;
                    tot++;
                }
    cout << tot << endl;
    return 0;
}
