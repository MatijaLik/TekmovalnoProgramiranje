#include<bits/stdc++.h>
using namespace std;
int f(int n){
    int ans = 0;
    for(int ex = 1; ex <= 30; ex++)
        ans += n / (1<<ex);
    return ans;
}
int main(){
    srand (time(NULL));
    for(int i = 0; i < 10; i++){
        char c = '0' + i;
        string s = "./testcases/1";
        s += c;
        s += ".in";
        ofstream outfile(s);
        int r = rand()%1000000 + 1;
        outfile << r;
        outfile.close();

        s = "./testcases/1";
        s += c;
        s += ".out";
        ofstream boutfile(s);
        boutfile << f(r);
        boutfile.close();

        cout << s << endl;
    }
}