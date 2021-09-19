ll r[limit];
ll parent[limit];

ll find(ll x){
    if(parent[x]==x) return x;
    return parent[x] = find(parent[x]);
}

void un(ll x, ll y){
    ll xRoot = find(x);
    ll yRoot = find(y);
    if(r[xRoot]<r[yRoot]){
        ll temp = yRoot;
        yRoot = xRoot;
        xRoot = temp;
    }
    parent[yRoot] = xRoot;
    if(r[xRoot] == r[yRoot]) r[xRoot]++;
}
