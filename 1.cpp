#include <stdio.h>
#include <string.h>

#define max 201

void swap(char *a, char *b){
	char temp = *a;
	*a = *b;
	*b = temp;
}

void recursive(char *word, int start, int n){
	if (start >= n) return;
	swap(word+start, word+n);
	recursive(word, ++start, --n);
}

int main(){
	int n;
	scanf("%d", &n); getchar();
	for(int i=0; i<n; i++){
		char word[max];
		scanf("%s", word); getchar();
		recursive(word, 0, strlen(word)-1);
		if(i < n-1)  printf("%s ", word);
		else if(i == n-1) printf("%s\n", word);
	}
	return 0;
}
