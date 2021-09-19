/**
 * Author: MatijaL
 * Time: 2021-05-06 16:52:46
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


#define limit 100200
#define DEBUG 1

int N;
vector<int> sosedi[limit];
vector<int> stars, dubina, jako, premec, pos;
int cur_pos = 1;


int dfs(int cur) {
    int size = 1;
    int najveci = 0;
    for (int otrok : sosedi[cur]) {
        if (otrok != stars[cur]) {
            stars[otrok] = cur, dubina[otrok] = dubina[cur] + 1;
            int velikost_otrok = dfs(otrok);
            size += velikost_otrok;
            if (velikost_otrok > najveci)
                najveci = velikost_otrok;
                jako[cur] = otrok;
        }
    }
    return size;
}

void razstavi(int cur, int vodilni) {
    premec[cur] = vodilni, pos[cur] = cur_pos++;
    if (jako[cur] != -1)
        razstavi(jako[cur], vodilni);
    for (int u : sosedi[cur]) {
        if (u != stars[cur] and u != jako[cur]){
            razstavi(u, u);
        }
    }
}

void init() {
    stars.resize(N, 0);
    dubina.resize(N, 0);
    jako.resize(N, -1);
    premec.resize(N, 0);
    pos.resize(N, 0);
    cur_pos = 0;

    dfs(0);
    razstavi(0, 0);
}

int ANS = 0;

int arr[limit];
int lazy[4*limit];

int left(int i){return 2*i;}
int right(int i){return 2*i + 1;}
int mid(int l, int r){return (l+r)/2;}

void segedinQ(int i, int l, int r, int ql, int qr, int tip){


    

    //zunaj??
    if(qr < l or r < ql) return;

    if(l == r){
        if(DEBUG)printf("farbam %d %d\n", l, r);
        arr[l] = tip;
        lazy[l] = -1;
        return;
    }

    //v celoti not?
    if(ql <= l and r <= qr){
        if(DEBUG)printf("farbam %d %d\n", l, r);
        lazy[i] = tip;
        return;
    }

    //na pol
    int m = mid(l, r);
    lazy[i] = -1;
    segedinQ(left(i), l, m, ql, qr, tip);
    segedinQ(right(i), m+1, r, ql, qr, tip);
    return;
}

void dajRezultat(int i, int l, int r){
    if(l == r){
        if(arr[l]) {
            ANS++;
            if(DEBUG) printf("%d je umazan\n", l);
        }
        return;
    }

    if(lazy[i] != -1){
        lazy[left(i)] = lazy[i];
        lazy[right(i)] = lazy[i];
    }

    int m = mid(l, r);
    dajRezultat(left(i), l, m);
    dajRezultat(right(i), m+1, r);

}

void query(int a, int b, int tip) {
    a--;
    b--;
    while(1){
        if(premec[a] == premec[b]) break;
        if (dubina[premec[a]] > dubina[premec[b]])
            swap(a, b);
        if(DEBUG) printf("query %d %d\n", pos[premec[b]], pos[b]);
        segedinQ(1, 0, N-1, pos[premec[b]], pos[b], tip);
        b = stars[premec[b]];
    }
    if (dubina[a] > dubina[b])
        swap(a, b);
    
    //a je ta zgornji
    //torej ga izkljuci
    if(a == b) return;
    if(DEBUG) printf("query %d %d\n", pos[a]+1, pos[b]);
    segedinQ(1, 0, N-1, pos[a]+1, pos[b], tip);
    
    return;
}

void sestaviGraf(){
    
    cin >> N;

    loop(i,N-1){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        sosedi[u].pb(v);
        sosedi[v].pb(u);
    }

    init();

    if(DEBUG){
        printf("###########\n");
        FOR(i, 1, N) printf("%d ", i);
        printf("\n");
        FOR(i, 0, N-1) printf("%d ", pos[i]);
        printf("\n");
        printf("###########\n");

        printf("@@@@\n");
        query(10, 7, 0);
        printf("@@@@\n");
        query(4, 8, 0);
        printf("@@@@\n");
        query(3, 1, 0);
        printf("@@@@\n");
    }
}

vector<pair<pll, pll>> dogodek; //cas 0/1 <kje, kam>


void skratBolfenk(){
    int tip, stDvoran;
    cin >> tip >> stDvoran;
    vector<int> nodes(stDvoran);
    loop(i, stDvoran) cin >> nodes[i];
    vector<int> casi(stDvoran-1);
    loop(i, stDvoran-1) cin >> casi[i];

    loop(i, stDvoran-1){
        dogodek.pb(
            mp(
                mp(casi[i], tip),
                mp(
                    nodes[i],
                    nodes[i+1]
                )
            )
        );
    }
}

void porihtajSkrate(){
    int S;
    cin >> S;
    while(S--) skratBolfenk();
    sort(all(dogodek));
    
}




void lenaPropagacijaNaSegedinGolazu(){
    loop(i, 4*limit) lazy[i] = -1;
    for(auto e : dogodek){
        if(DEBUG)
            printf("t = %d| %d - %d| tip %d\n", e.fs.fs, e.sc.fs, e.sc.sc, e.fs.sc);
        query(e.sc.fs, e.sc.sc, e.fs.sc);
    }
}



void solve(){
    sestaviGraf();
    porihtajSkrate();
    lenaPropagacijaNaSegedinGolazu();
    dajRezultat(1, 0, N-1);
    cout << ANS << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
