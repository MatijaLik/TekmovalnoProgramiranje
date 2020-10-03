#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<ll>
#define mii map<ll, ll>
#define si set<ll>
#define loop(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, n, m) for (ll i = n; i <= m; i++)
#define isIn(vec, item) find(vec.begin(), vec.end(), item) != vec.end()
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define inf 1000000000
#define mod 1000000007
#define debug(x) cout << "# " << x << endl

void solve()
{
    ll n, k;
    cin >> n >> k;
    int grid[n][n];

    memset(grid, 0, sizeof grid);

    k = min(k, n * n);

    bool tick = 1;
    
    int p1 = 0;
    int p2 = n-1;

    int coef = 0;/// (a-b)

    while (k--)
    {      
        if(coef > 3) break;

        int a, b;

        //adjust both p1 and p2
        if(coef < 0 and p1 == 0) p1 = -coef;
        if(coef > 0 and p2 == n-1) p2 = n-1-coef;

        //printf("p1 %d| p2 %d\n", p1, p2);

        //;
        if(p1 > p2){
            
            p1 = 0;
            p2 = n-1;
            tick = 1;

            if(coef == 0) coef = -1;
            else if(coef > 0) coef = (-coef) -1;
            else coef = -coef;//da na pozitivno
            k++;

            //printf("reseting | coef is %d\n", coef);

            continue;
        }

        if(tick){
            b = p1;
            a = coef + b;
            p1++;
            tick = false;
        }else{
            b = p2;
            a = coef + b;
            p2--;
            tick = true;
        }
        //printf("%d %d\n", a, b);
        grid[a][b] = 1;
    }

    //get minimal value
    ll maxA = 0;
    ll minA = inf;
    ll maxB = 0;
    ll minB = inf;

    loop(i, n)
    {
        ll sum = 0;
        //sestej vrstico
        loop(j, n) sum += grid[i][j];

        minA = min(minA, sum);
        maxA = max(maxA, sum);
    }

    loop(i, n)
    {
        ll sum = 0;
        //sestej stolpec
        loop(j, n) sum += grid[j][i];

        minB = min(minB, sum);
        maxB = max(maxB, sum);
    }

    cout << (maxB - minB) * (maxB - minB) + (maxA - minA) * (maxA - minA) << endl;

    loop(i, n)
    {
        loop(j, n)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
        solve();
}