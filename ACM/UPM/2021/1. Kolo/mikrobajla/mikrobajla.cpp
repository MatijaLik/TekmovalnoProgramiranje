/**
 * Author: MatijaL
 * Time: 2021-04-15 17:18:56
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



/*
VNAPREJ DOLIČI VELIKOST
VEKTORJA, KAMOR SHRANJUJEŠ 
TREAPE
*/

#define limit 1200000
mt19937 mt_rand(time(0));
ll N, M, X, P, R;
struct Treap {
	int data, priority;
    int mx;
    double avg;
	vector<Treap*> kids;
	int subtreeSize, sum;

    int propAdd;
    bool propDouble;

	Treap(int data);
};

int size(Treap *me) {
	return me == NULL ? 0 : me->subtreeSize;
}

int val(Treap *me){
    return me == NULL ? 0 : me->data;
}

void recalc(Treap *me) {
	if (me==NULL) return;
	me->subtreeSize = 1;
	me->sum = me->data + me->propAdd*size(me);

    me->mx = me->data;
    for (Treap* t:me->kids) me->mx = max(me->mx, val(t));

    me->avg = ((double) me->sum)/size(me);

	for (Treap* t:me->kids) if (t != NULL) me->subtreeSize += t->subtreeSize;
    if(me->propDouble) 
	for (Treap* t:me->kids) if (t != NULL) me->sum += t->sum+t->propAdd*size(t);
}

void prop(Treap *me) {
	if (me==NULL) return;
    assert(!(me->propDouble and me->propAdd));

	for (Treap *t:me->kids) if (t != NULL) t->propAdd += me->propAdd;

    if(me->propDouble) me->data *= 2;
	me->data+=me->propAdd;
	me->propAdd=0;
    me->propDouble=0;
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

    mx = _data;
    data = _data;
    sum = _data;

    propAdd = 0;
    propDouble = false;
    
	recalc(this);
	
	priority = mt_rand();
}

Treap* rangeAdd(Treap* t, int l, int r, int toAdd) {
	vector<Treap*> a=split(t, l), b=split(a[1], r-l+1);
	b[0]->toProp+=toAdd;
	return merge(a[0], merge(b[0], b[1]));
}

void inOrderTraversal(Treap *t){
	if(t == NULL) return;
	//Left, Node, Right
	inOrderTraversal(t->kids[0]);
	cout << t->data << endl;
	inOrderTraversal(t->kids[1]);
}


Treap* mt;
vector<Treap> v(limit, Treap(0));




void solve(){

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    t = 1;
    solve();   
}
