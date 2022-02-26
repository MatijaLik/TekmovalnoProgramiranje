#include<iostream>
#include<math.h>
using namespace std;
typedef long long ll;
int main(){
    int r, n;
    cin >> r >> n;
    
    /*
     * Ker imajo vsi ulomki v imenovalcu
     * neko potenco 2^i (i <= 20), lahko
     * te ulomke shranimo v float in
     * s tem ne izgubimo na preciznosti
     */
    float odgovor = 0;
    for(int _r=0;_r<r;_r++){
        string s;
        cin >> s;
        for(int i=1;i<=n;i++){
            if(s[i-1]=='S'){
                odgovor += 1.0/(1<<i);
            }
        }
    }
    cout << round(odgovor) << endl;
    return 0;
}
