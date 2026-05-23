#include<stdio.h>
#include"calc.h"
int main(){
	int a,b;
	printf("enter the numbers:\n");
	scanf("%d %d",&a,&b);
	printf("addition:%d\n",add(a,b));
	printf("subraction:%d\n",sub(a,b));
	printf("multiplication:%d\n",mul(a,b));
	printf("divison:%d\n",div(a,b));
	return 0;
	}
