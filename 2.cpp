#include <stdio.h>

int flag = 0, step = 1;

void fib(int num1, int num2, int x){
	if(num2 > x) return;
	
	int total = num1 + num2;
	
	if(x == total){
		flag = 1;
		return;	
	} 
	
	step++;
	return fib(num2, total, x);
}

int main(){
	int n, num1 = 0, num2 = 1;
	
	scanf("%d", &n);
	
	fib(num1, num2, n);
	
	if(flag == 1) printf("%d\n", step+1);
	else if(flag == 0) printf("%d is not in the fibonacci sequence\n", n);
	
	return 0;
}
