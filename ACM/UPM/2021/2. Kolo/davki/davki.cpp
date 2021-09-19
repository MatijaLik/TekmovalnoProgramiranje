#include <iostream>
#include <string>
#include<stdio.h>
#include<string>
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()

double strtoint(string s){
    double a = 0;
    double t1;
    double ex = 0;
    for(int i = s.size()-1; i > -1; i--){
        t1 = s[i] - 48;
        for(int j = 0; j < ex; j++){
            t1 = t1*10;
        }
        a += t1;
        ex++;
    }
    //cout << s << " " << a << endl;
    return a;
}

string dti(double t){
    bool negativ = false;
    if(t < 0) negativ = true;
    t = abs(t);
    string s = "";
    t *= 100;
    int digit = 0;
    int a = t;

    if(a == 0) return s;
    while(a > 0){
        s += (char)((a%10) + '0');

        digit++;
        a /= 10;
        if(digit == 2){
            s += ",";
            break;
        }
    }

    if(a == 0) s += "0";

    digit = 0;
    while(a > 0){
        if(digit % 3 == 0 and digit != 0) s += ".";

        s += (char)((a%10) + '0');
        digit++;
        a /= 10;
    }


    if(negativ) s += "-";
    reverse(all(s));
    return s;

}

int main(){
    string s[10];
    int vzd,stud;

    cin >> s[1] >> s[1];
    for(int i = 0; i < s[1].size(); i++){
        if(s[1][i] == '/'){
            s[1].erase(s[1].begin()+i,s[1].end());
        }
    }
    stud = strtoint(s[1]);

    cin >> s[1] >> s[1];
    for(int i = 0; i < s[1].size(); i++){
        if(s[1][i] == '/'){
            s[1].erase(s[1].begin()+i,s[1].end());
        }
    }
    vzd = strtoint(s[1]);

    double brutoall, prispevki, netoall, osnova, stdwork, taxedall, akontacija;
    brutoall = 0;
    prispevki = 0;
    netoall = 0;
    osnova = 0;
    stdwork = 0;
    taxedall = 0;
    akontacija = 0;

    double brut, pris, akon;

    while(!cin.eof()){
        cin >> s[1] >> s[2] >> s[3] >> s[4];
        if (cin.eof())break;
        //cout << "echo "  << s[1] << " " << s[2] << " " << s[3] << " " << s[4] << " " << endl;
        for(int i = 2; i < 5; i++){
            for(int j = 0; j < s[i].size(); j++){
                if(s[i][j] == '.' or s[i][j] == ','){
                    s[i].erase(s[i].begin()+j);
                }
            }
        }
        
        brut = strtoint(s[2])/100;
        pris = strtoint(s[3])/100;
        akon = strtoint(s[4])/100;

        //cout << brut << " " << pris << " " << akon << endl;

        brutoall += brut;
        prispevki += pris;
        akontacija += akon;

        if(s[1] == "1101"){ //plača
            osnova += brut - pris;
            taxedall += brut;
        }
        // else if(s[1] == "1101/1" or s[1] == "1101/2" or s[1] == "1105"){ //neobdavčeno

        // }
        else if(s[1] == "1211"){//studentsko delo, prizna se 10% stroskov od bruto zneska
            osnova += brut - brut*0.10 - pris;
            stdwork += brut - brut*0.10 - pris;
            taxedall += brut;
        }
        else if(s[1] == "1230"){//drugo, 10%
            osnova += brut - brut*0.10 - pris;
            taxedall += brut;
        }
    }

    //splosna olajsava
    double olajsava = 0;
    if(vzd < 12){
        if(taxedall >= 13316.83){
            olajsava = 3500 * ((12-vzd)/12);
        }
        else{
            olajsava = (3500 + (18700.38-1.40427*taxedall)) * ((12-vzd)/12);
        }
        osnova -= olajsava;
        //printf("olajsava: %.2lf\n", olajsava);
    }

    
    
    #warning probaj vedno odstet 3500
    //studentska olajsava
    
    if(stud > 0){
        if(stdwork > 3500){
            osnova -= 3500;
        }
        else{
            osnova -= stdwork;
        }
    }

    //if(stud>0) osnova -= 3500;

    if(osnova < 0) osnova = 0;
    //cout << "osnova " << osnova << endl;

    double tax = 0;

    // osnova do 8.500,00: 16%
    // osnova do 25.000,00: 26%
    // osnova do 50.000,00: 33%
    // osnova do 72.000,00: 39%
    // osnova nad 72.000,00: 50%
    if(osnova > 72000){
        tax += (osnova-72000)*0.5;
        osnova = 72000;
    }
    if(osnova > 50000){
        tax += (osnova-50000)*0.39;
        osnova = 50000;
    }
    if(osnova > 25000){
        tax += (osnova-25000)*0.33;
        osnova = 25000;
    }
    if(osnova > 8500){
        tax += (osnova-8500)*0.26;
        osnova = 8500;
    }
    if(osnova <= 8500){
        tax += osnova*0.16;
    }

    //cout << "tax: " << tax << endl;
    //cout << "akontacija: " << akontacija << endl;

    double tax_to_pay = tax - akontacija;

    netoall =  brutoall - tax_to_pay - prispevki - akontacija;
    // - akontacija;

    double breme = 100 - (netoall/brutoall)*100;



    cout << dti(tax_to_pay) << "\n"
     << dti(brutoall) << " " << dti(prispevki) << " " << dti(tax) << " " << dti(netoall) << " " << dti(breme) << "%" << endl;
}
