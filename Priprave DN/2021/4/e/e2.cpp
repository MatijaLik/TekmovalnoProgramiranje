/**
 * Author: MatijaL
 * Time: 2020-12-08 16:24:12
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
#define nlimit 100100

/*
struct Rect{
    int a,b,c,d;
    vector<int> sosedi[4];
    Rect(int _a, int _b, int _c, int _d){
        a = _a;
        b = _b;
        c = _c;
        d = _d;
    }
};
*/

bool bad[nlimit][4];

int lowlink[nlimit][4];
int dfsNum[nlimit][4];
int component[nlimit][4];

bool visited[nlimit][4];
bool hot[nlimit][4];

int curComp = 1;
stack<pll> s;
int cas = 1;
vector<pll> sosedi[nlimit][4]; 
vector<pll> par[nlimit][4];

/*
void dfs(pll node){
    ll shape = node.fs;
    ll side = node.sc;
    //printf("dfs %d\n", node);
    s.push(node);
    lowlink[shape][side] = cas;
    dfsNum[shape][side] = cas++;
    for(auto sosed : sosedi[shape][side]){
        ll ssh = sosed.fs;
        ll ssi = sosed.sc;
        if(dfsNum[ssh][ssi] == 0){//neobiskano
            dfs(sosed);
            lowlink[shape][side] = min(lowlink[shape][side], lowlink[ssh][ssi]);
        }
        if(dfsNum[ssh][ssi] != -1){
            lowlink[shape][side] = min(lowlink[shape][side], dfsNum[ssh][ssi]);
        }
    }
    if(lowlink[shape][side] == dfsNum[shape][side]){
        //printf("clearing node %d\n", node);
        pll popped;
        bool badMode = 0;
        if(s.top() == node) badMode = 1;
        while(1){
            popped = s.top();
            s.pop();
            dfsNum[popped.fs][popped.sc] = -1;
            component[popped.fs][popped.sc] = curComp;
            //printf("popped %d\n", popped);
            if(badMode){
                bad[popped.fs][popped.sc] = true;
            }
            if(popped == node)break;
        }
        curComp++;
    }
    
}
*/
bool dfs(pll node){
    ll shape = node.fs;
    ll side = node.sc;
    bool wack = 0;
    hot[shape][side] = true;
    //printf("in %c%lld\n", shape+'A', side);
    for(auto sosed : sosedi[shape][side]){
        ll ssh = sosed.fs;
        ll ssi = sosed.sc;
        if(visited[ssh][ssi]) wack = wack or bad[ssh][ssi];
        else if (hot[ssh][ssi]) wack = true;
        else wack = wack or dfs(sosed);
    }
    hot[shape][side] = false;
    visited[shape][side] = true;
    //printf("out %c%lld -> %d\n", shape+'A', side, wack);
    return bad[shape][side] = wack;
}


