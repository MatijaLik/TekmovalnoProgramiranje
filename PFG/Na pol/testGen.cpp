#include<bits/stdc++.h>
using namespace std;
int f(int n){
    int ans = 0;
    for(int ex = 1; ex <= 30; ex++)
        ans += n / (1<<ex);
    return ans;
}
int main(){
    for(int i = 0; i < 10; i++){
        char c = i + '0';
        string s = "./testcases/";
        s += c;
        s += ".in";
        ofstream outfile(s);
        int r = rand()%100001 + 1;
        outfile << r;
        outfile.close();

        s = "./testcases/";
        s += c;
        s += ".out";
        ofstream boutfile(s);
        boutfile << f(r);
        boutfile.close();

        cout << s << endl;
    }
}