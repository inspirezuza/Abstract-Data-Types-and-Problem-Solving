#include <stdio.h>

int n;
char maze[110][110]={};
int visited[110][110]={};

int traverseMaze(int x,int y){
    if(maze[x][y] == 'G'){
        return 1;
    }
    if((maze[x][y] != ' ' && maze[x][y] != 'S') || visited[x][y]){
        return 0;
    }
    
    visited[x][y] = 1;
    if(traverseMaze(x+1,y)){
        maze[x][y] = '.';
        return 1;
    }
    if(traverseMaze(x,y+1)){
        maze[x][y] = '.';
        return 1;
    }
    if(traverseMaze(x-1,y)){
        maze[x][y] = '.';
        return 1;
    }
    if(traverseMaze(x,y-1)){
        maze[x][y] = '.';
        return 1;
    }  
}

int main(){
    int x,y;
    scanf("%d ",&n);
    for(int i=0;i<n;i++){
        fgets(maze[i], sizeof(maze[i]), stdin);
        for(int j=0;j<n;j++){
            if(maze[i][j] =='S'){
                x=i;
                y=j;
            }
        }
    }
    traverseMaze(x,y);
    maze[x][y] = 'S';
    for(int i=0;i<n;i++){
        printf("%s",maze[i]);
    }
    return 0;
}