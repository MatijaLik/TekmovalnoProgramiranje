#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f(ll k){
    ll opt=10'000'000'000;
    for(ll d=1; d*d<=k;d++){
        if(k%d==0){
            ll a = d;
            ll b = k/d;
            ll obseg = 2*a +2*b;
            if(obseg<opt)
                opt = obseg;
        }
    }
    return opt;
}

int main(){
    ll b;
    string a;
    cin >> a;
    srand(rand()%(stoi(a)+1));
    
    cin >> b;

    string instr = "./test/" + a + string(".in");
    string outstr = "./test/" + a + string(".out");

    ofstream in, out;
    in.open(instr);
    out.open(outstr);

    in << b << endl;
    in.close();
    out << f(b) << endl;
    out.close();
}