#include <stdio.h>
#define NUM    300
int grid[NUM][NUM];
int visit[NUM][NUM];

void DFS(int x, int y, int m, int n){
    if (x<0 || y<0 || x>=m || y>=n || grid[x][y] == 0 || visit[x][y] ==1 ){
        return ;
    }
    
    visit[x][y] = 1;
    
    DFS(x+1, y, m, n);
    DFS(x-1, y, m, n);
    DFS(x, y+1, m, n);
    DFS(x, y-1, m, n);
    
}

// MODIFY THIS CODE
int get_mine(int m, int n) {
    int result = 0;
    
    for( int i = 0; i<m; i++) {
        for (int j=0; j<n; j++){
            visit[i][j]=0;
        }
    }
    
    for ( int i=0 ; i< m; i++){
        for (int j=0; j<n; j++){
            if (visit[i][j] ==0 && grid[i][j] ==1){
                DFS(i,j,m,n);
                result +=1;
            }
        }
    }
    return result;
}

int main() {
    /* DO NOT MODIFY */
    int i=0, j=0, m=0, n=0, result=0;

    scanf("%d %d", &m, &n);
    for(i=0; i<m; i++) {
        for (j=0; j<n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    
    result=get_mine(m,n);
    printf("%d\n", result);
    /* DO NOT MODIFY */
}
