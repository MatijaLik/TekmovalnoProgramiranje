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


char alphabet[26];


void solve(){
    int n, m;
    
    cin >> n >> m;
    vector<string> words(n);

    loop(i, n) cin >> words[i];

    if(n == 1){
        cout << words[0] << endl;
        return;
    }

    string original = words[0];

    loop(i, m){//kateri char spremenimo

        for(auto letter : alphabet){//na kero crko
            string mockup = original;
            mockup[i] = letter;//spremenimo

            bool works = 1;
            //preverimo veljavnost
            for(string word : words){

                int dif = 0;

                loop(c, m){//kateri char primerjamo
                    if(mockup[c]!=word[c]) dif++;
                }

                if(dif > 1){
                    works = 0;
                    break;
                }
            }

            if(works){
                cout << mockup << endl;
                return;
            }
        }
    } 
    cout << -1 << endl;
}

int main(){
    loop(i, 26) alphabet[i] = char(i+97);
    int t;
    cin >> t;
    while(t--)solve();
}