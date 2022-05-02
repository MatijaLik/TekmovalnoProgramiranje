#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f(ll k){
    int opt=100'000'000;
    for(int d=1; d<=k;d++){
        if(k%d==0){
            int a = d;
            int b = k/d;
            int obseg = 2*a +2*b;
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
    
    b = rand()%999998 + 2;

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