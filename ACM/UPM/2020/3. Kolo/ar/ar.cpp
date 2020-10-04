/**
 * Author: MatijaL
 * Time: 2020-10-01 17:12:41
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pll pair<ll, ll>
#define pii pair<int, int>
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
vector<int> v;
const int MOD = mod;
const int limit = 105;
pii memo[limit][limit];


bool isPosible(){
    if(v.size()==1){
        if(v[0] != 0 && v[0] != 1) return false;
        return true;
    }
    //first element is not
    if(v[0] != 0){          //false
        if(v[0] != 1){      //true
            if(v[0] != 2){  //not
            //cout << 4 << endl;
                return false;
            }
        }
    }
    //if last element is not
    if(v[v.size()-1] != 0){         //false
        if(v[v.size()-1] != 1){     //true
        //cout << 5 << endl;
            return false;
        }
    }

    //NOT true AND false OR NOT false
    //false
    //true XOR



    FOR(i,0,v.size()-2){
        //check that there are not two trues/falses 
        if(v[i] == 0){
            if(v[i+1] == 0) return false;
            if(v[i+1] == 1) return false;
        }
        if(v[i] == 1){
            if(v[i+1] == 0) return false;
            if(v[i+1] == 1) return false;
        }

        //checks if two consecutives are or/and/xor
        if(v[i] == 3 || v[i] == 4 || v[i] == 5){
            if(v[i+1] == 3 || v[i+1] == 4 || v[i+1] == 5){
                //cout << 1 << endl;
                return false;
            }
        }

    
        //if it is a not, it cannot be followed by an and, or and/or exor
        if(v[i] == 2){
            if(v[i+1] == 3 || v[i+1] == 4 || v[i+1] == 5){
                //cout << 2 << endl;
                return false;
            }
        }

        //if true or false, cannot be followed by not
        if(v[i] == 0 || v[i] == 1){
            if(v[i+1] == 2) {
                //cout << 3 << endl;
                return false;
            }
        }
    }

    //if all else makes sense, then it must be okay
    //cout<<"It works"<<endl;
    return true;
}

int add(int x, int y)
{
	return (x + y) % MOD;
}
int mul(int x, int y)
{
	return (x * 1ll * y) % MOD;
}
pll dp(int left, int right){
    //memoizacija
    if(memo[left][right] != mp(-1, -1)) return memo[left][right];
    
    //trivialni primer

    //1. Imamo samo en true/false
    if(left == right){
        int e = v[left];
        if(e) return memo[left][right] = mp(1, 0);
        else return memo[left][right] = mp(0, 1);
    }
    
    /*
     * TA DEL NE DELUJE
     * AMPAK JE TU FOR LEGACY PURPOSES
    //2. Imamo NOT nekaj
    if(v[left] == 2){
        pll res = dp(left+1, right, depth+1);

        //negiraj ta result
        return memo[left][right] = mp(res.sc, res.fs);
    }*/


    //Probaj deliti na vsakem OR| XOR| AND
    ll tcnt = 0;//na kolko nacinov bo true
    ll fcnt = 0; // na kolk nacinob bo false
    //loop(i, depth) cout << " ";
    //printf("dp %d %d\n", left, right);
    FOR(op, left, right){
        int e = v[op];

        if(op == left and e == 2){
            //UNARY NOT
            pll res = dp(left+1, right);
            tcnt = add(tcnt, res.sc);
            fcnt = add(fcnt, res.fs);
        }
        //ce sploh ni to operator
        if(e <= 2) continue;
        
        //loop(i, depth) cout << " ";
        //printf("operator on %d\n", op);
        pll lhs = dp(left, op-1);
        pll rhs = dp(op+1, right);

        //loop(i, depth) cout << " ";
                //printf("%d %d %d %d\n", lhs.fs, lhs.sc, rhs.fs, rhs.sc);

        if(e == 3){
            //OR

            tcnt = add(tcnt, mul(lhs.fs, add(rhs.fs, rhs.sc)));
            tcnt = add(tcnt, mul(lhs.sc, rhs.fs)); 
            
            fcnt = add(fcnt, mul(lhs.sc, rhs.sc));
            
        }else if(e == 4){
            //XOR

            tcnt = add(tcnt, mul(lhs.fs, rhs.sc));
            tcnt = add(tcnt, mul(lhs.sc, rhs.fs));

            fcnt = add(fcnt, mul(lhs.fs, rhs.fs));
            fcnt = add(fcnt, mul(lhs.sc, rhs.sc));

        }else if(e == 5){
            //AND
            //
            tcnt = add(tcnt, mul(lhs.fs, rhs.fs));

            fcnt = add(fcnt, mul(lhs.fs, rhs.sc));
            fcnt = add(fcnt, mul(lhs.sc, add(rhs.fs, rhs.sc))); 
        } 
    }
    //loop(i, depth) cout << " ";
    //printf("dp %d-%d --> T %d | F %d\n", left, right, tcnt, fcnt);
    return memo[left][right] = mp(tcnt, fcnt);
}

void append(string word){
    if(word == "false") v.pb(0);
                if(word == "true") v.pb(1);
                if(word == "NOT") v.pb(2);
                if(word == "OR") v.pb(3);
                if(word == "XOR") v.pb(4);
                if(word == "AND") v.pb(5);
}
int solve(){
    string line;
    loop(i, limit) loop(j, limit) memo[i][j] = mp(-1, -1);
    while(getline(cin , line)){
        v.clear();
        //cout << line << endl;
        
        string word = "";
        //porihtaj input
        for(auto c : line){
            if(c == ' '){

                append(word);
                word = "";
            }
            else word += c;
        }
        append(word);
        
        //for(auto e : v) cout << e << " ";
        //cout << endl;
        
        if(!isPosible()){
            cout << "napaka" << endl;
            continue;
        }

        int N = v.size();
        cout << dp(0, N-1).fs << endl; 

        //cleanup
        loop(i, N+3) loop(j, N+3) memo[i][j] = mp(-1, -1);
        

    }
    return 1;
}

int main(){

    //ios::sync_with_stdio(0);
    //cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

   
    solve();
}
