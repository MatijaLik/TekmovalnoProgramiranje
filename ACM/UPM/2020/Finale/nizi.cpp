#include <iostream>
#include <string>
#include <stack>
 
using namespace std;
 
int main(){
 
    //while(1){
    string s = "001101001";
    string s1, eh;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> s;
    //if(s == "a") break;
    stack <string > op;
    pair <int, pair <int, int > > best;
 
    int c = 0;
    int start = 0;
    int end = 0;
    bool bol = 0;
    
    while(1){
        c = 0;
        start = 0;
        end = 0;
        best = make_pair(0, make_pair(0, 0));
        
        for(int i = 0; i < s.size()-1; i++){
            if(s[i] == '0' and s[i+1] == '1'){
                end = i+2;
                i++;
            }
            else if(s[i] == '1' and s[i+1] == '0'){
                end = i+2;
                i++;
            }
            else{
                c = end-start;
                if(c > best.first){
                    best.first = c;
                    best.second = make_pair(start, end);
                }
                i++;
                start = i+1;
                end = i+1;
            }
        }
        c = end-start;
        if(c > best.first){
            best.first = c;
            best.second = make_pair(start, end);
        }
 
        start = 1;
        end = 1;
 
        for(int i = 1; i < s.size()-1; i++){
            if(s[i] == '0' and s[i+1] == '1'){
                end = i+2;
                i++;
            }
            else if(s[i] == '1' and s[i+1] == '0'){
                end = i+2;
                i++;
            }
            else{
                c = end-start;
                if(c > best.first){
                    best.first = c;
                    best.second = make_pair(start, end);
                }
                i++;
                start = i+1;
                end = i+1;
            }
        }
        c = end-start;
        if(c > best.first){
            best.first = c;
            best.second = make_pair(start, end);
        }
 
        //cout << "best:  " << best.first << " " << best.second.first << " " << best.second.second << endl;
        //break;
        
        s1 = "";
        bol = 0;
        
        for(int i = 0; i < s.size(); i++){
            if(i < best.second.first){
                eh = "z "; eh += s[i];
                op.push(eh);
            }
            else if(i >= best.second.second){
                eh = "k "; eh += s[i];
                op.push(eh);
            }
            else if(i%2 == best.second.first%2){
                s1 = s1 + s[i];
                bol = 1;
            }
        }
        //cout << s1 << endl;
        if(bol) op.push("p");
        
        s = s1;
        if(s.size() == 1){
            eh = "z ";
            eh += s[0];
            op.push(eh);
            break;
        }
        if(s.empty()) break;
        
        
    }
    
    cout << op.size() << endl;
    while(!op.empty()){
        cout << op.top() << endl;
        op.pop();
    }
    
    //}
}
