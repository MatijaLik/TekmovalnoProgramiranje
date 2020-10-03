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
#define debug(x) cout << "# " << x << endl;

int main(){
    ll T;
    cin >> T;
    while(T--){
        ll N, K;
        cin >> N >> K;

        string s;
        cin >> s;

        ll parts = N/K;

        
        ll opt[K];
        memset(opt, 0, sizeof opt);
        ll limit;
        if(K%2==0) limit = (K/2) - 1;
        else limit = K/2;
        FOR(letter, 0, limit){//za vsako crko
            map<char, ll> cnt;
            ll mx = 0;
            //char bestl; 
            FOR(i, 0, parts-1){ // vse dele
                char c = s[K*i + letter];
                cnt[c]++;
                //if(mx < cnt[c]) bestl = c;
                //cout << c << endl;
                mx = max(mx, cnt[c]);

                c = s[K*(i+1) - letter - 1];
                cnt[c]++;
                //cout << c << endl;
                //if(mx < cnt[c]) bestl = c;
                mx = max(mx, cnt[c]);
                    
            } 
            //printf("letter %d, mx %d, best %c\n", letter, mx, bestl);
            if(K%2 == 0 or letter != (K/2)) opt[letter] = 2*parts - mx;
            else opt[letter] = parts - mx/2; 
        }


        ll ans = 0;
        loop(i, (K/2)+1) ans += opt[i];

        cout << ans << endl;


        //sredina, ;e je n lih

        //konec


    }
}