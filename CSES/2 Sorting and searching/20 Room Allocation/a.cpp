#include<bits/stdc++.h>
using namespace std;


struct Guest{
    int id;
    int arrive;
    int depart;
    Guest(int _id, int _arrive, int _depart): id(_id), arrive(_arrive), depart(_depart){}
    
    bool operator < (Guest & other){
        if(arrive != other.arrive) return arrive < other.arrive;
        if(depart != other.depart) return depart < other.depart;
        return id < other.id;
    }
};

long long hsh(pair<int, int> p){return 1000000007*p.first + p.second;}
int main(){
    int n;
    cin >> n;
    vector<Guest> s, o;
    for(int i=0;i<n;i++){
        int a, b;
        cin >> a >> b;
        s.push_back(Guest(i, a, b));
    }
    o = s;
    sort(s.begin(), s.end());
    unordered_map<int, int> m;
    int ans = 0;
    priority_queue<pair<int, int>> q;
    for(auto e : s){
        int room;
        if(q.empty() or q.top().first < -e.arrive){
            ans++;
            room = ans;
        }else{
            room = q.top().second;
            q.pop();
        }
        q.push(make_pair(-e.depart - 1, room));
        m[e.id] = room;
    }
    cout << ans << endl;
    for(auto e : o) cout << m[e.id]<< " ";
    cout << endl;
    return 0;
}
