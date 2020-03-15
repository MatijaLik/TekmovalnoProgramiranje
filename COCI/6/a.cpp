#include <bitset>
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>
#include <stack>
#include <set>
#include <stdio.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector <ll>
#define mii map<ll, ll>
#define si set<ll>
#define loop(i, n) for(ll i = 0; i < n; i++)
#define FOR(i,n,m) for(ll i = n; i < m; i++)
#define isIn(vec, item) find(vec.begin(), vec.end(), item) != vec.end()
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define inf INT_MAX
#define mod 1000000007
#define debug(x) cout << "# " << x << endl;

vector<ll> validYears;
int N;
int months[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int cti(char c){
    return (int)c  - '0';
}

void getValidYears(){
    FOR(m, 1, 13){
        FOR(d, 1, months[m-1]+1){
            ll year = 0;
            year = (m%10)*1000 + (m/10)*100 + (d%10)*10 + (d/10);   
            if(d==29&&m==2){
                if(year%4==0 and year%100 != 0){
                    validYears.pb(year);
                }
            }else{
                validYears.pb(year);
            }
            //cout << year << endl;
        }
    }
}

void solve(){
    ll d, m, y;
    string s;
    cin >> s;
    d = cti(s[0])*10 + cti(s[1]);
    m = cti(s[3])*10 + cti(s[4]);
    y = cti(s[6])*1000 + cti(s[7])*100 + cti(s[8])*10 + cti(s[9]);
    //debug(d);
    //debug(m);
    //debug(y);
    for(ll i = 0; i < validYears.size(); i++){
        ll year = validYears[i];
        //cout << year << endl;
        if(year > y){
            ll nm = year/1000 + ((year/100)%10)*10;
            ll nd = (year/10)%10 + (year%10)*10;
            //debug(nd);
            //debug(nm);
            //debug(year);
            printf("%02d.%02d.%04d.\n", nd, nm, year);
            return;
        }
    }
}


int main(){
    getValidYears();
    sort(all(validYears));
    cin >> N;
    loop(i, N)solve();
}