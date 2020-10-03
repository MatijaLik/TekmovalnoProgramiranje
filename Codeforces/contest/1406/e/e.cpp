/**
 * Author: MatijaL
 * Time: 2020-09-12 15:45:01
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
int A(int a){
    cout << "A " <<  a << endl;
    cout << flush;
    int temp;
    cin >> temp;
    return temp;
}
int B(int a){
    cout << "B " <<  a << endl;
    cout << flush;
    int temp;
    cin >> temp;
    return temp;
}
void C(int a){
    cout << "C " << a << endl;
    return;
}
int N;
int mid;
int midId;
vector<int> primes;
bool compound[100100];

void erat(){
    FOR(i, 2, N){
        if(compound[i]) continue;
        primes.pb(i);
        for(ll j = i*i; j <= N; j += i)compound[j] = true;
    } 
}
int ALG1(){
    //printf("x is some bigprime\n");
    int begin = A(1);

    //groups of 100 
    int start = midId;
    int end = -1;
    int cnt = 0;
    FOR(i, midId, primes.size()-1){
        int p = primes[i];
        cnt+= B(p);
        if(cnt % 100 == 99){
            if(A(1) != begin - cnt){
                //found
                end = i;
                start = max(midId, end-99);
                break;
            }
        }
    }
    if(end == -1){
        end = primes.size()-1; 
        start = max(midId, end-99);
    }    
    assert(end - start < 101);
    FOR(i, start, end){
        int p = primes[i];
        if(B(p) == 1){
            return p;
        }
    }
    return 1;
}
void ALG2(){
    //printf("x is smallprime or compund\n");
    ll prod = 1;

    for(auto p : primes){
        if(p > mid) break;
        if(prod*p > N) break;


        ll exprime = 1;
        //lifting the exponent
        while(1){
            if(prod*exprime*p > N) break;
            if(B(exprime*p) == 0) break; 
            
            exprime *= p;
        }
        prod *= exprime;
    }
    

    //lowprod
    //printf("lowprod is %lld\n", prod);
    
    int other = ALG1();


    C(prod*other);
}

void solve(){
    cin >> N;
    if(N == 1){
        C(1);
        return;
    }
    erat();
    mid = floor(sqrt((double)N));
    
    int rmCnt = 0;
    loop(i, primes.size()){
        int p = primes[i];
        midId = i;
        if(p > mid) break;
        rmCnt += B(p);
    }

    int allCnt = A(1);
    if(allCnt + rmCnt == N) C(ALG1());
    else ALG2();
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
}
