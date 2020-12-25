/**
 * Author: MatijaL
 * Time: 2020-11-19 11:03:35
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

#define limit 200100

mt19937 mt_rand(time(0));

int LEFT(int i){return 2*i;}
int RIGHT(int i){return (2*i)+1;}
int MID(int l, int r){return (l+r)/2;}
vector<pll> seznam; //0 indexed

struct Treap {
	int data, priority, time;
	vector<Treap*> kids;
	int subtreeSize, sum, toProp;

	Treap(int data, int time);
};
int size(Treap *me) {
	return me == NULL ? 0 : me->subtreeSize;
}
void recalc(Treap *me) {
	if (me==NULL) return;
	me->subtreeSize = 1;
	for (Treap* t:me->kids) if (t != NULL) me->subtreeSize += t->subtreeSize;
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
Treap::Treap(int _data, int _time) {
	kids={NULL, NULL};
	data = _data;
    time = _time;
	recalc(this);
	
	priority = mt_rand();
}
void inOrderTraversal(Treap *t){
	if(t == NULL) return;
	//Left, Node, Right
	inOrderTraversal(t->kids[0]);
	seznam.pb(mp(t->data, t->time));
	inOrderTraversal(t->kids[1]);
}

int N;
vector<Treap> treaps(limit, Treap(0,0));
Treap * mainTreap = NULL; 


void prviDel(){
    loop(i, N){
        int x, pos;
        cin >> x >> pos;
        vector<Treap*> temp(2);
        temp = split(mainTreap, pos);

        Treap toInsert = Treap(x, i);
        treaps[i] = toInsert;

        mainTreap = merge(temp[0], &treaps[i]);
        mainTreap = merge(mainTreap, temp[1]);
    }
    inOrderTraversal(mainTreap);
}

struct Node{
    int L, R, size;
    Node * lKid, * rKid;

    //sorted vector
    vector<pll> v;

    //segment tree
    vector<ll> segtree;
    

    void buildST(int i, int l, int r){
        if(l == r) segtree[i] = v[l-1].sc;
        else{
            int m = MID(l, r);
            buildST(LEFT(i), l, m);
            buildST(RIGHT(i), m+1, r);
            segtree[i] = min(segtree[LEFT(i)], segtree[RIGHT(i)]);
        }
    }

    int queryST(int i, int l, int r, int ql, int qr){
        //zunaj
        if(qr < l or r < ql) return inf;
        //v celoti not
        if(ql <= l and r <= qr) return segtree[i];

        int m = MID(l, r);
        return min(
            queryST(LEFT(i), l, m, ql, qr),
            queryST(RIGHT(i), m+1, r, ql, qr)
        );
    }

    //vrne najmanjsi cas vecjega/manjsega elementa
    int query(int ql, int qr, bool bigger, int x){

        //printf("query %d %d value %d on interval | %d %d\n", ql, qr, x, L, R);

        //zunaj
        if(qr < L or R < ql) return inf;

        //v celoti not
        if(ql <= L and R <= qr){
            if(bigger){
                pll xPair = mp(x, inf);
                auto it = upper_bound(all(v), xPair);
                int leva = it - v.begin() + 1;
                int desna = size;
                if(desna < leva) return inf;
                return queryST(1, 1, size, leva, desna);
            }else{
                pll xPair = mp(x, -1);
                auto it = lower_bound(all(v), xPair);
                int leva = 1;
                int desna = it - v.begin();
                if(desna < leva) return inf;
                return queryST(1, 1, size, leva, desna);
            }
        }

        return min(
            lKid->query(ql, qr, bigger, x),
            rKid->query(ql, qr, bigger, x)
        );
    }
    Node(int _L, int _R);
    Node(){
        L = 0;
        R = 0;
        size = 0;
    }
};

vector<Node> nodes(4*limit, Node());
int prostor = 1;

Node::Node(int _L, int _R){
    L = _L;
    R = _R;
    size = R - L + 1;
    if(size == 1){
        v.pb(seznam[L-1]);
        lKid = NULL;
        rKid = NULL;
    }else{
        int mid = MID(L, R);

        nodes[prostor] = Node(L, mid);
        lKid = &nodes[prostor];
        prostor++;

        nodes[prostor] = Node(mid+1, R);
        rKid = &nodes[prostor];
        prostor++;

        //sestavi vector
        merge(
            lKid->v.begin(), lKid->v.end(),
            rKid->v.begin(), rKid->v.end(),
            back_inserter(v)
        );
    }

    /*
    printf("Node %d %d\n", L, R);
    for(auto e : v) printf("%d ", e.fs);
    printf("\n");
    for(auto e : v) printf("%d ", e.sc);
    printf("\n");
    */
    segtree.resize(4*size);
    buildST(1, 1, size);
}

void drugiDel(){
    //printf("BUILDING NODES\n");
    nodes[0] = Node(1, N);
    Node * root = &nodes[0];
    //printf("ALL NODES BUILT\n");

    int cum = 0;
    int up[limit];
    int down[limit];
    memset(up, 0, sizeof up);
    memset(down, 0, sizeof down);

    //printf("root %d %d %d\n", root->L, root->R, root->size);

    loop(i, N){
        pll p = seznam[i];
        int time = p.sc;
        int x = p.fs;
        int index = i+1;

        //na levi isci vecji na desni manjse 
        int timeOfDeath = min(
            root->query(1, index, true, x),
            root->query(index+1, N, false, x)
        );

        //printf("%d %d -> tod %d\n", x, index, timeOfDeath);

        if(timeOfDeath < time) continue;
        up[time]++;
        if(timeOfDeath!=inf) down[timeOfDeath]++;
    }
    
    /*
    loop(i, N) printf("%d ", up[i]);
    printf("\n");
    loop(i, N) printf("%d ", down[i]);
    printf("\n");
    */

    //gremo printat
    loop(i, N){
        cum += up[i];
        cum -= down[i];
        cout << cum << endl;    
    }

}

void solve(){
    cin >> N;
    prviDel();
    drugiDel();

    loop(i, N) cout << seznam[i].fs << " ";
    cout << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();   
}
