#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
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
#define DEBUG false


const string no = "Nestabilen :(";
const string yes = "Stabilen :)";

const double EPS = 1e-9;
pdd start = mp(0, 0);

pdd operator - (const pdd &a, const pdd &b){
    return mp(a.fs-b.fs, a.sc-b.sc);
}

double len(pdd a){
    return a.fs*a.fs + a.sc*a.sc;
}

double vProd(pdd a, pdd b){
    return a.fs*b.sc - a.sc*b.fs;
}

bool po_kotu(pdd a, pdd b){
    if(vProd(a-start, b - start) == 0) return len(a-start) < len(b-start);
    return vProd(a-start, b - start) > 0;
}

bool poOddaljenosti(pdd a, pdd b){
    return len(a) < len(b);
}

pdd tezisce;

double blocks, xSum, ySum;//stevilo blockov in rolling sum
vector<string> results;
vector<bool> g[30];
int H;

/*
Sodi sloji so vertikalni
Lihi horizontalni

x je vodoravno
y je horiznontalno

*/

pdd getTempTezisce(int h){
    pdd tempTezisce = mp(0,0); //ko racunamo kaj se zgodi, ce vzamemo vun en kos
    double numOfBlocks = 0;
    loop(i, h){
        loop(j, 3){
            if(i%2==0){
                if(g[i][j]){
                    tempTezisce.fs += j + 0.5;
                    tempTezisce.sc += 1.5;
                    numOfBlocks++;
                }
            }else{
                if(g[i][j]){
                    tempTezisce.fs += 1.5;
                    tempTezisce.sc += j + 0.5;
                    numOfBlocks++;
                }
            }
        }
    }
    tempTezisce.fs /= numOfBlocks;
    tempTezisce.sc /= numOfBlocks;
    return tempTezisce;
}

bool isStable(vector<bool> blocks, bool orientation, pdd t){
    /*
    b vrednosti povejo, ali je nek block prisoten

    Orientation:
    0 - navpicne
    1 - vodoravne

    Kaj delamo:
    (iskreno, niam pojma)
    1. shrani vsa oglisca blockov
    2. naredi convex hull
    3. pogleda ce je tezisce not
    */

    bool b0 = blocks[0];
    bool b1 = blocks[1];
    bool b2 = blocks[2]; 

    //0. preveri, ce sploh je kaki block
    if(!b0 and !b1 and !b2)return false;

    vector<pdd> allPoints;

    //1
    allPoints.pb(t);
    loop(i, 3){
        if(blocks[i]){
            if(orientation==0){
                allPoints.pb(mp(i, 0));
                allPoints.pb(mp(i+1, 0));
                allPoints.pb(mp(i, 3));
                allPoints.pb(mp(i+1, 3));
            }else{
                allPoints.pb(mp(0, i));
                allPoints.pb(mp(0, i+1));
                allPoints.pb(mp(3, i));
                allPoints.pb(mp(3, i+1));
            }
        }
    }

    //2
    //izbrisi podvojene
    set<pdd> dupli;
    for(int i = 0; i < allPoints.size(); i++){
        if(dupli.count(allPoints[i])) allPoints.erase(allPoints.begin()+i);
        else dupli.insert(allPoints[i]);
    }


    sort(all(allPoints), poOddaljenosti);//najdi najbolj spodaj levo tocko
    start = allPoints[0];
    if(start == t) return false;
    sort(all(allPoints), po_kotu);
    
    vector<pdd> hull;
    hull.pb(allPoints[0]);
    hull.pb(allPoints[1]);

    
    #if DEBUG
    printf("start is %.3f %.3f\n", start.fs, start.sc);
    for(auto tocka : allPoints)printf("kandidat %.3f %.3f\n", tocka.fs, tocka.sc);
    #endif
    

    FOR(i, 2, allPoints.size()-1){
        pdd next = allPoints[i];
        //printf("Prduct %.3f %.3f since %.3f %.3f -----> %.3f\n", hull.end()[-1].fs, hull.end()[-1].sc, next.fs, next.sc, vProd(hull.end()[-1] - hull.end()[-2], next - hull.end()[-2]));
        while(hull.size() >= 2 and vProd(hull.end()[-1] - hull.end()[-2], next - hull.end()[-2]) < -EPS){
            //printf("deleting %.3f %.3f since %.3f %.3f\n", hull.end()[-1].fs, hull.end()[-1].sc, next.fs, next.sc);
            hull.pop_back();
        }
        hull.pb(next);
    }

    /*
    Program se zajebe, ce lezi tezisce na zadnji stranci convex hulla, zato to rocno fixam
    */
    if(vProd(hull.end()[-1] - start, t - start)==0) return false;   


    //3
    //ce je tezisce del ovojnice, pomeni da zadeva ni stabilna 
    for(auto tocka : hull){
        /*
        #if DEBUG
            printf("hull %.3f %.3f\n", tocka.fs, tocka.sc);
        #endif
        */
        if(tocka == t) return false;
    }
    return true;
}


bool doLayer(int h){
    bool orientation = (h%2);
    vector<bool> layer = g[h]; 

    string result;
    loop(i, 3)if(layer[i])result+="1";else result+="0";  

    bool b0 = layer[0];
    bool b1 = layer[1];
    bool b2 = layer[2]; 
    #if DEBUG
    printf("Doing layer %d, with blocks: ", h);
    cout << b0 << " " << b1 << " " << b2 << endl;
    printf("Trenutno tezisce %f %f\n", tezisce.fs, tezisce.sc);
    #endif

    //0. preveri, ce gre za zgornji sloj
    if(h!=0){
        //1. poglej ce je stabilno
        if(!isStable(layer, orientation, tezisce))return false;

        //2. vsako probaj vun dat 
        loop(i, 3){
            if(layer[i]){

                //zacasno nastavi
                layer[i] = 0;
                g[h][i] = 0;

                //za vse spodnje sloje preveri, ce je stabilno 
                bool deluje = 1;
                FOR(bot, h, H-1){
                    //printf("removed %d, checking layer %d, weight at %.3f %.3f\n", i, bot, getTempTezisce(bot).fs, getTempTezisce(bot).sc);
                    if(!isStable(g[bot], bot%2, getTempTezisce(bot))){deluje = false;break;}
                }
                
                g[h][i] = 1;
                layer[i] = 1;

                if(deluje) result[i] = '*';
            }
        }
    }

    //3. Popravi tezisce
    if(!orientation){loop(i, 3) if(layer[i]){xSum+=i+0.5; ySum += 1.5; blocks++;}}
    else {loop(i, 3) if(layer[i]){ySum+=i+0.5; xSum += 1.5; blocks++;}}

    tezisce.fs = xSum/blocks;
    tezisce.sc = ySum/blocks;
    
    //4 vrni vrednosti
    results.pb(result);
    return true;
}

void solve(){
    bool stable = 1;

    //ponastavi stvari
    start = mp(0,0);
    tezisce = mp(0,0);
    xSum = 0;
    ySum = 0;
    blocks = 0;
    memset(g, 0, sizeof g);
    results.clear();

    H = 0;
    cin >> H;

   

    loop(i, H){
        string s;
        cin >> s;
        loop(l, 3) g[i].pb(s[l] == '1');
        
    } 
    loop(i, H){
       if(!doLayer(i))stable=0; 
    }
    
    //print results
    if(stable){
        cout << yes << endl;
        for(auto line : results) cout << line << endl;
    }else{
        cout << no << endl;
    }
    cout << endl;
}

int main(){
    int T;
    cin >> T;
    loop(i, T) solve();
}