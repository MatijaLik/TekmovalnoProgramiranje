#include<stdio.h>
#include<iostream>
using namespace std;
#include <fstream>

string f(int n, int m){
    if(n > 2 && m > 2 && m == n) return "jala\n";
    else if (n > 2 && m > 2 && m!=n) return "buba\n";
    else if(min(n, m) <= 2 && max(n, m) > 2) return"buba\n";
    else if(n == m) return"jala\n";
    else return "buba\n";
}

int main(){
    int b, c;
    string a;
    cin >> a;
    srand(rand()%(stoi(a)+1));
    /*
    b = rand()%1000000000;
    c = rand()%1000000000;*/
    cin >> b >> c;
    string instr = "./test/" + a + string(".in");
    string outstr = "./test/" + a + string(".out");

    ofstream in, out;
    in.open(instr);
    out.open(outstr);

    in << b << " " << c << endl;
    in.close();
    out << f(b, c) << endl;
    out.close();
}