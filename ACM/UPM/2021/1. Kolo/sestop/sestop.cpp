#include <iostream>
#include <queue>

using namespace std;

long long grid[105][105];
long long a[105][105];
long long n, m, k;

priority_queue <pair<long long, pair<int, int > > > pq;

bool f = true;

void solve(pair <int, int > c){
    if(a[c.first][c.second] != 0 && f == false){
        return;
    }
    if(f) f = false;
    //cout << "c:     " << c.first << " " << c.second << " " << a[c.first][c.second] << endl;
     
    if(c.first > 0){
        if(a[c.first-1][c.second] == 0){
            pq.push(make_pair(-grid[c.first-1][c.second], make_pair(c.first-1, c.second)));
        }
        else if(a[c.first-1][c.second] != 0 && grid[c.first-1][c.second] < grid[c.first][c.second]){
            a[c.first][c.second] += a[c.first-1][c.second];
        }
    }

    if(c.second > 0){
        if(a[c.first][c.second-1] == 0){
            pq.push(make_pair(-grid[c.first][c.second-1], make_pair(c.first, c.second-1)));
        }
        else if(a[c.first][c.second-1] != 0 && grid[c.first][c.second-1] < grid[c.first][c.second]){
            a[c.first][c.second] += a[c.first][c.second-1];
        }
    }

    if(c.first < n-1){
        if(a[c.first+1][c.second] == 0){
            pq.push(make_pair(-grid[c.first+1][c.second], make_pair(c.first+1, c.second)));
        }
        else if(a[c.first+1][c.second] != 0 && grid[c.first+1][c.second] < grid[c.first][c.second]){
            a[c.first][c.second] += a[c.first+1][c.second];
        }
    }

    if(c.second < m-1){
        if(a[c.first][c.second+1] == 0){
            pq.push(make_pair(-grid[c.first][c.second+1], make_pair(c.first, c.second+1)));
        }
        else if(a[c.first][c.second+1] != 0 && grid[c.first][c.second+1] < grid[c.first][c.second]){
            a[c.first][c.second] += a[c.first][c.second+1];
        }
    }
}

int main(){
    pair <int, int > start = make_pair(0, 0);
    pair <int, int > end = make_pair(0, 0);

    cin >> n >> m >> k;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] > grid[start.first][start.second]) start = make_pair(i, j);
            if(grid[i][j] < grid[end.first][end.second]) end = make_pair(i, j);
        }
    }

    a[end.first][end.second] = 1;
    pq.push(make_pair(-grid[end.first][end.second], end));

    pair <int, int > top;

    while(!pq.empty()){
        top = pq.top().second;
        pq.pop();
    	solve(top);
    }
    /*
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }*/

    top = start;
    string rez = "";

    while(1){
        if(top == end)break;

        if(top.first < n-1){
            if(grid[top.first+1][top.second] < grid[top.first][top.second]){
                if(a[top.first+1][top.second] < k) k -= a[top.first+1][top.second];
                else{
                    top.first++;
                    rez += 'J';
                    continue;
                }
            }
        }

        if(top.first > 0){
            if(grid[top.first-1][top.second] < grid[top.first][top.second]){
                if(a[top.first-1][top.second] < k) k -= a[top.first-1][top.second];
                else{
                    top.first--;
                    rez += 'S';
                    continue;
                }
            }
        }

        if(top.second < m-1){
            if(grid[top.first][top.second+1] < grid[top.first][top.second]){
                if(a[top.first][top.second+1] < k) k -= a[top.first][top.second+1];
                else{
                    top.second++;
                    rez += 'V';
                    continue;
                }
            }
        }

        if(top.second > 0){
            if(grid[top.first][top.second-1] < grid[top.first][top.second]){
                if(a[top.first][top.second-1] < k) k -= a[top.first][top.second-1];
                else{
                    top.second--;
                    rez += 'Z';
                    continue;
                }
            }
        }
    }
    cout << rez << endl;
}