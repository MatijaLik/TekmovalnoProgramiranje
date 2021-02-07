/**
 * Author: MatijaL
 * Time: 2021-02-05 15:35:01
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
    int n, m;
    cin >> n >> m;
    char adj[n][n];
    loop(i, n){
        string s;
        cin >> s;
        int j = 0;
        for(auto c : s) adj[i][j++] = c;
    }

    //najdi topcino
    loop(i, n){
        loop(j, n){
            if(i==j) continue;
            if(adj[i][j] == adj[j][i]){
                //mamo ga!
                cout << "YES" << endl;
                loop(M, m+1){
                    int c;
                    if(M%2) c = i+1;
                    else c = j+1;
                    cout << c << " ";
                }
                cout << endl;
                return;
            }
        }
    }
    
    //liha topcina
    if(m%2){
        cout << "YES" << endl;
        loop(M, m+1){
            int c;
            if(M%2) c = 1;
            else c = 2;
            cout << c << " ";
        }
        cout << endl;
        return;
    }

    //soda topcina
    if(n > 2){
        int left = 1;
        int pivot = 2;
        int right = 3;
        if(adj[left-1][pivot-1] == adj[right-1][pivot-1]){
            swap(pivot, right);
            
            if(adj[left-1][pivot-1] == adj[right-1][pivot-1]){
                swap(left, pivot);
            }
        }

        cout << "YES" << endl;
        if(m % 4 == 0){
            cout << pivot << " ";
            vector<int> v = {right, pivot, left, pivot};
            loop(M, m) cout << v[M%4] << " ";
            cout << endl;
        }
        else{
            cout << left << " ";
            vector<int> v = {pivot, right, pivot, left};
            loop(M, m) cout << v[M%4] << " ";
            cout << endl;
        }
        return;
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
