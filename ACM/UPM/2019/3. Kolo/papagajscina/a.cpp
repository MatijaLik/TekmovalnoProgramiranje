#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    long long narocilo[n];
    
    int oseba = 0;
    long long najdrazja = 0;
    while(oseba < n){
        long long pica;
        cin >> pica;
        najdrazja = max(najdrazja, pica);
        if(cin.peek() == '\n'||cin.peek()=='\r'){
            narocilo[oseba] = najdrazja;
            najdrazja = 0;
            oseba++;
        }
    }
    for(int i =0;i<n;i++) cout << narocilo[i] << endl;
}