void solve(){
    int N;
    cin >> N;

    //nastavi arraye
    loop(i, nlimit)loop(j, 4){
        lowlink[i][j] = 0;
        dfsNum[i][j] = 0;
        component[i][j] = -1;
    }


    vector<pair<pair<pll,pll>, ll>> hScan;
    vector<pair<pair<pll,pll>, ll>> vScan;
    loop(i, N){
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        hScan.pb(mp(mp(mp(a, 1), mp(d, b)), i));
        hScan.pb(mp(mp(mp(c, 0), mp(d, b)), i));

        vScan.pb(mp(mp(mp(b, 1), mp(a, c)), i));
        vScan.pb(mp(mp(mp(d, 0), mp(a, c)), i));
    }

    //point (x, on/off, top, bot, id)

    //od leve v desno
    sort(all(hScan));
    sort(all(vScan));
    set<pll> bots; //<y, id>
    set<pll> tops; // <y, id>

    vector<pair<pair<pll,pll>, ll>> batch;
    ll prev = -1;
    for(auto p : hScan){
        int X = p.fs.fs.fs;
        if(X == prev)batch.pb(p);
        else{
            //prvo pocitsti
            prev = X;
            for(auto e : batch){
                //najdi presecisce
                ll x = e.fs.fs.fs;
                ll opt = e.fs.fs.sc;
                ll top = e.fs.sc.fs;
                ll bot = e.fs.sc.sc;
                ll id = e.sc;

                //dodaj v queue
                if(opt == 1){
                    continue;
                }else{
                    //printf("removing  %c %lld %lld %lld\n", (char)id+'A', top, bot, id);
                    bots.erase(bots.find(mp(bot, id)));
                    tops.erase(tops.find(mp(top, id)));
                    
                }
            }
            for(auto e : batch){
                //najdi presecisce
                ll x = e.fs.fs.fs;
                ll opt = e.fs.fs.sc;
                ll top = e.fs.sc.fs;
                ll bot = e.fs.sc.sc;
                ll id = e.sc;
                //glej gor
                auto it = bots.lower_bound(mp(top, -1));
                if(it != bots.end()){
                    pll p = *it;
                    sosedi[id][1 - opt].pb(mp(p.sc, 3));
                    par[p.sc][3].pb(mp(id, 1-opt));
                }
                //glej dol
                it = tops.upper_bound(mp(bot+1, -1));
                if(it != tops.begin()){
                    pll p = *(--it);
                    sosedi[id][1-opt].pb(mp(p.sc, 2));
                    par[p.sc][2].pb(mp(id, 1-opt));
                }

            }
            for(auto e : batch){
                //najdi presecisce
                ll x = e.fs.fs.fs;
                ll opt = e.fs.fs.sc;
                ll top = e.fs.sc.fs;
                ll bot = e.fs.sc.sc;
                ll id = e.sc;

                //dodaj v queue
                if(opt == 1){
                    //printf("adding %c, %lld %lld %lld\n", (char)id+'A', top, bot, id);
                    bots.insert(mp(bot, id));
                    tops.insert(mp(top, id));
                    
                }else{
                    continue;
                }
            }
            batch.clear();
            batch.pb(p);
        }  
    }

    batch.clear();
    prev = -1;
    set<pll> lefts, rights;


    for(auto p : vScan){
        int X = p.fs.fs.fs;
        if(X == prev)batch.pb(p);
        else{
            //prvo pocitsti
            prev = X;
            for(auto e : batch){
                ll x = e.fs.fs.fs;
                ll opt = e.fs.fs.sc;
                ll left = e.fs.sc.fs;
                ll right = e.fs.sc.sc;
                ll id = e.sc;

                //dodaj v queue
                if(opt == 1){
                    continue;
                }else{
                    //printf("removing  %c\n", (char)id+'A');
                    lefts.erase(lefts.find(mp(left, id)));
                    rights.erase(rights.find(mp(right, id)));
                    
                }
            }
            for(auto e : batch){
                //najdi presecisce
                ll x = e.fs.fs.fs;
                ll opt = e.fs.fs.sc;
                ll left = e.fs.sc.fs;
                ll right = e.fs.sc.sc;
                ll id = e.sc;
                //glej desno
                auto it = lefts.lower_bound(mp(right, -1));
                if(it != lefts.end()){
                    pll p = *it;
                    sosedi[id][2 + opt].pb(mp(p.sc, 0));
                    par[p.sc][0].pb(mp(id, 2+opt));
                }
                //glej levo
                it = rights.upper_bound(mp(left+1, -1));
                if(it != rights.begin()){
                    pll p = *(--it);
                    sosedi[id][2 + opt].pb(mp(p.sc, 1));
                    par[p.sc][1].pb(mp(id, 2+opt));
                }

            }
            for(auto e : batch){
                ll x = e.fs.fs.fs;
                ll opt = e.fs.fs.sc;
                ll left = e.fs.sc.fs;
                ll right = e.fs.sc.sc;
                ll id = e.sc;

                //dodaj v queue
                if(opt == 1){
                    //printf("adding %c\n", (char)id+'A');
                    lefts.insert(mp(left, id));
                    rights.insert(mp(right, id));
                    
                }else{
                    continue;
                }
            }
            batch.clear();
            batch.pb(p);
        }  
    }
    
    /*
    //izpisi vse
    loop(i, N)loop(j, 4){
        printf("//////////////////\n");
        printf("%c%lld\n", (char)(i+'A'), j);
        printf("children:");
        for(auto e : sosedi[i][j]){
            printf(" %c%lld", (char)(e.fs+'A'), e.sc);
        }
        printf("\n");
        printf("parents:");
        for(auto e : par[i][j]){
            printf(" %c%lld", (char)(e.fs+'A'), e.sc);
        }
        printf("\n");
    }*/


    loop(i, N)loop(j, 4){
        if(!visited[i][j]) dfs(mp(i, j));
    }
    loop(i, N){
        bool a, b, c, d;
        a = bad[i][0];
        b = bad[i][1];
        c = bad[i][2];
        d = bad[i][3];
        //printf("Shape %c: %d %d %d %d\n", i+'A', a, b, c, d);
        if((a and b) or (b and c) or (c and d) or (d and a)){
            //printf("Shape %c bad\n", i+'A');
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");

    

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
