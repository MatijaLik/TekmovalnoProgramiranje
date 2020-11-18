/**
 * Author: MatijaL
 * Time: 2020-11-07 17:18:45
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
int n;    
vector<int> v;
vector<int> legacy;
int ans;
stringstream ss;
bool orient = false;
void print(){
    for(auto e : v) cout << e << " ";
    cout << endl;
}

void flip(){ 
    reverse(all(v));
    ss << n << endl;
    FOR(i, 1, n) ss << 1 << " ";
    ss << endl;
    orient = !orient;

    print();
}
void shuffle(int pivot, int goal){
    int a, b, c, d;
    a = pivot;
    b = 1;
    c = goal-pivot;
    d = n-goal-1;

    int cnt = 0; 
    if(a>0) cnt++;
    if(b>0) cnt++;
    if(c>0) cnt++;
    if(d>0) cnt++;
    ss<< cnt << endl;
    if(a > 0) ss << a << " ";
    if(b > 0) ss << b << " ";
    if(c > 0) ss << c << " ";
    if(d > 0) ss << d << " ";
    ss << endl;



    vector<int> next;
    loop(i, d) next.pb(v[goal+1+i]);
    loop(i, c) next.pb(v[pivot+1+i]);
    next.pb(v[pivot]);
    loop(i, a) next.pb(v[i]);

    v = next;

    print();
}


void benis(){
    
    while(true){
        int gi;
        int pi;
        bool found = false;
        FOR(i, 0, n-1){
            FOR(j, i+1, n-1){
                if(v[i] == 1+v[j]){
                    pi= i;
                    gi = j;
                    found = true;
                    break;
                }
            }
            if(found) break;
        }
        if(!found) break;
      
        ans++;
        shuffle(pi, gi);
    }
}


void solve(){
    cin >> n;
    loop(i, n){
        int temp;
        cin >> temp;
        v.pb(temp);
    }
    legacy = v;
    
    ss.str("");
    ans = 0;
    v = legacy;
    benis();
    if(ans > n){
        ss.str("");
        ans = 1;
        v = legacy;
        flip();
        benis();
    }   

    cout << ans << endl;
    cout << ss.str();
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t = 1;
    while(t--) solve();   
}
