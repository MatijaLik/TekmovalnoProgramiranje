#include<iostream>
#include<string>
using namespace std;
/*
 * Vhodni podatki:
 * Prva vrstica vsebuje vzorec
 * Druga vsrtica vsebuje N, dolžina seznama besed
 * Naslednjih N vrstic vsebuje po eno besedo
 * 
 * Primer vhoda:
 *  *i*a
 *  5
 *  miza
 *  zima
 *  riba
 *  mirta
 *  prva
 */

int main(){
    string vzorec;
    cin >> vzorec;
    int N;
    cin >> N;
    for(int n=0;n<N;n++){
        string beseda;
        cin >> beseda;
        
        //Preverimo ujemanje dolžin besed
        if(beseda.length()!=vzorec.length()) continue;
        
        bool ujemanje = true;
        //Preverimo ujemanje znakov
        for(int i=0;i<vzorec.length();i++){
            if(vzorec[i]!='*'&&vzorec[i]!=beseda[i]) {
                ujemanje=false;
                break;
            }
        }
        
        //Če se vse ujema, besedo izpišemo
        if(ujemanje) 
            cout << beseda << endl;
    }
}
