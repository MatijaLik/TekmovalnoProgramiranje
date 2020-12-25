/**
 * Author: MatijaL
 * Time: 2020-12-01 12:02:31
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
#define limit 1000010

bool b[limit];
unordered_set<ll> primes;


void erat(){
    b[1] = 1;
    b[0] = 1;
    FOR(i, 2, limit){
        if(b[i]==0){
            primes.insert(i);
            for(ll j = i*i; j < limit; j += i){
                b[j] = 1; 
            }
        }
    }
    return;
}

int memo[100000][5];
void precompute(){

    FOR(p, 1, 100000){
        if(b[p] == 1) continue;

        int len = 0;
        int temp = p;
        while(temp){
            len++;
            temp /= 10;
        }



        int ans = 0;
        FOR(d, 1, 5){
            int exp = d-1;
            int digit = ((p / (ll)pow(10, exp))%10)*pow(10,  exp);

            int pure = p - digit;
            //printf("%lld %lld -> %lld\n", p, d, pure);
            memo[pure][d]++;
        }
    }
}

int solve(int num){
    int len = 0;
    int temp = num;
    while(temp){
        len++;
        temp /= 10;
    }

    int grid[5][5];
    loop(i, 5)loop(j, 5) grid[i][j] = 0;

    temp = num;
    loop(i, len){
        grid[0][len-1-i] = temp%10;
        grid[len-1-i][0] = temp%10;
        temp /=10;
        grid[i][i] = 0;
    }


    ll res = 0;
    //int it = 0;

    vector<int> cand = {1, 3, 7, 9};


    FOR(a, 0, 9)FOR(b, 0, 9)FOR(c, 0, 9)FOR(d, 0, 9)FOR(e, 0, 9)FOR(f, 0, 9){
        if(len == 2 and a > 0) continue;
        if(len <= 3 and (b > 0 or d > 0)) continue;
        if(len <= 4 and (c > 0 or f > 0 or e > 0)) continue; 

        

        //it++;
        //if(it%100000==0) cout << it << endl;

        grid[1][2] = a;
        grid[2][1] = a;
        grid[1][3] = b;
        grid[3][1] = b;
        grid[1][4] = c;
        grid[4][1] = c;
        grid[2][3] = d;
        grid[3][2] = d;
        grid[2][4] = e;
        grid[4][2] = e;
        grid[3][4] = f;
        grid[4][3] = f;

        /*

        loop(i, len){
            loop(j, len) cout << grid[i][j] << " ";
            cout << endl;
        }*/

        int prod = 1;
        FOR(i, 1, len-1){
            int num = 0;
            loop(j, len){
                num *= 10;
                num += grid[i][j];   
            }
            //cout << num << endl;
            prod *= memo[num][len-i];
            //printf("%d %d\n", num, len-i);
            if(prod == 0) break;
        }
        res += prod;

        //cout << "///////" << endl;
        /*
        loop(i, 5){
        loop(j, 5) cout << grid[i][j]<< " ";
        cout << endl;
        }*/
        //cout << res << endl;
    }

    return res;
}

int main(){
    erat();
    precompute();
    //cout << "done" << endl;
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int t;
    cin >> t;
    while(t--){
        int p;
        cin >> p;
        cout << solve(p) << endl;
    }
    //cout << solve(12345) << endl;
    /*
    printf("{");
    FOR(p, 10, 99999)printf("%d, ",solve(p));
    printf("}\n");*/
}
