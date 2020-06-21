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
#define debug(x) cout << "# " << x << endl;


string a;
string b;


//map<pair<string, string>,  int> memo;
ll rsa[28][2100000];
ll rsb[28][2100000];

ll count(int start, int end, char s, int letter){
    //printf("coutn for %d %d ans string %c\n", start, end, s);
    if(s == 'a'){
        return rsa[letter][end] - rsa[letter][start-1];
    }else{
        return rsb[letter][end] - rsb[letter][start-1];
    }

}

bool check(ll la, ll lb, ll len){
    


    if(len < 1) return false;
    if(len==1){
        if(a[la] == b[lb]) return true;
        else return false;
    }


    //string suba = a.substr(la, len);
    //string subb = b.substr(lb, len);

    //ll q = memo[mp(suba, subb)];

    //if(q == 2)return true;
   // if(q == 1) return false;

    bool gre[4][4];
    ll siptar = len/3;
    loop(ac, 3)loop(bc, 3){

        bool abort = false;
        //prvo preveri st crk

        

        loop(letter, 26){
            int p = count(la+ac*siptar, la+ac*siptar+siptar-1, 'a', letter);
            int d = count(lb+bc*siptar, lb+bc*siptar+siptar-1, 'b', letter);
            if(p!=d){
                //printf("abort %d %d, %d %d at letter %d\n", ac, bc, p, d, letter);
                gre[ac+1][bc+1] = false;
                abort = true;
                break;
            }
        }
        if(abort) continue;
        gre[ac+1][bc+1] = check(la+ac*siptar, lb + bc*siptar, len/3); 
    }

    bool res = false;
    //deli in vladaj
    ll f[] = {1, 1, 2, 2, 3, 3};
    ll s[] = {2, 3, 1, 3, 1, 2};
    ll t[] = {3, 2, 3, 1, 2, 1};

    loop(i, 6){
        if(
            gre[1][f[i]] and
            gre[2][s[i]] and 
            gre[3][t[i]]
        )res = true;
    }
    /*
    if(res){
        memo[mp(suba, subb)] = 2;
    }else{
        memo[mp(suba, subb)] = 1;
    }*/
    return res;

}

void solve(){
    a = "";
    b = "";
    cin >> a;
    cin >> b;
    a = " " + a;
    b = " " + b;
    ll len = a.length()-1;
    memset(rsa, 0, sizeof rsa);
    memset(rsb, 0, sizeof rsb);
    //roling sum
    FOR(i, 1, len){
        int la = (int)a[i]-'a';
        int lb = (int)b[i]-'a';
        loop(letter, 26){
            rsa[letter][i] = rsa[letter][i-1];
            rsb[letter][i] = rsb[letter][i-1];
        }
        rsa[la][i]++;
        rsb[lb][i]++;
    }
    /*
    FOR(i, 1, len){
        loop(letter, 5){
            printf("%d-%d  ", rsa[letter][i], rsb[letter][i]);
        }
        cout << endl;
    }*/

    if(check(1, 1, len)) cout << "enaka" << endl;
    else cout << "razlicna" << endl;
}


int main(){



    ll T;
    cin >> T;
    while(T--){
        solve();
    }
}