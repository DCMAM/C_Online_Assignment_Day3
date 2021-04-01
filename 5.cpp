#include <stdio.h>

#define max 20

int total = 0;
char unique[50][max][max];

void recursive(char maze[][max],int i,int j,int n,char final_maze[][max]){	
	if(i < 0 || i >= n || j < 0 || j >= n) return;
    if(maze[i][j] == '#' || final_maze[i][j] == '*') return;
	
    if(maze[i][j] == 'p'){
		final_maze[i][j] = 'p';
		
		for(int a=0; a<n; a++){
			for(int b=0; b<n; b++){
				if(maze[a][b] == '#') unique[total][a][b] = '#'; 
				else if(maze[a][b] == 'j') unique[total][a][b] = 'j'; 
				else unique[total][a][b] = final_maze[a][b];
			}
		}
		
		total++;
        final_maze[i][j] = '.';
        
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
	int T, row, col;
	scanf("%d", &T);
	
	char maze[T][max];
	
	for(int i=0; i<T; i++){
		scanf("%s", &maze[i]); 
		for(int j=0; j<T; j++){
			if(maze[i][j] == 'j'){
				row = i;
				col = j;
			}
		}
	}
	
	char final_maze[T][max];
	
	for(int i=0; i<T; i++){
		for(int j=0; j<T; j++){
			final_maze[i][j] = '.';
		}
	}
 	
	recursive(maze, row, col, T, final_maze);
    
	for(int x=0; x<total; x++){
 	   for(int a=0; a<T; a++){
			for(int b=0; b<T; b++){
				printf("%c", unique[x][a][b]);
			}
			printf("\n");
		}
		printf("\n");
	}
	
    return 0; 
}

