#include <bitset>
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<ll, ll>
#define pli pair<long long, ll>
#define vi vector <ll>
#define mii map<ll, ll>
#define si set<ll>
#define loop(i, n) for(int i = 0; i < n; i++)
#define FOR(i,n,m) for(int i = n; i < m; i++)
#define isIn(vec, item) find(vec.begin(), vec.end(), item) != vec.end()
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define inf 999999999
#define mod 1000000007
#define debug(x) cout << "# " << x << endl;


struct Comparer {
    bool operator() (const pair<bitset<105>,bitset<105>>  &b1, const pair<bitset<105>,bitset<105>> &b2) const {
        if(b1.first.to_ulong() == b2.first.to_ulong()){
            return b1.second.to_ulong() < b2.second.to_ulong();
        }else{
            return b1.first.to_ulong() < b2.first.to_ulong();
        }
        
    }
};
map<pair<bitset <105>, bitset <105>>, int, Comparer> memo;

int r1[105];
int r2[105];
int n;
vector <int> v1;
vector <int> v2;
int tres;
int dp(bitset <105> u1, bitset <105> u2, int cost){
    if(memo[mp(u1, u2)]){
        if(memo[mp(u1, u2)] == 420){
            return 0;
        }else{
            return memo[mp(u1, u2)];
        }
    }
    loop(i, n-1){
        if(!u1[i]){
            int mini = 105;
            loop(j, n-1){
                if(!u2[j]){
                    bitset<105> n1, n2;
                    n1 = u1 | bitset<105>(1 << i);
                    n2 = u2 | bitset<105>(i << j);
                    if(v1[i] + v2[j] <= tres){
                        mini = min(mini, dp(n1, n2, cost+1));
                    }else{
                        mini = min(mini, dp(n1, n2, cost));
                    }
                }
            }
            return memo[mp(u1, u2)] = mini;
        }
    }
    return 0;



}


int main(){
    int t;
    cin >> t;
    loop(i, t){
        int a, b;
        n = 0;
        cin >> n >> a >> b;
        tres = a + b;
        int x = min(a,b) - 1;
        int y = n - max(a,b); 


        //best case
        /*
        FOR(i,1, n+1){
            if(i!=a) v1.pb(i);
        }
        FOR(i,1, n+1){
            if(i!=b) v2.pb(i);
        }
        bitset <105> t1, t2;
        cout << dp(t1,t2,0) + 1 << " "; 
        */

        int best = 1;
        if(y > x){
            cout << 1 << " ";
        }else if (max(a,b) == n){
            cout << n - abs(a-b) + 1<< " ";
        }else{
            i = 1;
            while( i < min(a,b)){
                if(i + n <= tres){
                    best++;
                    i++;
                }else{
                    break;
                }
            }
            cout << best << " ";
        }

        //worst case
        int w = 1;
        w += abs(a-b);
        w += 2*(min(x,y));
        if(x > y){
            w += x - y;
        }

        cout << w << endl;
    }
}