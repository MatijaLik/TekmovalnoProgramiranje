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
#define inf 1000040000
#define mod 1000000007

ll add(ll a, ll b){
    return (a+b)%mod;
}
ll sub(ll a, ll b){
    a %= mod;
    b %= mod;
    return add(a, mod-b);
}
ll mul(ll a, ll b){
    return (a*b)%mod;
}
ll binpow(ll a, ll exp){
    ll base = a%mod;
    ll res = 1;
    while(exp){
        if(exp%2) res = mul(res, base);
        base = mul(base, base);
        exp /= 2;
    }
    return res;
}
ll inv(ll a){
    return binpow(a, mod-2);
}
ll countRec(ll a, ll b, ll hmax){
    a %= mod;
    b %= mod;
    ll left = mul(a, b);
    ll lambda = hmax+1;
    ll right = mul(mul(lambda, lambda-1), inv(2));
    return mul(left, right);
}
int N;
ll height[100500];
ll width[100500];
pll segtree[400100];
ll widthrs[100500];
bool normalMode = true;

ll LEFT(int i){return 2*i;}
ll RIGHT(int i){return (2*i)+1;}
ll MID(int l, int r){return (l+r)/2;}

void segB(int i, int l, int r){
   if(l == r){
       segtree[i] = mp(height[l], l);
       return;
   }

   //rekurzivno dol
   ll m = MID(l, r);
   segB(LEFT(i), l, m);
   segB(RIGHT(i), m+1, r);

   //najdi optimum
   if(segtree[LEFT(i)].fs < segtree[RIGHT(i)].fs) segtree[i] = segtree[LEFT(i)];
   else segtree[i] = segtree[RIGHT(i)];
}

pll segQ(int i, int l, int r, int ql, int qr){
    if(qr < l or r < ql) return mp(inf, -1);
    //v celoti not
    if(ql <= l and r <= qr) return segtree[i];

    //rekurzivno obe strani
    ll m = MID(l, r);
    pll left = segQ(LEFT(i), l, m, ql , qr);
    pll right = segQ(RIGHT(i), m+1, r, ql, qr);
    if(left.fs < right.fs) return left;
    else return right;
}
ll mrg(int mid, int left, int right, int prevH){
    if(left >= mid+1 or right <= mid) return 0;
    ll ans = 0;
    /*
     * najdi najmanjsega -> countRec(left, right, visina)
     * odstej prejsnjega -> -countRec(left, right, prevH)
     * odtrani najmanjsega -> rekurzivno mrg
     */
    pll smallest;
    if(right == N or normalMode) smallest = segQ(1, 1, N, left, right);
    else smallest = mp(height[left], left);
    ll minH = smallest.fs;
    ll minId = smallest.sc;

    ll leftW = widthrs[mid] - widthrs[left-1];
    ll rightW = widthrs[right] - widthrs[mid]; 
    //assert(leftW > 0  and rightW > 0); 
    //printf("merging %lld %lld %lld %lld\n", mid, left, right, prevH);
    //printf("width %lld %lld\n", leftW, rightW);
    //1
    if(minH != prevH)ans = add(ans, countRec(leftW, rightW, minH));

    //2
    if(minH != prevH)ans = sub(ans, countRec(leftW, rightW, prevH));

    //3
    if(minId <= mid){
        ans = add(ans, mrg(mid, minId+1, right, minH));
    }else{
        ans = add(ans, mrg(mid, left, minId-1, minH));
    }
    //printf("ans -> %lld\n", ans);
    return ans;
}

ll build(int l, int r){
    //printf("Building %lld %lld\n", l, r);
    if(l == r){
        //stevilo rectanglov
        ll h = height[l];
        ll w = width[l];
        ll left = mul(mul(h+1, h), inv(2));
        ll right = mul(mul(w+1, w), inv(2));
        //printf("build return %lld %lld -> %lld\n", l, r,  mul(left, right));
        return mul(left, right);
    }

    //vsako polovico prvo posebej
    ll ans = 0;
    ll mid = (l+r)/2;
    ans = add(ans, build(l, mid));
    ans = add(ans, build(mid+1, r));

    //merge
    ans = add(ans, mrg(mid, l, r, 0));
    //printf("build return %lld %lld -> %lld\n", l, r, ans);

    return ans;
}

void solve(){
    cin >> N;
    ll totalW = 0;
    loop(i, N){
        int h;// = rand() % mod;
        cin >> h;
        height[i+1] = h;
    }
    loop(i, N){
        int w;// = rand() % mod;
        cin >> w;
        width[i+1] = w;
        totalW += w;
        //cout << totalW << endl;
        widthrs[i+1] = totalW;
    }


    //check for normal normalMode
    normalMode = false;
    FOR(i, 2, N-1){
        if(height[i-1] > height[i]){
            normalMode = true;
        }
    }
    //assert(normalMode);
    segB(1, 1, N);
    cout << build(1, N) << endl; 
}


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve(); 
}
