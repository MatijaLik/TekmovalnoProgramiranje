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


set<int> sorted;
int letterNum;
int vhodnaStopnja[26];


vector<int> pointing[26];
set<int> pointingS[26];




string khan(){
    string s;
    while(true){
        bool change = 0;
        for(int i = 0; i < 26; i++){
            if(sorted.count(i)==0 and vhodnaStopnja[i]==0){
                sorted.insert(i);
                change = 1;
                s += (char)(i + 97);
                for(auto sosed : pointing[i]){
                    vhodnaStopnja[sosed]--;
                }
                break;
            }
        }
        if(!change) break;
    }
    return s;
}


int main(){
    int n;
    cin >> n;
    vector<string> v;
    loop(i, n){
        string s;
        cin >> s;
        v.pb(s);
    }


    loop(i, n)loop(j, n){
        if(j <= i) continue;
        string a = v[i];
        string b = v[j];
        int len = min(a.length(), b.length());

        bool fix = 0;
        loop(p, len){
            char ac = a[p];
            char bc = b[p];


            if(bc != ac){
                int smol = ac - 'a';
                int big = bc - 'a';
                fix = 1;
                if(pointingS[smol].count(big)==0){
                    pointing[smol].pb(big);
                    vhodnaStopnja[big]++;
                    pointingS[smol].insert(big);
                    //cout << (char)(smol+97) << "--->" << (char)(big+97) << endl;
                }
                    
                break;
            }
        }

        if(!fix and a>b){
            cout << "Impossible" << endl;
            exit(0);
        }
    }

    string s = khan();
    if(s.length() != 26) cout << "Impossible" << endl;
    else cout << s << endl;
}