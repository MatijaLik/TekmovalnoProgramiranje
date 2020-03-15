#include <bitset>
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<ll, ll>
#define pli pair<long long, ll>
#define vi vector <ll>
#define mii map<ll, ll>
#define si set<ll>
#define loop(i, n) for(ll i = 0; i < n; i++)
#define FOR(i,n,m) for(ll i = n; i < m; i++)
#define isIn(vec, item) find(vec.begin(), vec.end(), item) != vec.end()
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define inf 999999999
#define mod 1000000007
#define debug(x) cout << "# " << x << endl;

int sum[200010];
int amnt[200010];
ll nums[200010];
ll weights[200010];
map<ll,ll> b;
priority_queue<ll> bq;
set<ll> bs;
priority_queue<ll> qnum[200010];
ll maxNum = 0;
ll curLayer = 2000010;
int main(){
    ll n;
    cin >> n;
    loop(i, n) cin >> nums[i];
    loop(i, n) cin >> weights[i];

    loop(i, n){
        ll num = nums[i];
        if(bs.count(num)==0){
            bq.push(-num);
            bs.insert(num);
        }
    }
    ll point = 0;
    while(!bq.empty()){
        ll x = -bq.top();
        bq.pop();
        b[x] = point;
        //cout << "bijekcija " << x << " " << point << endl;
        point++;
    }

    loop(i, n){
        ll num = nums[i];
        ll weight = weights[i];

        ll id = b[num];
        sum[id] += weight;
        qnum[id].push(weight);
        amnt[id]++;
        if(amnt[id]>1){
            curLayer = min(curLayer, num);
        }
        maxNum = max(maxNum, num);
    }
    //cout << "here" << endl;

    ll res = 0;
    ll mpWeight = 0;
    //ll mpMax = 0;
    priority_queue <ll> q;

    /*
    loop(i, maxNum+2){
        if(amnt[i] > 1){
            if(qnum[i].empty())continue;
            ll tm = qnum[i].top();
            qnum[i].pop();

            //vtakni not
            mpWeight += sum[i] - tm;
            while(!qnum[i].empty()) {
                q.push(qnum[i].top());
                qnum[i].pop();
            }
            //prva migracija
            res += mpWeight;
            //cout << "starting at " << i << endl;
            //debug(mpWeight);
            curLayer = i+1;
            break;
        }
    }priprave*/

    //cout << "zacnemo pri " << curLayer << endl;
    //cout << "b" << endl;
    if(curLayer==200010){
        cout << 0 << endl;
        return 0;
    }
    while(curLayer <= maxNum + 10 or !q.empty()){
        ll tm = 0;
        //ce je prazno
        if(bs.count(curLayer)==0){
            if(q.empty()){
                curLayer++;
                continue;
            }
            //depositaj svoj load
            mpWeight -= q.top();
            q.pop();
            //cout << "empty" << endl;
        }else{
            ll id = b[curLayer];
            //cout << "bijekcija " << curLayer << " " << id << endl;
            if(!q.empty() && qnum[id].top() < q.top()){
                //pogledamo zamenjavo
                //menjamo
                mpWeight -= (q.top() - qnum[id].top());
                q.pop();
                tm = qnum[id].top();
                q.push(qnum[id].top());
                qnum[id].pop();

                //cout << "replacing" << endl;
            }else{
                tm = qnum[id].top();
                qnum[id].pop();
            }
            //mergaj
            //debug(tm);
            while(!qnum[id].empty()) {
                q.push(qnum[id].top());
                qnum[id].pop();
                mpWeight += sum[id] - tm;
            }
        }
        
        //debug(tm);
        //cout << "mpw at layer " << curLayer << " -> " << mpWeight << endl;
        res += mpWeight;
        curLayer++;
    }
    cout << res << endl;
    return 0;
}