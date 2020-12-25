/**
 * Author: MatijaL
 * Time: 2020-12-12 14:48:06
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


int ans = 0;
stringstream ss;



void solve(){
    int N;
    cin >> N;

    vector<int> v(N);
    loop(i, N) cin >> v[i];

    vector<int> sorted;
    sorted = v;
    sort(all(sorted));
    reverse(all(sorted));
    
    stack<int> prim;
    stack<int> sec;


    reverse(all(v));
    loop(i, N) prim.push(v[i]);


    string from = "L\n";
    string  to = "D\n";

    for(auto e : sorted){
        //printf("looking for %d\n", e);
        //1 dokoplji se
        while(true){
            int cur = prim.top();
            prim.pop();
            if(cur == e){
                ans++;
                ss << "UZMI D " + from;
                break;
            }else{
                ans+= 2;
                ss << "UZMI L " + from;
                ss << "STAVI L " + to;
                sec.push(cur);

            }
        }

        //naredi plac
        while(true){
            if(prim.empty()) break;
            //dokler imamo manjse elemente jih fuknes preko
            int cur = prim.top();
            if(cur > e) break;
            prim.pop();

            ans+= 2;
            ss << "UZMI L " + from;
            ss << "STAVI L " + to;
            sec.push(cur);
        }

        //postavi nazaj
        ans++;
        ss << "STAVI D " + from;

        //daj ostale nazaj
        while(!sec.empty()){
            int cur = sec.top();
            sec.pop();

            ans+= 2;
            ss << "UZMI L " + to;
            ss << "STAVI L " + from;
            prim.push(cur);
        }
    }


    cout << ans << endl;
    cout << ss.str();
}


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
