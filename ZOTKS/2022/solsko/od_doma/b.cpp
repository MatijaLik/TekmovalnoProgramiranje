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

#define DEBUG 0
struct TipKandidata{
    int V, W, X, id;
    TipKandidata(int _V, int  _W,int _X, int _id): V(_V), W(_W), X(_X), id(_id){};

    bool operator<(TipKandidata &other){
        if(V == other.V) return id < other.id;
        return V > other.V;
    }
};

struct Kandidat{
    int V;
    Kandidat(int _V): V(_V){}
};

struct MasniRazred{
    int W;
    vector<TipKandidata> vrste;
    vector<Kandidat> folk;
    MasniRazred(int _W):W(_W){};
    void ustvariKandidate(){
        sort(all(vrste));
        int kvota = 2050/W;
        for(auto e : vrste){
            if(kvota == 0) break;
            int x = min(kvota, e.X);
            loop(i, x){
                folk.pb(Kandidat(e.V));
            }
            kvota -= x;
        }
        if(DEBUG) prnt();
    }
    void prnt(){
        printf("Masni razred %d\n", W);
        for(auto e : folk) printf("%d ", e.V);
        printf("\n");
    }
};

void solve(){
    int N, K;
    cin >> K >> N;

    vector<MasniRazred> klase;
    FOR(w, 0, K)klase.pb(MasniRazred(w));
    
    loop(i, N){
        int a, b,c;
        cin >> a >> b >> c;
        TipKandidata t = TipKandidata(a, b, c, i);
        klase[b].vrste.pb(t);
    }

    FOR(w, 1, K) klase[w].ustvariKandidate();

    ll DP[2050][2050];
    memset(DP, 0, sizeof DP);
    FOR(w, 1, K){
        FOR(rem, 0, K){
            ll ludi = 0;
            int x = 0;
            while(true){
                DP[w][rem] = max(DP[w][rem], ludi + DP[w-1][rem-x*w]);

                if(x < klase[w].folk.size() 
                and (x+1)*w <= rem
                ){
                    ludi += klase[w].folk[x].V;
                    x++;
                }else{
                    break;
                } 
            }
            if(DEBUG)cout << DP[w][rem] << " ";
            
        }
        if(DEBUG)cout << endl;
    }
    cout << DP[K][K] << endl;
    
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
}