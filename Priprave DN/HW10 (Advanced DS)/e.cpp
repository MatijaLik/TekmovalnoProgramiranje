#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
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


#define nol 26 //number of letters
#define limit 100100 // zgornja meja za n

ll N, Q;
ll nums[nol][limit];
ll seg[nol][4*limit];
ll lazy[nol][4*limit];
ll lcnt[nol];

ll MID(ll a, ll b){ return (a+b)/2;}

ll build(ll l, ll r, ll i, ll letter){
    ll mid = MID(l, r);
    if(l == r) return seg[letter][i] = nums[letter][l]; // list
    return seg[letter][i] = 
        build(l, mid, 2*i, letter)+
        build(mid+1, r, 2*i + 1, letter);
}

ll getRange(ll ql, ll qr, ll l, ll r, ll i, ll letter){
    ll mid = MID(l, r);
    if(lazy[letter][i] != -1){
        //cout << "feed forward " << letter << " " << l << " " << r << " " << lazy[letter][i] << endl;
        if(lazy[letter][i] == 0) seg[letter][i] = 0;
        else seg[letter][i] = lazy[letter][i];
        if(l != r){// posreduj navzdol
            if(lazy[letter][i]){
                lazy[letter][i*2] = mid-l+1;
                lazy[letter][i*2 + 1] = r-mid;
            }else{
                lazy[letter][i*2] = 0;
                lazy[letter][i*2 + 1] = 0;
            }
            
        }
        lazy[letter][i] = -1;
    }

    //out of range
    if(qr < l or r < ql) return 0;

    //v celoti notri
    if(ql <= l and r <= qr) return seg[letter][i];

    //malo sem pa malo taj
    
    return getRange(ql, qr, l, mid, 2*i, letter)+
    getRange(ql, qr, mid+1, r, 2*i+1, letter);
}

void update(ll ql, ll qr, ll l, ll r, ll i, ll diff, ll letter){

    ll mid = MID(l, r);
    if(lazy[letter][i] != -1){
        //cout << "feed forward " << letter << " " << l << " " << r << " " << lazy[letter][i] << endl;
        if(lazy[letter][i] == 0) seg[letter][i] = 0;
        else seg[letter][i] = lazy[letter][i];
        if(l != r){// posreduj navzdol
            if(lazy[letter][i]){
                lazy[letter][i*2] = mid-l+1;
                lazy[letter][i*2 + 1] = r-mid;
            }else{
                lazy[letter][i*2] = 0;
                lazy[letter][i*2 + 1] = 0;
            }
            
        }
        lazy[letter][i] = -1;
    }

    if(qr < l or r < ql) return;//out of range
    if(ql <= l and r <= qr){
        if(diff == 1) seg[letter][i] = r-l+1; // v celoti notri
        else seg[letter][i] = 0;
        
        if(l!=r){
            // ce ni list, poslji update naprej
            //cout << "range is " << l << " " << r << endl;
            if(diff == 1){
                lazy[letter][2*i] = mid-l+1;
                lazy[letter][2*i+1] = r-mid;
                //cout << "setting lazy to " <<  (r-l+1)/2 << endl;
            }else{
                lazy[letter][2*i] = 0;
                lazy[letter][2*i+1] = 0;
                //cout << "setting lazy to " <<  0 << endl;
            }
            
        }
        return;
    }
    update(ql, qr, l, mid, 2*i, diff, letter);
    update(ql, qr, mid+1, r, 2*i + 1, diff, letter);
    seg[letter][i] = seg[letter][2*i] + seg[letter][2*i+1];
}

void print(){
    //print
    char ans[limit+10];
    memset(ans, '0', sizeof ans);
    FOR(letter, 0, nol){
        FOR(index, 1, N+1){
            if(getRange(index, index,1, limit, 1, letter)) {                
                ans[index] = (char)(letter + 97);
            }
        }
    }

    FOR(i, 1, N+1) cout << ans[i];
    cout << endl;
}

int main(){
    //auto start = high_resolution_clock::now();
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cout << "start" << endl;
    memset(lazy, -1, sizeof lazy);
    cin >> N >> Q;
    string s;
    cin >> s;

    //build
    for(ll i = 0; i < s.length(); i++){
        char c = s[i];
        nums[(int)c - 'a'][i+1] = 1;
        lcnt[(int)c - 'a']++;
    }
    FOR(letter, 0, nol) build(1, limit, 1, letter);

    //queries
    loop(q, Q){
        ll a, b, k;
        cin >> a >> b >> k;
        ll cnt = 0;

        if(k){
            FOR(letter, 0, nol){
                //debug("#####");
                ll amnt = getRange(a, b, 1, limit, 1, letter);//count
                if(amnt){
                    update(a, b, 1, limit, 1, 0, letter);//clear

                    update(a+cnt, a+cnt+amnt-1, 1, limit, 1, 1, letter);//fill
                }
                cnt+=amnt;
            }
        }else{
            for(int letter = nol-1; letter >= 0; letter--){
                ll amnt = getRange(a, b, 1, limit, 1, letter);//count
                if(amnt){
                    update(a, b, 1, limit, 1, 0, letter);//clear
                    if(amnt)update(a+cnt, a+cnt+amnt-1, 1, limit, 1, 1, letter);//fill
                }
                cnt+=amnt;
            }
        }
        //print();
    }
    //auto stop = high_resolution_clock::now();
    print();
    //auto duration = duration_cast<microseconds>(stop - start); 
    //cout << duration.count() << endl;
    return 0;
}