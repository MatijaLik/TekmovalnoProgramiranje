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

#define limit 200100

int opt[limit];
int memo[limit][6];
int N;
int notes[limit];

int dp(int note, int finger){
    if(note==N) return 2;
    if(memo[note][finger]!=0) return memo[note][finger];
    //cout << note << " " << finger << endl;
    bool options[6] = {1,1,1,1,1,1};
    options[finger] = 0; //ne sme biti ista kot prej

    if(note != 0){//ce nismo na prvi
        if(notes[note] > notes[note-1]){//narascamo
            loop(i, 6){
                if(i < finger){
                    options[i] = 0;
                }
            }
        }else if(notes[note] < notes[note-1]){//padamo
            loop(i, 6){
                if(i > finger){
                    options[i] = 0;
                }
            }
        }
    }
    loop(i, 6){
        if(i==0) continue;
        if(options[i]){
            if(dp(note+1, i) == 2){
                opt[note] = i;
                return memo[note][finger] = 2;
            }
        }
    }
    return memo[note][finger] =1;
}


int main(){
    cin >> N;
    loop(i, N){
        cin >> notes[i];
    }



    if(dp(0,0)==1){
        cout << -1 << endl;
    }else if(dp(0,0)==2){
        loop(i, N){
            cout << opt[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}