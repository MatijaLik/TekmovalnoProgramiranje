#include<bits.stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i = 0; i <n;i++){
        string s, ans;
        cin >>s;
        for(int j = 0; j <s.size();j++{
            char e = s[j];
            ans += e;
            if(e == 'a'||e=='e'||e=='i'||e=='o'||e=='u') {
                ans += "p";
                ans += e;
            }
        }
        cout << ans << endl;
    }
}
