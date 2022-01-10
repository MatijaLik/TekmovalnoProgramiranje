#include<bits/stdc++.h>
#include "hint.h"
#define pb push_back
using namespace std;

std::vector<bool> genHint(const std::vector<int>& a, const std::vector<int>& b, const std::vector<int>& sol){
    vector<bool> ans;
    int p1 = 0;
    int p2 = 0;
    while(p2 < sol.size()){
        if(a[p1] == sol[p2]){
            ans.pb(1);
            p1++;
            p2++;
        }else{
            ans.pb(0);
            p1++;
        }
    }
    return ans;
}

std::vector<int> solve(const std::vector<int>& a, const std::vector<int>& b, const std::vector<bool>& hint){
    vector<int> ans;
    for(int i = 0; i<hint.size();i++){
        if(hint[i]) ans.pb(a[i]);
    }
    return ans;
}