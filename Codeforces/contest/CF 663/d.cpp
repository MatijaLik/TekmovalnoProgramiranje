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

ll solve3Mask(vector<vector<bool>> mask, ll l){

    //poglej ce je legalno
    int bad = 0;
    for(auto b :  mask[0]){
        if(!b) bad++;
    }
     if(bad == 0) return 0;
    if(bad%2) return inf;
    bad = 0;
    for(auto b :  mask[1]){
        if(!b) bad++;
    }
    if(bad%2) return inf;

    ll ans = 0;
    //imerimo vse razdalje
    bool first0 = 1;
    bool first1 = 1;
    int len0 = 0;
    int len1 = 0;
    bool bonus0 = 0;
    bool bonus1 = 0;
    loop(i, l-1){

        bool sbonus0 = 0;

        //printf("index %lld\n", i);
        if(!mask[0][i]){
            if(first0){
                len0 = 0;
                first0 = 0;
                sbonus0 = 1;
        }else{
                ans += len0;
                first0 = 1;
                //printf("ending top\n");
                //poglej nasprotni bonus
                if(!first1 and bonus1){
                    //printf("bonus\n");
                    bonus1 = 0;
                    ans--;
                }
            }
        }
        if(!mask[1][i]){
            if(first1){
                len1 = 0;
                first1 = 0;
                bonus1 = 1;
        }else{
                ans += len1;
                first1 = 1;
                //printf("ending bot\n");
                //poglej nasprotni bonus
                if(!first0 and bonus0){
                    //printf("bonus\n");
                    bonus0 = 0;
                    ans--;
                }
            }
        }
        if(sbonus0) bonus0 = 1;
        len0++;
        len1++;
    }
    /*
    printf("testing\n");
    for(int b : mask[0]) printf(" %d", b);
    printf("\n");
    for(int b : mask[1]) printf(" %d", b);
    printf("\n");
    printf("%lld\n", ans);*/
    return ans;
}

ll solve2Mask(vector<bool> mask, ll l){



    //je legalno???
    int bad = 0;
        
    for(auto b :  mask){
        if(!b) bad++;
    }
    if(bad == 0) return 0;
    if(bad % 2)return inf;

    ll ans = 0;


    //izmerimo vse razdalje
    bool first = 1;
    int len = 0;
    loop(i, l-1){
        if(!mask[i]){
            if(first){
                len = 0;
                first = 0;
            }else{
                ans += len;
                first = 1;
            }
        }
        len++;
    }
    return ans;
}

void solve(){
    int n, m;
    cin >> n >> m;
    bool grid[n][m];
    loop(i, n){
        string s;
        cin >> s;
        loop(j, m){
            char c = s[j];
            if(c == '1') grid[i][j] = 1;
            else grid[i][j] = 0;
        }
    }

    if(min(n, m) >= 4){
        cout << -1 << endl;
        return;
    }
    if(min(n, m) == 1){
        cout << 0 << endl;
        return;
    }
    if(n == 2 and m == 2){
        int cnt = 0;
        loop(i, 2)loop(j, 2) if(grid[i][j])cnt++;
        if(cnt % 2 == 0) cout << 1 << endl;
        else cout << 0 << endl;
        return;
    }

    bool g[min(n, m)][max(n, m)];

    //fukni ga podolgem
    if(n > m){
        loop(i, n)loop(j, m) g[j][i] = grid[i][j];
    }else{
        loop(i, n)loop(j, m) g[i][j] = grid[i][j];
    }

    ll l = max(n, m);
    ll w = min(n, m);
    if(w == 2){



        //1. bitmaskaj
        vector<bool> mask;
        FOR(i, 0, l-2){
            int cnt = 0;
            //prestej vse
            if(g[0][i]) cnt++;
            if(g[1][i]) cnt++;
            if(g[0][i+1]) cnt++;
            if(g[1][i+1]) cnt++;
            if(cnt % 2 == 0) mask.pb(0);
            else mask.pb(1);
        }



        
        ll best = inf;
        vector<bool> ogMask = mask;
        loop(i, 4){
            int cost = 0;
            if(i & (1 << 0)) mask[0] = 1;
            else mask[0] = 0;
            if(ogMask[0]!=mask[0])cost++;

            if(i & (1 << 1)) mask[l-2] = 1;
            else mask[l-2] = 0;
            if(ogMask[l-2]!=mask[l-2])cost++;

            best = min(best, solve2Mask(mask, l)+cost);
        }
        

        cout << best << endl;
        
    }
    else{
        //2 bitmaska
        vector<vector<bool>> mask(2);
        FOR(i, 0, l-2){
            int cnt = 0;
            //prestej vse
            if(g[0][i]) cnt++;
            if(g[1][i]) cnt++;
            if(g[0][i+1]) cnt++;
            if(g[1][i+1]) cnt++;
            if(cnt % 2 == 0) mask[0].pb(0);
            else mask[0].pb(1);
        }
        FOR(i, 0, l-2){
            int cnt = 0;
            //prestej vse
            if(g[1][i]) cnt++;
            if(g[2][i]) cnt++;
            if(g[1][i+1]) cnt++;
            if(g[2][i+1]) cnt++;
            if(cnt % 2 == 0) mask[1].pb(0);
            else mask[1].pb(1);
        }


        ll best = inf;
        vector<vector<bool>> ogMask = mask;
        
        //probaj vse
        loop(i, 16){
            int cost = 0;
            if(i & (1 << 0)) mask[0][0] = 1;
            else mask[0][0] = 0;
            if(ogMask[0][0]!=mask[0][0])cost++;

            if(i & (1 << 1)) mask[1][0] = 1;
            else mask[1][0] = 0;
            if(ogMask[1][0]!=mask[1][0])cost++;

            if(i & (1 << 2)) mask[0][l-2] = 1;
            else mask[0][l-2] = 0;
            if(ogMask[0][l-2]!=mask[0][l-2])cost++;

            if(i & (1 << 3)) mask[1][l-2] = 1;
            else mask[1][l-2] = 0;
            if(ogMask[1][l-2]!=mask[1][l-2])cost++;

            //poglejmo za bonuse
            if(
                ogMask[0][0]!=mask[0][0]
                and
                ogMask[1][0]!=mask[1][0]
            )cost--;

            if(
                ogMask[0][l-2]!=mask[0][l-2]
                and
                ogMask[1][l-2]!=mask[1][l-2]
            )cost--;

            best = min(best, solve3Mask(mask, l)+cost);
        }

        
        cout << best << endl;
    }

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
}   