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

int main(){

    //ios::sync_with_stdio(0);
    //cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    std::string str;

    str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());

    int cnt[30];
    memset(cnt, 0, sizeof cnt);

    //prestej
    for(auto c : s)cnt[(int)c - 65]++;

    //odd ones;
    int oddOnes = 0;
    int mid = -1;

    FOR(i, 0, 26){
        if(cnt[i]%2){
            oddOnes++;
            mid = i;
        }
    }

    if(oddOnes > 1){
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    deque<int> ans;

    if(mid != -1) ans.pb(mid);
    cnt[mid--];

    for(int i = 25; i >= 0; i--){
        loop(j, cnt[i]/2){
            ans.push_front(i);
            ans.push_back(i);
        }
    }

    for(auto e : ans){
        cout << char(e + 65);
    }
    cout << endl;
}