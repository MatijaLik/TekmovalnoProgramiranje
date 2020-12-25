/**
 * Author: MatijaL
 * Time: 2020-11-24 11:48:01
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pll pair<ll, ll>
#define loop(i, n) for(ll i = 0; i < n; i++)
#define FOR(i,n,m) for(ll i = n; i <= m; i++)
#define isIn(vec, item) find(vec.begin(), vec.end(), item) != vec.end()
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define inf 1000000005
#define mod 1000000007
#define print(v) for(auto e : v) cout << e << " "; cout << endl;


void solve(){
    string s;
    cin >> s;

    int n = s.length();
    vector<int> v(n);
    for(int i = 1, l = 0, r = 0; i < n; i++){
        //setup
        if(i <= r)
            v[i] = min(r - i + 1, v[i-l]);
        
        //expand
        while(l + v[i] < n and s[i + v[i]] == s[v[i]])
            v[i]++;

        //adjust
        if(i + v[i] - 1 > r){
            l = i;
            r = i + v[i] - 1;
        }
    }

    


    vector<int> end;
    //vector<int> mid;

    int bestMid = 0;

    FOR(i, 1, n-1){
        if(v[i] == n-i){
            end.pb(v[i]);
            bestMid = max(bestMid, v[i]-1);
        }
        else bestMid = max(bestMid, v[i]);
    }



    int p1 = 0, p2 = 0;
    int best = 0;
    //print(mid);
    //print(end);
    while(p1 < end.size()){
        int e1 = end[p1];
        int e2 = bestMid;
        if(e2 >= e1){
            best = e1;
            break;
        }

        p1++;

    }

    if(best == 0){
        cout << "Just a legend" << endl;
    }else{
        cout << s.substr(0,best) << endl;
    }
    //print(v);
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);  
    solve();
}
