#include <stdio.h>
#include <string.h>

//#define max 10
#define max 1000

//char map[max][max];
char map2[max][max];

void recursive(int n, int i, int j, char pattern, char map[][max]){
	if(i < 0 || i >= n || j < 0 || j >= n) return;
//	if(map[i][j] == '#' && step > 10) return;
	
	map2[i][j] = '#';

	
	if(pattern == '1'){ // up
		recursive(n, i+1, j, pattern, map);
	}
	else if(pattern == '2'){ // down
		recursive(n, i-1, j, pattern, map);
	}
	else if(pattern == '3'){ //right
		recursive(n, i, j+1, pattern, map);
	}
	else if(pattern == '4'){ //left
		recursive(n, i, j-1, pattern, map);
	}
	else if(pattern == '5'){ // ne
		recursive(n, i+1, j+1, pattern, map);
	}
	else if(pattern == '7'){ // sw
		recursive(n, i-1, j-1, pattern, map);
	}
	else if(pattern == '8'){ // nw
		recursive(n, i+1, j-1, pattern, map);
	}
	else if(pattern == '6'){ // se
		recursive(n, i-1, j+1, pattern, map);
	}
	
	return;
}

int main(){
	int n;
	scanf("%d", &n);
	
	char map[n][max];
	
	for(int i=0; i<n; i++){
		scanf("%s", map[i]);
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			map2[i][j] = map[i][j];
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(map[i][j] == '+'){
				recursive(n, i, j, '1', map);
				recursive(n, i, j, '2', map);
				recursive(n, i, j, '3', map);
				recursive(n, i, j, '4', map);
			}
			else if(map[i][j] == '|'){
				recursive(n, i, j, '1', map);
				recursive(n, i, j, '2', map);
			}
			else if(map[i][j] == '_'){
				recursive(n, i, j, '3', map);
				recursive(n, i, j, '4', map);
			}
			else if(map[i][j] == '\\'){
				recursive(n, i, j, '5', map);
				recursive(n, i, j, '7', map);
			}
			else if(map[i][j] == '/'){
				recursive(n, i, j, '6', map);
				recursive(n, i, j, '8', map);
			}
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("%c", map2[i][j]);
		}
		printf("\n");
	}
	
		
	return 0;
}
