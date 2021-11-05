#include<stdio.h>
#include<iostream>
using namespace std;
#include <fstream>

int f(int N){
    int pravda = 0;
    if(N > 650){
        pravda += (N - 650)*5;
        N = 650; 
    }
    if(N > 150){
        pravda += (N - 150)*2;
        N = 150;
    }

    pravda += N;
    return pravda;
    //printf("%d\n", pravda);
}

int main(){
    int a;
    int b;
    cin >> a >> b;
    string instr = "./test/" + to_string(a) + string(".in");
    string outstr = "./test/" + to_string(a) + string(".out");

    ofstream in, out;
    in.open(instr);
    out.open(outstr);

    in << b << endl;
    in.close();
    out << f(b) << endl;
    out.close();
}