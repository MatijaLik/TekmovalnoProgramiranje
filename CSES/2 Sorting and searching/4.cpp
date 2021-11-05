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
#define inf 2000000000
#define mod 1000000007
#define debug(x) cout << "# " << x << endl


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;   

    set<array<int, 2>> tickets;
    vector<int> people(m);

    loop(i, n){
        int temp;
        cin >> temp;
        tickets.insert({temp, i});
    }
    
    
    //printf("here\n");

    loop(i, m)cin >> people[i];
    

    for(auto person : people){

        auto id = tickets.lower_bound({person+1, 0});

        if(id == tickets.begin()){
            cout << -1 << endl;
            continue;
        }

        id--;
        cout << (*id)[0] << endl;
        tickets.erase(id);   
    }
}