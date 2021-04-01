#include <stdio.h>

#define max 10

int total=0, flag=0;

void recursive(char maze[][max],int i,int j,int n,char final_maze[][max]){	
	if(i < 0 || i >= n || j < 0 || j >= n) return;
    if(maze[i][j] == '#' || final_maze[i][j] == '*') return;
    
    if(maze[i][j] == 'P'){
    	flag = 1;
		return;
    }
    
    final_maze[i][j] = '*';
    
	recursive(maze,i-1,j,n,final_maze);
	recursive(maze,i+1,j,n,final_maze);
    recursive(maze,i,j-1,n,final_maze);
    recursive(maze,i,j+1,n,final_maze);

    final_maze[i][j] = '.';
    
    return;
} 

int main() {
	int n, row, col;
	scanf("%d", &n);
	
	char map[n][max];
	
	for(int i=0; i<n; i++){
		scanf("%s", map[i]);
		for(int j=0; j<n; j++){
			if(map[i][j] == 'J'){
				row = i;
				col = j;
			}
		}
	}
	
	char final_maze[n][max];
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			final_maze[i][j] = '.';
		}
	}
	
	recursive(map, row, col, n, final_maze);

	if(flag == 1) printf("J found its way to P.\n");
	else if(flag == 0) printf("J couldn't find its way to P.\n");
	
    return 0; 
}

