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


ll strToNum(string s){
    ll res = 0;

    ll pow = 1;

    for(int i = s.length()-1; i >= 0; i--){
        if(s[i] == '1') res+= pow;
        pow *= 2;
    }


    return res;

} 


string numToString(ll a, ll n){
    string ans = "";
    while(n--){
        if(a%2==1)ans = "1" + ans;
        else ans = "0" +ans;
        a /= 2;
    }
    return ans;
}

void solve(){
    set<ll> removed;

    int N, M;
    cin >> N >> M;

    ll curLength = ((ll) 1 << M);
    ll median = ((ll) 1 << (M-1)) - 1;


    loop(i, N){
        string s;
        cin >> s;

        ll num = strToNum(s);

        removed.insert(num);
        if(num <= median){
            if(curLength%2 == 0){//prestavi v desno

                median++;
                while(removed.count(median)) median++;

            }

            if(num == median){//daj na levo
                median--;
                while(removed.count(median)) median--;
            }

        }else{//brisemo na desni
            if(curLength%2 == 1){//prestavi v levo
                median--;
                while(removed.count(median)) median--;
            }
        }

        //printf("median is %lld\n", median);
        curLength--;
    }
    //printf("median is %lld\n", median);
    cout << numToString(median, M) << endl;
}

int main(){
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) solve();
}