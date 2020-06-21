
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

#define limit 200100

int N;
vector<pii> v;
bool separator[limit];

struct Node { 
   int data; 
   struct Node *next; 
}; 

struct Node* head = NULL;  

void insert(int new_data, int index) { 
   struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
   new_node->data = new_data; 
   new_node->next = head; 
   head = new_node; 
}

void solve(){
    int res = 0;
    loop(n, N){
        int val, ix;
        cin >> val >> ix;

        v.insert(v.begin()+ix, mp(val, n));

        //pogledamo vse levo
        int highestLeft = 0;
        FOR(i, 0, ix-1){
            highestLeft = max(highestLeft, v[i].fs);
            if(v[i].fs > val and separator[v[i].sc]){
                res--;
                separator[v[i].sc] = false;
            }
        }

        //vse desno
        int lowestRight = inf;
        FOR(i, ix+1, n){
            lowestRight = min(lowestRight, v[i].fs);
            if(v[i].fs < val and separator[v[i].sc]){
                res--;
                separator[v[i].sc] = false;
            }
        }

        if(highestLeft <= val and lowestRight >= val){
            res++;
            separator[n] = true;
            //printf("am separator\n");
        }
        cout << res << endl;
    }
    for(auto e : v){
        cout << e.fs << " ";
    }cout << endl;
}

void ciganSolve(){
    loop(n, N){

    }

}


int main(){
    cin >> N;
    if(N > 5000)ciganSolve();
    else solve();
}