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

ll n;
vector<ll> a;
vector<ll> b;

int check(ll amnt){
    //printf("checking amount %lld\n", amnt);
    //error codes
    //0 works
    //1 too right
    //2 too left

    ll carry = amnt;
    FOR(i, 0, n-1){
        ll demand = a[i];
        //printf("using %d, demanding %lld carry is %lld\n" , i, demand, carry);
        //ponucaj prvo stranico
        if(i != 0) demand -= b[i-1] - carry;
        else demand -= b[n-1] - carry;

        //da ne zaidemo v negativo
        demand = max(demand, 0LL);


        //idi na naslednjo stranico
        //je dovolj placa?
        if(demand > b[i] and i < n-1){
            //error pizda ti materina
            return 2;
        }

        if(demand > amnt and i == n-1) return 1;

        //printf("using node %d, carrying %lld\n" , i, demand);

        //pripravi carry
        carry = demand;
    }
    return 0;


}


void solve(){
    cin >> n;
    a.clear();
    b.clear();

    loop(i, n){
        int temp;
        cin >> temp;
        a.pb(temp);
    }

    loop(i, n){
        int temp;
        cin >> temp;
        b.pb(temp);
    }

    //delamo bisekcijo na stranici n -> 1

    ll l = 0;
    ll r = b[n-1];
    ll mid;

    while(l <= r){
        ll mid = (l+r)/2;

        int e = check(mid);
        if(e == 0){
            cout << "YES" << endl;
            return;
        }else if(e == 2) r = mid - 1;
        else l = mid + 1;
    }

    cout << "NO" << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) solve();
}