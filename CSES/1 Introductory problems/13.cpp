#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector <ll>
#define mii map<ll, ll>
#define si set<ll>
#define loop(i, n) for(ll i = 0; i < n; i++)
#define FOR(i,n,m) for(ll i = n; i <= m; i++)
#define isIn(vec, item) find(vec.begin(), vec.end(), item) != vec.end()
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define inf 1000000000
#define mod 1000000007
#define debug(x) cout << "# " << x << endl


set<string> visited;
vector<string> vse;

ll N;
string s;

void f(ll mask, string str){
    //printf("f -> mask %lld\n", mask);


    if(mask == (1 << N)-1){
        if(visited.count(str) == 0){
            //cout << str << endl;
            visited.insert(str);
            vse.pb(str);
            return;
        }
    }
    
        
    loop(i, N){
        //if empty
        if((mask & (1 << i)) == 0){
            f(mask | (1 << i), str + s[i]);
        }
    }
    return;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cin >> N;
    cin >> s;
    N = s.length();
    f(0, "");

    sort(all(vse));
    cout << vse.size() << endl;
    for(auto e : vse) cout << e << endl;
}