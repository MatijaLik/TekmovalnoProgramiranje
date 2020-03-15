struct Edge
{
    int from, to, weight;
    bool operator<(Edge other) const
    {
        return weight > other.weight;
    }
};

struct TestStruct {
    int id;
    double number; 
    TestStruct(int anInt, double aDouble) : id(anInt), number(aDouble) { }
};

ios::sync_with_stdio(0);
cin.tie(0);

freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);