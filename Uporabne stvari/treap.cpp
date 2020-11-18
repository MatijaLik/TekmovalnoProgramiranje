#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
VNAPREJ DOLIČI VELIKOST
VEKTORJA, KAMOR SHRANJUJEŠ 
TREAPE
*/
mt19937 mt_rand(time(0));

struct Treap {
	int data, priority;
	vector<Treap*> kids;
	int subtreeSize, sum, toProp;

	Treap(int data);
};

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

int main() {
	return 0;
}