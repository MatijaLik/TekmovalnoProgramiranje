#include<iostream>
using namespace std;
typedef long long ll;

/*
 * Motivacija:
 * Naj bo zetoni[i][j] število žetonov na polju (i, j)
 * Naj bo dimenzija mreže W*H
 * Za vsako polje želimo poračunati njen izkupiček.
 * Stvar poskusimo izvesti s časovno zahtevnostjo O(W*H)
 */

/*
 * Vhodni podatki:
 * V prvi vrstici se nahajata stevili W in H (sirina in visina mreze)
 * V naslednjih H vrsticah se nahaja W stevil locenih s presledkom.
 * j-to stevilo v i-ti vrstici ustreza stevilu zetonov na polju (i, j)
 * 
 * Podatke nam posreduje standardni vhod 
 * 
 * Primer vhoda:
 * 5 4
 * 0 0 1 2 0
 * 0 2 3 1 0
 * 0 0 2 1 2
 * 0 0 0 3 1
 */

int main(){
    int W, H;
   cin >> W >> H;
   int zetoni[H][W];
   for(int i=0;i<H;i++){
       for(int j=0;j<W;j++){
           cin >> zetoni[i][j];
        }
    }
    
    /*
     * Vrednost neki_izkupicek[i][j]
     * nam pove, koliko zetonov poberemo, ce postavimo nov 
     * zeton na (i, j) in se premikamo v neko doloceno smer.
     */
    int gornji_izkupicek[H][W];
    int spodnji_izkupicek[H][W];
    int levi_izkupicek[H][W];
    int desni_izkupicek[H][W];
    
    /*
     * Vsako izmed spremenjlivk poracunamo s kumulativnimi vsotami
     * Pri racunanju spretno upostevamo polja z nic zetoni
     */
    for(int i=0;i<H;i++){
        ll cumSum=0;
        for(int j=0;j<W;j++){
            levi_izkupicek[i][j]=cumSum;
            cumSum = zetoni[i][j] ? cumSum + zetoni[i][j] : 0;
        }
        cumSum=0;
        for(int j=W-1;j>=0;j--){
            desni_izkupicek[i][j]=cumSum;
            cumSum = zetoni[i][j] ? cumSum + zetoni[i][j] : 0;
        }
    }
    for(int j=0;j<W;j++){
        ll cumSum=0;
        for(int i=0;i<H;i++){
            gornji_izkupicek[i][j]=cumSum;
            cumSum = zetoni[i][j] ? cumSum + zetoni[i][j] : 0;
        }
        cumSum=0;
        for(int i=H-1;i>=0;i--){
            spodnji_izkupicek[i][j]=cumSum;
            cumSum = zetoni[i][j] ? cumSum + zetoni[i][j] : 0;
        }
    }
    
    /*
     * Poiscemo polje z najvecjim skupnim izkupickom
     */
    int najboljsi_i = -1;
    int najboljsi_j = -1;
    ll najvecji_izkupicek = -1;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            ll skupni_izkupicek = 
                gornji_izkupicek[i][j] +
                spodnji_izkupicek[i][j] +
                levi_izkupicek[i][j] + 
                desni_izkupicek[i][j];
            if(skupni_izkupicek>najvecji_izkupicek){
                najvecji_izkupicek = skupni_izkupicek;
                najboljsi_i = i;
                najboljsi_j = j;
            }
        }
    }
    printf("Največ točk prejmemo, če postavimo žeton v %d-to vrstico ter %d-ti stolpec.\n Stolpci in vrstice so oštevilčeni od 0 naprej, začenši zgoraj levo. \n Ob tem bomo nabrali %lld točk.\n", 
           najboljsi_i, najboljsi_j, najvecji_izkupicek
           );
}
