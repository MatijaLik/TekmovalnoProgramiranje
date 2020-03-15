#include <bitset>
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <cstring>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int, int>
#define pint pair<long long, long long>
#define pli pair<long long, int>
#define vi vector <int>
#define mii map<int, int>
#define si set<int>
#define loop(i, n) for(int i = 0; i < n; i++)
#define FOR(i,n,m) for(int i = n; i < m; i++)
#define isIn(vec, item) find(vec.begin(), vec.end(), item) != vec.end()
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define inf 9999
#define mod 1000000007
#define debug(x) cout << "# " << x << endl;

#define shift 10100

int memo[105][10500];
int N;
int pSum[105];
vector<pii> books;

int dp(int k, int space){
    //cout << k << " " << space << endl;
    if(memo[k][space+shift]!=-1) {
        return memo[k][space+shift];
    }
    if(space < -pSum[k]){
        return memo[k][space+shift] = inf;
    }
    if(k == N){
        if(space < 0){
            return memo[k][space+shift] = inf;
        }else{
            return memo[k][space+shift] = 0;
        }
    }
    
    pii nextBook = books[k];
    int thiccness = nextBook.second;
    int width = nextBook.first;
    return memo[k][space+shift] = min(dp(k+1, space+thiccness)+thiccness, dp(k+1, space-width));
}

int main(){
    cin >> N;
    loop(i, N){
        int a, b;
        cin >> a >> b;
        books.pb(mp(b, a));
    }
    sort(all(books));
    reverse(all(books));
    for(int i = N-1; i >= 0; i--){
        pSum[i] = pSum[i+1] + books[i].second;
    }
    memset(memo, -1, sizeof memo);
    cout << dp(0, 0) << endl;
    return 0;
}