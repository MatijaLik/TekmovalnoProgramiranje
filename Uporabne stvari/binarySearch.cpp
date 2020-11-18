#include<bits/stdc++.h>
using namespace std;
void countSmallerRight(int A[], int len) 
{ 
    set<int> s; 
    int countSmaller[len]; 
    for (int i = len - 1; i >= 0; i--) { 
        s.insert(A[i]); 
        auto it = s.lower_bound(A[i]); 
        countSmaller[i] = distance(s.begin(), it); 
    } 
  
    for (int i = 0; i < len; i++) 
        cout << countSmaller[i] << " "; 
} 