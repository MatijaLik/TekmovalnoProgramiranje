/**
 * Author: MatijaL
 * Time: 2021-06-18 20:13:08
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

#define DEBUG 1

int N;

vector<int> ans;
vector<int> sosedi[200500];
int subtreesize[200500];

int chosenBranch = -1;
int miniColor, midiColor;

void dfs(int node, int prev){
    subtreesize[node] = 1;
    for(auto e : sosedi[node]){
        if(e != prev) {
            dfs(e, node);
            subtreesize[node] += subtreesize[e];
        }
    }
    //printf("subtreesize of %d is %d\n", node, subtreesize[node]);
    return;
}

void dfsFill(int node, int prev, int rem, int color){
    //printf("dfs fill %d %d %d\n", node, rem, color);
    if(node == prev){
        //zacetek
        if(color == miniColor) dfsFill(chosenBranch, node, rem, color);
        else{
            ans[node] = midiColor;
            rem--;
            for(auto e : sosedi[node]){
                if(rem <= 0) break;
                if(e != chosenBranch) {
                    dfsFill(e, node, min(subtreesize[e], rem), color);
                    rem -= subtreesize[e];
                }
                       
            }
        }
    }else{
        ans[node] = color;
        rem--;
        for(auto e : sosedi[node]){
            if(rem <= 0 or e == prev) continue;
            dfsFill(e, node, min(subtreesize[e], rem), color);
            rem -= subtreesize[e];
        }
    }
}

int largest(int node){
    int mx = 0;
    int mxe = 0;
    for(auto e : sosedi[node]){
        if(subtreesize[e] < subtreesize[node]){
            if(subtreesize[e] > mx){
                mx = subtreesize[e];
                mxe = e;
            }
        }
        else{
            if(N - subtreesize[node]> mx){
                mx = N - subtreesize[node];
                mxe = e; 
            }
        }
    }
    //printf("largest of %d is %d with size %d\n", node, mxe, mx);
    if(mx > N/2) return mxe;
    else return -1;
}



vector<int> find_split(int n, int a, int b, int c, vector<int> p, vector<int> q){
    N = n;
    loop(i, p.size()){
        sosedi[p[i]].pb(q[i]);
        sosedi[q[i]].pb(p[i]);
    }
    
    
    

    int mini = min(a, min(b, c));
    int midi = a + b + c - mini - max(a, max(b, c));

    dfs(0, 0);
    int centroid = 0;
    while(largest(centroid) != -1) centroid = largest(centroid);
    dfs(centroid, centroid);

    //printf("centroid is %d\n", centroid);

    for(auto e : sosedi[centroid])
        if(subtreesize[e] >= mini){
            chosenBranch = e;
            break;
        }

    if(chosenBranch == -1){
        // zafukali smo
        ans.resize(n, 0);
        return ans;
    }

    //printf("selectedBranch is %d\n", chosenBranch);

    if(a == mini) miniColor = 1;
    else if(b == mini) miniColor = 2;
    else miniColor = 3;

    if(c == midi) midiColor = 3;
    else if(b == midi) midiColor = 2;
    else midiColor = 1;

    ans.resize(n, 6 - midiColor - miniColor);
    dfsFill(centroid, centroid, mini, miniColor);
    dfsFill(centroid, centroid, midi, midiColor);

    return ans;
}


void solve(){
    int n, m;
    cin >> n >> m;
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> p(m), q(m);
    loop(i, m){
        int x, y;
        cin >> x >> y;
        p[i] = x;
        q[i] = y;
    }

    print(find_split(n, a, b, c, p, q));
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
