#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector <ll>
#define mii map<ll, ll>
#define si set<ll>
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
#define debug(x) cout << "# " << x << endl


#define nlimit 200100

ll ntree[4*nlimit];
ll stree[4*nlimit];

vector<int> normal;
vector<ll> special;

int left(int i){ return (2*i);}
int right(int i){ return (2*i)+1;} 

int N, Q;

void build(int index, int l, int r){
    int mid = (l+r)/2;
    if(l==r){
        ntree[index] = normal[l];
        stree[index] = special[l];
    }else{
        build(left(index), l, mid);
        build(right(index), mid+1, r);

        ntree[index] = ntree[left(index)] + ntree[right(index)];
        stree[index] = stree[left(index)] + stree[right(index)];
    }
}

void update(int index, int l, int r, int loc, int newVal){
    if(loc < l or r < loc) return;
    if(l == loc and r == loc){//smo v listu
        int nVal = newVal;
        int sVal = loc*newVal;

        if(loc%2==0){
            nVal = -nVal;
            sVal = -sVal;
        }

        normal[loc] = nVal;
        ntree[index] = nVal;

        special[loc] = sVal;
        stree[index] = sVal;


    }else{
        int mid = (l+r)/2;
        update(left(index), l, mid, loc, newVal);
        update(right(index), mid+1, r, loc, newVal);

        ntree[index] = ntree[left(index)] + ntree[right(index)];
        stree[index] = stree[left(index)] + stree[right(index)];
    }
}

ll query(int tree, int index, int l, int r, int ql, int qr){
    if(qr < l or r < ql) return 0;
    if(ql <= l and r <= qr){
        if(tree) return stree[index];
        else return ntree[index];
    }else{
        int mid = (l+r)/2;
        ll sum = 0;
        sum += query(tree, left(index), l, mid, ql, qr);
        sum += query(tree, right(index), mid+1, r, ql, qr);
        return sum;
    }
}

ll preQuery(int l, int r){
    ll ans = 0;
    ans += query(1, 1, 1, N, l, r);
    if(l%2==0) ans *= (-1);
    //printf("first sum %d\n", ans);

    ll adj = query(0, 1, 1, N, l, r);
    //printf("second %d\n", adj);
    if(l%2==0) ans += (l-1)*adj;
    else ans -= (l-1)*adj;
    return ans;
}




void solve(int cs){
    //pocisti
    loop(i, 4*nlimit){ntree[i] = 0; stree[i] = 0;}
    normal.clear();
    special.clear();


    ll result = 0;

    cin >> N >> Q;
    normal.pb(0);
    special.pb(0);
    loop(i, N){
        int temp;
        cin >> temp;
        if(i%2==0)normal.pb(temp);
        else normal.pb(-temp);
    }

    FOR(i, 1, N){
        if(i%2==1){
            special.pb(i*normal[i]);
        }else{
            special.pb(i*normal[i]);
        }
    }

    build(1, 1, N);
    /*
    printf("normal\n");
    loop(i, 2*N){
        cout << ntree[i] <<" ";
    }
    cout << endl;

    printf("normal\n");
    loop(i, 2*N){
        cout << stree[i] <<" ";
    }
    cout << endl;
    */
    

    loop(i, Q){
        char c;
        cin >> c;
        if(c=='Q'){
            int a, b;
            cin >> a >> b;
            result += preQuery(a, b);
        }else{
            int a, b;
            cin >> a >> b;
            update(1, 1, N, a, b);
        }
    }


    printf("Case #%d: %lld\n", cs, result);
}


int main(){
    int t;
    cin >> t;
    int i = 1;

    while(t--)solve(i++);
}