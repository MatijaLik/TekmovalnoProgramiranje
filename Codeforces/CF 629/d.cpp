#include <bitset>
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>
#include <stack>
#include <set>
#include <map>
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


void print1(ll n){
    cout << 1 << endl;
    loop(i, n) cout << 1 << " ";
    cout << endl;
}

void print2(ll n){
    cout << 2 << endl;
    int color = 1;
    loop(i, n){
        if(color) cout << 1 << " ";
        else cout << 2 << " ";
        color = 1-color;
    }
    cout << endl;
}
void print2s(ll clust, ll n){
    cout << 2 << endl;
    int color = 1;
    loop(i, n){
        if(color) cout << 1 << " ";
        else cout << 2 << " ";
        if(i!=clust)color = 1-color;
    }
    cout << endl;
}


void print3(ll n){
    cout << 3 << endl;
    int color = 0;
    loop(i, n){
        if(i==n-1) cout << 3 << " ";
        else if(color == 0) cout << 1 << " ";
        else if (color == 1)cout << 2 << " ";
        color = 1-color;
    }
    cout << endl;
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        //cout << "@@@@" << endl;
        vector<ll> v;
        loop(i, n){
            ll temp;
            cin >> temp;
            v.pb(temp);
        }

        //poglej ce so vsi isti
        bool dif = 0;
        FOR(i, 1, n-1){
            if(v[i] != v[i-1]){
                dif = 1;
                break;
            }
        }
        if(!dif){
            print1(n);
            continue;
        }

        if(n%2==0){
            print2(n);
            continue;
        }


        ll clust = -1;
        //najdi cluster
        FOR(i, 0, n-1){
            ll a = i-1;
            if(a == -1) a = n-1;
            if(v[i] == v[a]){
                clust = a;
                break;
            }
        }
        if(clust != -1){
            //printf("clust is %d\n", clust);
            print2s(clust, n);
        }else{
            print3(n);
        }


    }
}