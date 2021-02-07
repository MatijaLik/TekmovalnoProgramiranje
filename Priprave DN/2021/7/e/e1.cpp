#include <iostream>
#include <vector>
#include <map>
#include <set>
#define loop(i, k) for (int i = 0; i < k; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define pb push_back
using namespace std;


int main()
{

    set<int> p;
    map<set<int>, int> s;
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    unsigned long long allTheLonelyPeople = 0;
    unsigned long long cnt = 0;
    cin >> n >> m;
    loop(i, m)
    {
        int a, b;
        cin >> a >> b;
        p[a].insert(b);
        p[b].insert(a);
    }
    FOR(i, 1, n + 1)
    {
        if (p[i].size() == 0)
        {
            allTheLonelyPeople++;
            continue;
        }
        cnt += s[p[i].size()][p[i]];
        s[p[i].size()][p[i]]++;
    }
    loop(i, 1000010) s[i].clear();
    FOR(i, 1, n + 1)
    {
        if (p[i].size() == 0)
            continue;
        p[i].insert(i);
    }
    FOR(i, 1, n + 1)
    {
        if (p[i].size() == 0)
            continue;
        cnt += s[p[i].size()][p[i]];
        s[p[i].size()][p[i]]++;
    }
    cnt += (allTheLonelyPeople * (allTheLonelyPeople - 1)) / 2;
    cout << cnt << endl;
    return 0;
}