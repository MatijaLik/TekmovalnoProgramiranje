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

mt19937 mt_rand(time(0));

struct Treap {
	int data, priority;
	vector<Treap*> kids;
	int subtreeSize;
    int pref0, best0, suf0;
    int pref1, best1, suf1;

    bool invert;

	Treap(int data);
};

int size(Treap *me) {
	return me == NULL ? 0 : me->subtreeSize;
}

void prop(Treap *me) {
	if (me==NULL) return;
    if(me->invert == true){
        for (Treap *t:me->kids) if (t != NULL) t->invert = not(t->invert);
        me->data = 1-me->data;
        swap(me->pref0, me->pref1);
        swap(me->best0, me->best1);
        swap(me->suf0, me->suf1);
        me->invert=0;
    }
}

void recalc(Treap *me) {
	if (me==NULL) return;
	me->subtreeSize = 1;
	for (Treap* t:me->kids) if (t != NULL) me->subtreeSize += t->subtreeSize;
	
    // L        |  R
    // P0 B0 S0 | p0 b0 s0
    // P1 B1 S1 | p1 b1 s1

    Treap* l = me->kids[0];
    prop(l);
    int P0, B0, S0, P1, B1, S1;
    if(l == NULL)P0 = B0 = S0 = P1 = B1 = S1 = 0;
    else{
        P0 = l->pref0;
        B0 = l->best0;
        S0 = l->suf0;
        P1 = l->pref1;
        B1 = l->best1;
        S1 = l->suf1;
    }

    Treap* r = me->kids[1];
    prop(r);
    int p0, b0, s0, p1, b1, s1;
    if(r == NULL)p0 = b0 = s0 = p1 = b1 = s1 = 0;
    else{
        p0 = r->pref0;
        b0 = r->best0;
        s0 = r->suf0;
        p1 = r->pref1;
        b1 = r->best1;
        s1 = r->suf1;
    }

    me->pref0 = (P0 == size(l) and me->data == 0) ? P0 + 1 + p0: P0;
    me->best0 = (me->data == 0) ? max(S0 + 1 + p0, max(B0, b0)) : max(B0, b0);
    me->suf0 = (s0 == size(r) and me->data == 0) ? S0 + 1 + s0 : s0;

    me->pref1 = (P1 == size(l) and me->data == 1) ? P1 + 1 + p1 : P1;
    me->best1 = (me->data == 1) ? max(S1 + 1 + p1, max(B1, b1)) : max(B1, b1);
    me->suf1 = (s1 == size(r) and me->data == 1) ? S1 + 1 + s1 : s1;
}



Treap* merge(Treap *l, Treap *r) {
    prop(l); prop(r);
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
	prop(me);
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

Treap::Treap(int _data) {
	kids={NULL, NULL};
	data = _data;
    invert = false;
    pref0 = best0 = suf0;
    pref1 = best1 = suf1;
	recalc(this);
	
	priority = mt_rand();
}

/*
Treap* rangeAdd(Treap* t, int l, int r, int toAdd) {
	vector<Treap*> a=split(t, l), b=split(a[1], r-l+1);
	b[0]->toProp+=toAdd;
	return merge(a[0], merge(b[0], b[1]));
}*/

void inOrderTraversal(Treap *t){
	if(t == NULL) return;
	//Left, Node, Right
	inOrderTraversal(t->kids[0]);
	cout << t->data;
	inOrderTraversal(t->kids[1]);
}


#define limit 300100

Treap * mt = NULL;
vector<Treap> v(limit, Treap(0));
int N, Q;

void invert(){
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

	M->invert = not(M->invert);
    //prop(M);
    //recalc(M);
	
	mt = merge(A, M);
	mt = merge(mt, B);

    //recalc(mt);
}



void solve(){
    cin >> N >> Q;
    string s;
    cin >> s;
    loop(i, N){
        char c = s[i];
        Treap nt = Treap(0);
        if(c == '1'){
            nt = Treap(1);
        }
        v[i] = nt;
        mt = merge(mt, &v[i]);
    }
    
    loop(i, Q){
        int t;
        cin >> t;
        if(t == 1) invert();


        cout << max(mt->best0, mt->best1) << endl;
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