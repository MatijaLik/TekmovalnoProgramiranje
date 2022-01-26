/**
 * Author: MatijaL
 * Time: 2020-10-28 15:01:56
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

int N;
mt19937 mt_rand(time(0));

struct Treap {
	int data, priority;
	vector<Treap*> kids;
	int subtreeSize, sum, toProp;

	Treap(int data);
};

Treap * root = NULL;


int size(Treap *me) {
	return me == NULL ? 0 : me->subtreeSize;
}

void recalc(Treap *me) {
	if (me==NULL) return;
	me->subtreeSize = 1;
	me->sum = me->data + me->toProp*size(me);
	for (Treap* t:me->kids) if (t != NULL) me->subtreeSize += t->subtreeSize;
	for (Treap* t:me->kids) if (t != NULL) me->sum += t->sum+t->toProp*size(t);
}

void prop(Treap *me) {
	if (me==NULL) return;
	if (me->toProp == 0) return;
	for (Treap *t:me->kids) if (t != NULL) t->toProp += me->toProp;
	me->data+=me->toProp;
	me->toProp=0;
	recalc(me);
}

Treap* merge(Treap *l, Treap *r) {
	if (l==NULL) return r;
	if (r==NULL) return l;
	prop(l); prop(r);
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
    toProp = 0;
	recalc(this);
	
	priority = mt_rand();
}


void inOrderTraversal(Treap *t){
    if(t == NULL) return;

	//Left, Node, Right
    
	inOrderTraversal(t->kids[0]);
	cout << t->data << " ";
	inOrderTraversal(t->kids[1]);
}



void query(int a, int b){
	if(a >= b) return;
	int len = min(b-a, N-b+1);

	//L A M B R -> L B M A R
	Treap *L, *A, *B, *M, *R;
	vector<Treap*> s;

	s = split(root, a-1);
	L = s[0];
	s = split(s[1], len);
	A = s[0];

	s = split(s[1], b-(a+len));
	M = s[0];

	s = split(s[1], len);
	B = s[0];
	R = s[1];


	root = merge(L, B);
	root = merge(root, M);
	root = merge(root, A);
	root = merge(root, R);
} 


void solve(){

    cin >> N;
    vector<Treap> v(N, Treap(0));

    FOR(i, 1, N){
        Treap newNode = Treap(i);
        v[i-1] = newNode;
        root = merge(root, &v[i-1]);
    }

	loop(i, N){
		int a, b;
		cin >> a >> b;
		query(a, b);
		if(i != N-1) continue;
		inOrderTraversal(root);
		cout << endl;
	}

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
