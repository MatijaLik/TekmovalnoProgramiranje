/*
 * Author: MatijaL
 * Time: 2020-08-16 19:01:25
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
#define inf 1000000000
#define mod 1000000007
set<ll> good;
set<ll> bad;
ll lcnt = 0;
ll fcnt = 0;
ll doubleCnt = 0;

set<ll> fire;
ll fireInCnt = 0;

ll ans = 0;

void sortThings(){

    //prevec elementov
    while(good.size() > doubleCnt){
        ll min_element;
        min_element = *good.begin();
        if(fire.count(min_element) and fireInCnt == 1 and good.size() >= 2){
            //ne smemo prehitro vun vzet zadnjega F
            ll min = *good.begin();
            good.erase(min);
            min_element = *good.begin();
            good.insert(min);
            
        }
        ans -= min_element;
        good.erase(min_element);
        bad.insert(min_element);
        if(fire.count(min_element)) fireInCnt--;
    }

    //premalo elementov
    while(good.size() < doubleCnt){
        ll max_element;
        if(good.size() == 0 and !fire.empty()){
            //ce je set prazen, damo prvo fire not
            max_element = *(fire.rbegin());
        }
        else max_element = *(bad.rbegin()); 
        ans += max_element;
        good.insert(max_element);
        bad.erase(max_element);
        if(fire.count(max_element)) fireInCnt++;
    }
}
void solve(){
    int n;
    cin >> n;
    

    loop(i, n){
        ll tp, d;
        cin >> tp >> d;
        
        //add or remove element
        if(d < 0){
            d = -d;
            ans -= d;
            if(good.count(d)){ans-=d; good.erase(d);}
            else bad.erase(d);
            
            if(tp == 0) {
                fcnt--;
                fire.erase(d);
            }
            else lcnt--;
        }else{
            bad.insert(d);
            ans += d;
            if(tp == 0) {
                fcnt++;
                fire.insert(d);
            }
            else lcnt++;
        }
        
        //eval doubleCnt
        if(fcnt == 0) doubleCnt = lcnt-1;
        else doubleCnt = lcnt;

        if(fcnt + lcnt == 0) ans == 0;
        else sortThings();
        cout << ans << endl;
    }
    
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
