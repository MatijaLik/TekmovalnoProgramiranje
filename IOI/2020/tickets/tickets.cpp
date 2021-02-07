/**
 * Author: MatijaL
 * Time: 2021-01-17 18:15:39
**/
#include <tickets.h>
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
#define limit 1600
ll median;
struct Card{
    int color, pos;
    ll num;
    ll worth;
    Card(int a, int b, ll c){
        color = a;
        pos = b;
        num = c;
        worth = abs(num - median);
    }
    bool operator < (const Card& other){
        if(worth!=other.worth) return worth > other.worth;
        return pos < other.pos;
    }
};

ll find_maximum(int K, vector<vector<int>> x){
    int n = x.size();
    int m = x[0].size();
    vector<Card> cards[n];
    vector<ll> allNumbers;
    vector<vector<int>> out(n, vector<int>(m, -1));

    loop(i, n)loop(j, m){
        allNumbers.pb(x[i][j]);
        cards[i].pb(Card(i, j, x[i][j]));
    }

    sort(all(allNumbers));
    int mid = (m*n)/2 -1;
    int median = allNumbers[mid];

    printf("MEDIAN is %d\n", median);

    for(auto e : cards) sort(all(e)); 

    vector<Card> left[n];
    vector<Card> right[n];
    
    vector<int> pointL(n, 0);
    vector<int> pointR(n, 0);

    //pair<cost, color> right -> subLeft
    vector<pll> subLeft;
    vector<pll> subRight;
    //1. k najboljsih vsake barve
    loop(color, n){
        int cnt = 0;
        int pl = -1;
        int pr = -1;
        for(auto e : cards[color]){
            if(cnt < K){
                cnt++;
                if(e.num <= median) left[color].pb(e);
                else right[color].pb(e);
                pl = left[color].size()-1;
                pr = right[color].size()-1;

                pointL[color] = pl;
                pointR[color] = pr;
            }else{
                if(e.num <= median){
                    left[color].pb(e);
                    //probaj dat iz desne
                    if(pl >= 0) subLeft.pb(mp(left[color][pr].worth - e.worth, color));
                    pl--;
                }else{
                    right[color].pb(e);

                    //daj z leve
                    if(pr >= 0) subRight.pb(mp(right[color][pl].worth - e.worth, color));
                    pr --;
                }
            }
        }
    }

    //2. uravnovesi
    int leftCnt = 0;
    int rightCnt = 0;
    loop(i, n) leftCnt += left[i].size();
    loop(i, n) rightCnt += right[i].size();

    sort(all(subLeft));
    sort(all(subRight));

         
    for(auto e : subLeft){
        if(leftCnt >= rightCnt) break;
        int curColor = e.sc;
        leftCnt++;
        rightCnt--;
        pointL[curColor]++;
        pointR[curColor]--;
    }
    for(auto e : subRight){
        if(rightCnt >= leftCnt) break;
        int curColor = e.sc;
        rightCnt++;
        leftCnt--;
        pointR[curColor]++;
        pointL[curColor]--;
    }

    //3 lotimo se dela momci
    loop(k, K){
        int cl = 0;
        int cr = 0;
        set<int> usedColors;
        
        //nastimaj leve
        loop(color, n){
            if(usedColors.count(color) or pointR[color] < 0) continue;
            if(cl == n/2) break;
            Card c = left[color][pointL[color]];
            pointL[color]--;
            out[c.color][c.pos] = k;
            cl++;
        }

        //pa se desne
        loop(color, n){
            if(usedColors.count(color) or pointR[color] < 0) continue;
            if(cr == n/2) break;
            Card c = right[color][pointR[color]];
            pointR[color]--;
            out[c.color][c.pos] = k;
            cr++;
        }
        assert(cl == n/2 and cr == n/2);
    }

    allocate_tickets(out);
    return 0;
}
