/**
 * Author: MatijaL
 * Time: 2020-10-11 11:05:02
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


int segtree[4*200200];
int left(int i){return 2*i;}
int right(int i){return 2*i +1;}

int mid(int l, int r){return (l+r)/2;}

void insert(int i, int l, int r, int ql, int qr){
    if(qr < l or r < ql) return;
    
    //v celoti not
    if(ql <= l and r <= qr){
        segtree[i]++;
        return; 
    }   
    int MID = mid(l, r);
    insert(left(i), l, MID, ql, qr);
    insert(right(i), MID+1, r, ql, qr);
}

int query(int i, int l, int r, int val){
    if(val < l or r < val) return 0;

    int res = segtree[i];
    if(l == r) return res;

    int MID = mid(l, r);
    res+=query(left(i), l, MID, val);
    res+=query(right(i), MID+1, r, val);
    return res;
}

void solve(){
    int N;
    cin >> N;
    string s;
    cin >> s;

    stack<int> indeces[26];

    loop(i, N){
        char c = s[i];
        int letter = (int)c - 'a';
        int index = N - i;
        indeces[letter].push(index);
    }

    int v[N];
    loop(i, N){
        char c = s[i];
        int letter = (int)c - 'a';
        v[i] = indeces[letter].top();
        indeces[letter].pop();
    }
    
    
    ll cnt = 0;
    loop(i, N) { 
        cnt += query(1, 1, N, v[i]);
        insert(1, 1, N, 1, v[i]);
    }

    cout << cnt << endl;
}



int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
