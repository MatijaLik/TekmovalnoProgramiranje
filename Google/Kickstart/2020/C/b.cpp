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


#define limit 100



void solve(int cs){
    int grid[limit][limit];


    ll input[limit];
    memset(input, 0, sizeof input);

    vector<int> sosedi[limit];
    set<int> sosediS[limit];
    set<int> existing;


    ll n, m;
    cin >> n >> m;
    loop(i, n){
        string s;
        cin >> s;
        loop(j, m){
            char c = s[j];
            int value = (int)c - 65;
            existing.insert(value);
            grid[i][j] = value;
        }
    }
    
    /*
    printf("izpisemo grid\n");
    loop(i, n){
        loop(j, m){
            cout << grid[i][j];
        }
        cout << endl;
    }*/

    //gremo po stolpcih
    loop(j, m){
        loop(i, n){
            if(i == 0) continue;
            int up = grid[i-1][j];
            int bot = grid[i][j];
            if(up != bot and sosediS[bot].count(up) == 0){
                sosediS[bot].insert(up);
                sosedi[bot].pb(up);
                input[up]++;
            }
        }
    }

    /*
    printf("izpisemo vse\n");
    loop(i, 26){
        printf("crka %d: ", i);
        for(auto sosed : sosedi[i]){
            cout << sosed << " ";
        }
        cout << endl;
        printf("input is %d\n", input[i]);
    }*/

    string s = "";
    set<int> visited;
    bool error = 0;
    while(true){
        bool change = 0;
        for(int i = 0; i < 26; i++){
            if(existing.count(i) == 0) continue;
            if(input[i]==0 and visited.count(i) == 0){
                visited.insert(i);
                s += char(i + 'A');
                //printf("adding %d\n", i);
                change = 1;
                for(auto sosed : sosedi[i]){
                    input[sosed]--;
                }
                break;
            }
        }
        if(!change){
            if(s.length() < existing.size())error = 1;
            break;
        }
    }

    if(error) printf("Case #%d: %d\n", cs, -1);
    else {
        printf("Case #%d: ", cs);
        cout << s << endl;
    }

    return;
    
}

int main(){
    int t;
    cin >> t;
    int i = 1;

    while(t--)solve(i++);
}