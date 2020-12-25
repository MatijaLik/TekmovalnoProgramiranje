#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
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
#define inf 1000000010
#define mod 1000000007
 
ll n;
struct Node{
    ll x, id;
    bool state;
    Node(ll a, bool b, ll c){
        x = a;
        id = c;
        state = b;
    }
    Node(){
        x = -1;
        id = -1;
        state = 0;
    }
};
//b
bool posSort(const Node &a, const Node &b){
    if(a.x == b.x and a.state == b.state) return a.id < b.id;
    if(a.x == b.x) return a.state == false;
    return a.x < b.x;
}
 
bool negSort(const Node &a, const Node &b){
    if(a.x == b.x and a.state == b.state) return a.id < b.id;
    if(a.x == b.x) return a.state == false;
    return a.x > b.x;
}
 
struct Rect{
    ll a, b, c, d;
    ll id;
    Rect(ll _a, ll _b, ll _c, ll _d, ll _id){
        a = _a;
        b = _b;
        c = _c;
        d = _d;
        id = _id;
    }
 
    pair<Node, Node> parse(ll p){
        if(p==0) return mp(Node{a, 1, id}, Node{c, 0, id});
        if(p==1) return mp(Node{c, 1, id}, Node{a, 0, id});
        if(p==2) return mp(Node{b, 1, id}, Node{d, 0, id});
        if(p==3) return mp(Node{d, 1, id}, Node{b, 0, id});
        return mp(Node{0,0,0}, Node{0,0,0});
    }
 
    Rect(){
        a = 0;
        b = 0;
        c = 0;
        d = 0;
        id = -1;
    }
};
 
struct llNode{
    llNode * next;
    Node node;
    llNode(llNode * _next,const Node &_node){
        next = _next;
        node = _node;
    }
 
    llNode(){
        next = NULL;
        node = Node();
    }
};
 
vector<Rect> mv;
 
bool daq(vector<int> valid){
    if(valid.size()<=3) return true;
    vector<Node> v[4];
    loop(i, 4) v[i].reserve(3*valid.size());
    ll totalSize = valid.size()*2;
    ll dir = 0;
    ll cnt[4] = {0,0,0,0};
    for(auto e : valid){
        loop(i, 4){
            v[i].pb(mv[e].parse(i).fs);
            v[i].pb(mv[e].parse(i).sc);
        }
    }
    //printf("%d %d %d %d\n", v[0].size(), v[1].size(), v[2].size(),v[3].size());
    sort(all(v[0]), posSort);
    v[1] = v[0];
    reverse(all(v[1]));

    sort(all(v[2]), posSort);
    v[3] = v[2];
    reverse(all(v[3]));
 
    ll place = 0;
    llNode start[4];
    llNode curNode[4];
    vector<llNode> linkedList;
    linkedList.reserve(4*totalSize);


    
    //sestavi linkedlist
    loop(i, 4){
        llNode * prev = NULL;
        for(ll pos = v[i].size()-1; pos >= 0; pos--){
            Node nn = v[i][pos];
            llNode ln = llNode{prev, nn};
            linkedList.pb(ln);
            prev = &linkedList[place];
            place++;
        }
        //start je neki placeholder
        start[i] = llNode{prev,Node()};
    }
 
    ll removedCnt = 0;
    loop(i, 4) curNode[i] = start[i];
    vector<int> smol[4];
    unordered_set<int> smolS[4];
    loop(i, 4) smolS[i].reserve(2*valid.size());
 
    unordered_set<int> blacklist;
    blacklist.reserve(2*valid.size());

    int curX[4] = {-1000,inf,-1000,inf};
    while(true){
        
        //velikost removecnt
        if(removedCnt == valid.size()-1) return true;
 
        //nekaj z pointerji
        if(curNode[0].next== NULL
        and curNode[1].next== NULL
        and curNode[2].next== NULL
        and curNode[3].next==NULL){
            return false;
        }

        if(curNode[dir].next == NULL){
            dir += 1;
            dir %= 4;
            continue;
        }
        
        if(curX[0]==curX[1]){
            curNode[0] = llNode(NULL, Node());
            curNode[1] = llNode(NULL, Node());
            if(dir==0 or dir == 1) continue;
        }
        if(curX[2]==curX[3]){
            curNode[2] = llNode(NULL, Node());
            curNode[3] = llNode(NULL, Node());
            if(dir==2 or dir == 3) continue;
        }
 
        
 
        llNode * sprehod = curNode[dir].next;
 
        //najdi naslednika
        while(sprehod != NULL and blacklist.count(sprehod->node.id)) sprehod = sprehod->next;
        curNode[dir].next = sprehod;
 
        if(curNode[dir].next==NULL){
            dir += 1;
            dir %= 4;
            continue;
        }
 
 
        //stopi naprej
        curNode[dir] = *(curNode[dir].next);
        Node cur = curNode[dir].node;


        curX[dir] = cur.x;
 
        
        if((cur.state and dir%2==0) or (!cur.state and dir%2)){
            //vzemi Node
            cnt[dir]++;
            smolS[dir].insert(cur.id);
        }else{
            //odstrani node
            smol[dir].pb(cur.id);
            
            cnt[dir]--;
 
            if(cnt[dir]==0){
                
                if(removedCnt + smol[dir].size() == valid.size()){
                    dir += 1;
                    dir %= 4;
                    continue;
                }
                bool bad[4] = {0,0,0,0};
                removedCnt += smol[dir].size();
                for(auto e : smol[dir]){
                    blacklist.insert(e);
                    loop(i, 4){
                        if(i==dir) continue;
                        if(smolS[i].count(e)){
                            smol[i].clear();
                            cnt[i]=0;
                            curNode[i] = start[i];
                            curX[i] = (-100)*(i+1);
                            smolS[i].clear();
                        }
                    }
                }
                bool b = daq(smol[dir]);
                
 
                if(b == false){
                    return false;
                }
 
                /*
                //resetiraj linkedList
                loop(i, 4) {
                    if(i == dir) continue;
                    cnt[i] = 0;
                    curNode[i] = start[i];
                    curX[i] = (-100)*(i+1);
                }*/

                smol[dir].clear();
                
            }
        }

        //hmm mogoce je vredno obdrzat dir
        if(curNode[dir].next!=NULL and (curNode[dir].next)->node.x == cur.x){
            continue;
        }else{
            dir += 1;
            dir %= 4;
        }
        
        
    }
    
    return false;
}
 
 
void solve(){
    
    cin >> n;
    vector<int> v;
    mv.reserve(n);
    loop(i, n){
        v.pb(i);
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        mv.pb(Rect{a, b, c, d, (int)i});
    }
 
 
 
    if(daq(v)) cout << "YES" << endl;
    else cout << "NO" << endl;
}
 
int main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
}