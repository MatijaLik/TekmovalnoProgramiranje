/**
 * Author: MatijaL
 * Time: 2020-11-14 15:02:23
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

void solve(){
    int n;
    cin >> n;
    ll top = 0;
    ll bot = inf;

    ll cur = 0;

    string s;
    cin >> s;
    loop(i, n){
        char c = s[i];
        if(c == '+') cur++;
        if(c == '-') cur--;
        top = max(top, cur);
        bot = min(bot, cur);
    }

    if(top <= 0) top = 0;
    if(bot >= 0) bot = 0;

    int size = top+abs(bot);
    int start = top-1;

    if(size == 0){
        size = 1;
        start = 0;
    }

    //cout << top << " " << bot << endl;

    char grid[size][n];
    loop(i, size) loop(j, n) grid[i][j] = '.';
    bool error = 0;

    loop(i, n){
        char c = s[i];
        if(c == '+'){
            grid[start][i] = '/';
            start--;
        }
        else if(c == '-'){
            start++;
            grid[start][i] = '\\';
            
        }
        else{
            if(start == -1) error = true;
            grid[start][i] = '_';
        }
    }

    if(error){


        //cout << "error " << endl;
        
        size++;
        start = top;
        char ngrid[size][n];
        loop(i, size) loop(j, n) ngrid[i][j] = '.';
        loop(i, n){
            char c = s[i];
            if(c == '+'){
                ngrid[start][i] = '/';
                start--;
            }
            else if(c == '-'){
                start++;
                ngrid[start][i] = '\\';
                
            }
            else{
                if(start == -1) error = true;
                ngrid[start][i] = '_';
            }
        }
        loop(i, size){
            loop(j, n) cout << ngrid[i][j];
            cout << endl;
        } 
    }else{
        loop(i, size){
            loop(j, n) cout << grid[i][j];
            cout << endl;
        } 
    }

    


}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
