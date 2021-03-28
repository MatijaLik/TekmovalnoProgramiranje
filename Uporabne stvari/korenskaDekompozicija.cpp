#define limit 1000100
ll arr[limit];
ll bloki[1100];
ll dolzinaBloka = sqrt(limit);
 
void update(int i, ll val){
    arr[i] = min(val, arr[i]);
    int blokId = i / dolzinaBloka;
    bloki[blokId] = min(bloki[blokId], val);
}
 
int query(int L, int R){
    ll res = inf*1LL*inf;
 
    int p = L;
    //leva stran
    while(p < R and p % dolzinaBloka){
        res = min(res, arr[p]);
        p++;
    }
    //bloki
    while(p + dolzinaBloka <= R){
        res = min(res, bloki[p/dolzinaBloka]);
        p++;
    }
 
    //desno
    while(p <= R){
        res = min(res, arr[p]);
        p++;
    }
 
    //printf("query %lld %lld -> %lld\n", L, R, res);
    return res;
}
