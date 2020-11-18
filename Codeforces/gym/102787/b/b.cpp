/**
 * Author: MatijaL
 * Time: 2020-10-28 15:01:56
 * 
 * Ideja: Treap s hashanjem poddrevesa 
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

const int limit = 700100;
const int MOD = mod;
const int base = 26;

int add(int x, int y)
{
	return (x + y) % MOD;
}
int sub(int x, int y)
{
	return add(x, MOD - y);
}
int mul(int x, int y)
{
	return (x * 1ll * y) % MOD;
}
ll shift[limit];

void preCompShift(){
    shift[0] = 1;
    FOR(i, 1, limit-1) shift[i] = mul(base,shift[i-1]);
}

mt19937 mt_rand(time(0));

struct Treap {
	int data, priority;
	vector<Treap*> kids;
	int subtreeSize, preHash, sufHash;

	Treap(char _letter);
};

int size(Treap *me) {
	return me == NULL ? 0 : me->subtreeSize;
}

void recalc(Treap *me) {
	if (me==NULL) return;
	me->subtreeSize = 1;
    for (Treap* t:me->kids) if (t != NULL) me->subtreeSize += t->subtreeSize;

    //PreHash
	ll _preHash = 0;
    if(me->kids[0] != NULL) _preHash += me->kids[0]->preHash;
    _preHash = add(_preHash, mul(me->data , shift[size(me->kids[0])]));
    if(me->kids[1] != NULL) _preHash = add(_preHash, mul(me->kids[1]->preHash , shift[size(me->kids[0])+1]));
    me->preHash = _preHash;

	//SufHash
    ll _sufHash = 0;
    if(me->kids[1] != NULL) _sufHash += me->kids[1]->sufHash;
    _sufHash = add(_sufHash, mul(me->data , shift[size(me->kids[1])]));
    if(me->kids[0] != NULL) _sufHash = add(_sufHash, mul(me->kids[0]->sufHash , shift[size(me->kids[1])+1]));
    me->sufHash = _sufHash;
}

Treap* merge(Treap *l, Treap *r) {
	if (l==NULL) return r;
	if (r==NULL) return l;
	if (l->priority < r->priority) {
		l->kids[1]=merge(l->kids[1], r);
		recalc(l);
		return l;
	}
	else {
		r->kids[0]=merge(l, r->kids[0]);
		recalc(r);
		return r;
	}
}

vector<Treap*> split(Treap *me, int nInLeft) {
	if (me == NULL) return {NULL, NULL};
	if (size(me->kids[0])>=nInLeft) {
		vector<Treap*> leftRes=split(me->kids[0], nInLeft);
		me->kids[0]=leftRes[1];
		recalc(me);
		return {leftRes[0], me};
	}
	else {
		nInLeft = nInLeft - size(me->kids[0]) - 1;
		vector<Treap*> rightRes = split(me->kids[1], nInLeft);
		me->kids[1] = rightRes[0];
		recalc(me);
		return {me, rightRes[1]};
	}
	return {NULL, NULL};
}

Treap::Treap(char _letter) {
	kids={NULL, NULL};
	data = (int)(_letter) - 'a';
    preHash = 0;
    sufHash = 0;

	recalc(this);
	
	priority = mt_rand();
}

Treap* mt;
vector<Treap> v(limit, Treap('a'));
int N, Q;
int freeSpace = 300100;

void remove(){
	int l, r;
	cin >> l >> r;


	// A M B --> A B
	Treap *A, *M, *B;
	vector<Treap*> h;
	h = split(mt, l-1);
	A = h[0];

	h = split(h[1], r-l+1);
	M = h[0];
	B = h[1];

	mt = merge(A, B);
} 

void insert(){
	char c;
	int p;
	cin >> c >> p;

	//A B ---> A I B
	Treap *A, *B;
	v[freeSpace] = Treap(c);
	Treap * I = &v[freeSpace];

	vector<Treap*> h;
	h = split(mt, p-1);
	A = h[0];
	B = h[1];

	mt = merge(A, I);
	mt = merge(mt, B);

	freeSpace++;
}

void palindrome(){
	if(mt == NULL) {cout << "yes" << endl; return;}
	int l, r;
	cin >> l >> r;

	//A M B
	Treap *A, *M, *B;
	vector<Treap*> h;
	h = split(mt, l-1);
	A = h[0];

	h = split(h[1], r-l+1);
	M = h[0];
	B = h[1];

	


	//cout << M->preHash << endl;
	//cout << M->sufHash << endl;
	if(M->preHash == M->sufHash) cout << "yes" << endl;
	else cout <<"no" << endl;
	
	mt = merge(A, M);
	mt = merge(mt, B);
}

void inOrderTraversal(Treap *t){
	if(t == NULL) return;
	//Left, Node, Right
	inOrderTraversal(t->kids[0]);
	cout << (char)(t->data + 'a');
	inOrderTraversal(t->kids[1]);
}

void solve(){
    preCompShift();
    
    cin >> N >> Q;
    string s;
    cin >> s;
    loop(i, N){
        char c = s[i];
        v[i] = Treap(c);
        mt = merge(mt, &v[i]);
    }
    
	loop(i, Q){
		int a;
		cin >> a;
		if(a == 1) remove();
		if(a == 2) insert();
		if(a == 3) palindrome();
		//inOrderTraversal(mt);
		//cout << endl;
	}

	
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
