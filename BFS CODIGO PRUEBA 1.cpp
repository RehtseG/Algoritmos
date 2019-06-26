#include<bits/stdc++.h>
using namespace std;
 
#define MAX 1000
char ady[MAX][MAX];
bool visitado[MAX][MAX];
 
struct Estado{
    int x;
    int y;
    int d;
    Estado(int x1, int y1, int d1) : x(x1), y(y1), d(d1) {}
};
 
int BFS(int x, int y, int h, int w){
    Estado inicial(x,y,0);
    queue<Estado>estados;
    estados.push(inicial);
    memset(visitado, false, sizeof(visitado));
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
 
    while(!estados.empty()){
        Estado actual = estados.front();
        estados.pop();
        if(ady[actual.x][actual.y] == 'O')
            return actual.d;
        visitado[actual.x][actual.y] = true;
        for(int i = 0; i < 4; i++){
            int nx = dx[i] + actual.x;
            int ny = dy[i] + actual.y;
 
            if(nx >= 0 && nx < h && ny >= 0 && ny < w && ady[nx][ny] != 'X' && !visitado[nx][ny]){
                Estado adyacente(nx, ny, actual.d + 1);
                estados.push(adyacente);
            }
        }
    }
    return -1;
}
 
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int h, w, x, y, t;
    cin>>h>>w>>t;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin>>ady[i][j];
            if(ady[i][j] == 'C'){
                x = i;
                y = j;
            }
        }
    }
    cout<<BFS(x, y, h, w);
    return 0;
}
