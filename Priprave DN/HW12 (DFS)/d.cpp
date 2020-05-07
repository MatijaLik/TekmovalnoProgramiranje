#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int, int>
#define piii pair<int , pii>
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
 
#define prodlimit 1010000
 
int N, M;
vector<vector<int>> grid;
vector<int> sosedi[prodlimit];
int input[prodlimit];//vhodna stopnja vozlisc
 
map<pii, int> label;
map<int, pii> inverseLabel;
 
 
//STAGE 2
int lowlink[prodlimit];
int dfsNum[prodlimit];
int component[prodlimit];
int curComp = 1;
 
 
vector<int> groups[prodlimit];
vector<int> s;
 
ll cas = 1;
void dfs(int node){
    //printf("dfs %d\n", node);
    s.pb(node);
    lowlink[node] = cas;
    dfsNum[node] = cas++;
    for(auto sosed : sosedi[node]){
        if(dfsNum[sosed] == 0){//neobiskano
            dfs(sosed);
            lowlink[node] = min(lowlink[node], lowlink[sosed]);
        }
        if(dfsNum[sosed] != -1){
            lowlink[node] = min(lowlink[node], dfsNum[sosed]);
        }
    }
    if(lowlink[node] == dfsNum[node]){
        //printf("clearing node %d\n", node);
        int popped = -1;
        while(1){
            popped = s.back();
            s.pop_back();
            dfsNum[popped] = -1;
            component[popped] = curComp;
            groups[curComp].pb(popped);
            //printf("popped %d\n", popped);
            if(popped == node)break;
        }
        curComp++;
    }
    
}
 
bool customSort(pii a, pii b){
    return grid[a.fs][a.sc] > grid[b.fs][b.sc];
}
 
 
struct Component{
    int id;
    int input;
    bool visited;
    vector<int> nodes;
    vector<int> sosedi;
    
};
 
vector<Component> allC;
 
int main(){
 
 
    int cnt = 1;
 
    cin >> N >> M;
    loop(i, N){//preberi in dodaj label
        vector<int> row;
        loop(j, M){
            int temp;
            cin >> temp;
            row.pb(temp);
 
            label[mp(i, j)] = cnt;
            inverseLabel[cnt] = mp(i, j);
            cnt++;
        }
        grid.pb(row);
    }
 
 
    //1 Naredi povezave
    //printf("1\n");
    //vrstice
    loop(i, N){
        vector<pii> tempR;
        loop(j, M) tempR.pb(mp(i, j));
        sort(all(tempR), customSort);
 
        loop(t, tempR.size()-1){
            sosedi[label[tempR[t]]].pb(label[tempR[t+1]]);
 
            //glej se za nazaj
            if(grid[tempR[t].fs][tempR[t].sc]==grid[tempR[t+1].fs][tempR[t+1].sc]){
                sosedi[label[tempR[t+1]]].pb(label[tempR[t]]);
            }
            else input[label[tempR[t+1]]]++;
        }
    }
 
 
    //stolpce
    loop(j, M){
        vector<pii> tempR;
        loop(i, N) tempR.pb(mp(i, j));
        sort(all(tempR), customSort);
 
        loop(t, tempR.size()-1){
            sosedi[label[tempR[t]]].pb(label[tempR[t+1]]);
 
            //glej se za nazaj
            if(grid[tempR[t].fs][tempR[t].sc]==grid[tempR[t+1].fs][tempR[t+1].sc]){
                sosedi[label[tempR[t+1]]].pb(label[tempR[t]]);
            }
            else input[label[tempR[t+1]]]++;
        }
    }
    
 
    /*
    printf("Vse povezave\n");
    loop(i, N)loop(j, M){
        printf("Node %d %d\n", i, j);
        for(auto sosed : sosedi[label[mp(i, j)]]){
            printf("%d %d\n", inverseLabel[sosed].fs, inverseLabel[sosed]. sc);
        }
    }*/
 
 
 
    //2. najdi mocno povezane komponente
    //printf("2\n");
    loop(i, prodlimit){
        lowlink[i] = 0;
        dfsNum[i] = 0;
        component[i] = -1;
    }
 
    //printf("2a\n");
    FOR(i, 1, N*M){
        if(dfsNum[i]==0) dfs(i);
    }
 
    //printf("2b\n");
    /*
    loop(i, N){
        loop(j, M){
            cout << component[label[mp(i, j)]] << " ";
        }
        cout << endl;
    }*/
 
    //indexes start at 1
    Component blank;
    allC.pb(blank);
 
    //printf("\nKOMPONENTE\n");
    FOR(i, 1, curComp-1){
        //sestavi komponento
        Component C;
        C.id = i;
        C.input = 0;
        C.visited = false;
        
        for(auto node : groups[i]){
            C.input += input[node];
            C.nodes.pb(node);
        }
 
        for(auto node : groups[i]){//dodaj sosede komponente
            for(auto sosed : sosedi[node]){
                if(component[sosed]!=component[node]) C.sosedi.pb(component[sosed]);
            }
        }
        allC.pb(C);
 
        /*
        printf("##########\nComponent %d\n", i);
        printf("Input: %d\n", C.input);
        printf("Vozlisca: ");
        for(auto node : C.nodes)printf("%d ", node);
        printf("\nSosedi: ");
        for(auto sosed : C.sosedi) printf("%d ", sosed);
        printf("\n");
        */
        
    }
 
    //printf("3\n");
    //3. Topolosko sortitanje
    //printf("TOPOLOGICAL SORT\n");
    int maxDepth = 0;
    int newGrid[N][M];
    for(int i = 1; i < curComp; i++){
        Component C = allC[i];
        if(!C.visited && C.input == 0){
            queue<pair<int, int>> q;
            q.push(make_pair(1, i));
            while(!q.empty()){
                
                //printf("Visiting component %d\n", q.front().second);
 
                Component curC = allC[q.front().second];
                int depth = q.front().first;
                maxDepth = max(maxDepth, depth);
 
                allC[q.front().second].visited = true;
                for(auto node : curC.nodes){
                    newGrid[inverseLabel[node].first][inverseLabel[node].second] = depth;
                }
 
                for(auto sosed : curC.sosedi){
                    allC[sosed].input--;
                    if(allC[sosed].input==0){
                        q.push(make_pair(depth+1, sosed));
                    }
                }
 
                q.pop();
            }
        }
    }
    
    loop(i, N){
        loop(j, M){
            if(newGrid[i][j] < 1 or newGrid[i][j] > maxDepth) while(1){};
            cout << maxDepth - newGrid[i][j] + 1 << " ";
        }
        cout << endl;
    }
 
}