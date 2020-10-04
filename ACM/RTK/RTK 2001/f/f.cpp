/**
 * Author: MatijaL
 * Time: 2020-09-26 16:24:45
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
int N;
map<string, ll> cnt[21];
vector<string> words;
set<string> wordSet;

vector<ll> top[21];
double bot[21];

void getWords(int id, string line){
    line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
    string word = "";
    for(auto c : line){
        if(c == ' '){
            if(wordSet.count(word) == 0){
                words.pb(word);
                wordSet.insert(word);
            }
            cnt[id][word]++;
            word = "";
        }
        else word += c;
    }
    if(wordSet.count(word) == 0){
        words.pb(word);
        wordSet.insert(word);
    }

   cnt[id][word]++;
}
void preCalc(){
    loop(i, N){
        bot[i] = 0;
        for(auto w : words){
            top[i].pb(cnt[i][w]);
            bot[i] += cnt[i][w] * cnt[i][w];
        }
        bot[i] = sqrt(bot[i]);
    }
}
double P(int x, int y){
    double num = 0;
    loop(i, wordSet.size()){
        num += top[x][i]*top[y][i];
    }
    num /= bot[x];
    num /= bot[y];
    return num;
}
void solve(){
    cin >> N;
    string temp;
    getline(cin, temp);
    vector<string> lines;
    loop(i, N){
        string line;
        getline(cin, line);
        lines.pb(line);
    }
    loop(i, N){
        getWords(i, lines[i]);
    }
    preCalc();
    double best = 0;
    pll res; 
    loop(i, N) loop(j, N){
        if(i >= j) continue;
        if(P(i, j) > best){
            best = P(i, j);
            res.fs = i+1;
            res.sc = j+1;
        }
    }
    cout << res.fs << " " << res.sc << endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
}
