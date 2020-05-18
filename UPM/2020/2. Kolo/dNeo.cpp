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

map <string, int > id;//obvoznice
map <int, string> inverseId; //int </> ime ulice


vector <pair<int, int > > v; //za odgovore

int grid[1010][1010]; //načrt mesta: križišče == grid[x][y];

int sumx[1010];
int sumy[1010];

vector <pair<int, pair<int, bool > > > sum; //pair(sum_ulice, pair(id_ulice, true-obvoznica false-vpadnica))

//koliko protestov je na ulici
map<int, int> aop;
map<int, int> ogaop;
map<int, vector<int>> kjeseka;

map<pii, bool> aktiven;

set<pii> uporabljena;

vector<int> resitev;

int main(){
    int n, m, p;
    string s1, s2;
    cin >> n >> m >> p;

    int stProt = 0;

    int index = 1;
    loop(i, n){
        cin >> s1;
        inverseId[index] = s1;
        id[s1] = index++;
    }

    loop(i, m){
        cin >> s1;
        inverseId[index] = s1;
        id[s1] = index++;
    }

    for(int i = 0; i < p; i++){
        cin >> s1 >> s2; //odgovore shrani v pair(idx, idy);
        int id1, id2;
        id1 = id[s1];
        id2 = id[s2];
        if(id1 <= n == id2 <= n or (id1==0) or (id2 == 0)) {
            //cout << inverseId[id1] << " " << inverseId[id2] << endl;
            //printf("jao napacno jebote\n");
            continue;
        }
        if(aktiven[mp(id1, id2)] and aktiven[mp(id2, id1)]){
            
            if(uporabljena.count(mp(id1, id2)) or uporabljena.count(mp(id2, id1))) continue;

            kjeseka[id1].pb(id2);
            kjeseka[id2].pb(id1);

            aop[id1]++;
            aop[id2]++;
            stProt++;


            uporabljena.insert(mp(id1, id2));
            uporabljena.insert(mp(id2, id1));
        }

        
        aktiven[mp(id1, id2)] = true;
        aktiven[mp(id2, id1)] = true;
    }

    FOR(i, 1,  n+m){
        //printf("node %d s kolicino %d\n", i, aop[i]);
    } 

    ogaop = aop;

    int cleared = 0;
    priority_queue<pii> q;

    FOR(i, 1, n+m)q.push(mp(aop[i],i));

    while(cleared < stProt){
        pii p = q.top();
        q.pop();

        int kolicina = p.fs;
        int indeks = p.sc;


        //printf("poppamo %d s kolicino %d\n", indeks, kolicina);

        if(kolicina != aop[indeks]){
            q.push(mp(aop[indeks], indeks));
            //printf("neveljaven\n");
            continue;
        }

        for(auto sekajoca : kjeseka[indeks]){
            //ce je aktivno
            if(aktiven[mp(sekajoca, indeks)]){
                cleared++;
                aktiven[mp(sekajoca, indeks)] = false;
                aktiven[mp(indeks, sekajoca)] = false;

                
            }
            aop[sekajoca]--;
            aop[indeks]--;
        }
        //printf("Kolicina cleared je %d\n", cleared);
        
        resitev.pb(indeks);
    }
    
    /*
    for(int i = 0; i < v.size()-1; i++){
        if(v[i] == v[i+1]){
            i++;
            grid[v[i].first][v[i].second]++;

            sumx[v[i].first]++;
            sumy[v[i].second]++;
        }
    }*/
    vector<string> kresitev;

    for(auto i : resitev){
        //cout << "ime: " << inverseId[i];
        //printf(" -> og %d, now %d\n", ogaop[i], aop[i]);
        if(ogaop[i] == -aop[i]){
            continue;
        }

        //cout <<" pushing " << inverseId[i] << endl;
        kresitev.pb(inverseId[i]);
    }

    

    cout << kresitev.size() << endl;
    for(auto kraj : kresitev){
        cout << kraj << endl;
    }
}