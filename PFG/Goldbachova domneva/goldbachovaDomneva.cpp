#include <bits/stdc++.h>
using namespace std;

vector<int> prastevila;
bool aliJeSestavljeno[1000001];


void reseto(){
    for(int i = 2; i <= 1000000; i++){
        if(!aliJeSestavljeno[i]){
            prastevila.push_back(i);
            for(long long j = i*1LL*i; j <= 1000000; j += i)
                aliJeSestavljeno[j] = true;
        }
    }
}


int main(){

    reseto();
    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++){
        int n;
        cin >> n;
        for(auto p : prastevila){
            if(n - p >= 2 and !aliJeSestavljeno[n-p]){
                cout << p << " " << n-p << endl;
                break;
            }
        }
    }
}