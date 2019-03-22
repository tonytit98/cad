#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef union{	
	int i;
	long l;
	float f;
	double d;
	void *v;
	char *s;
	char c;
	unsigned char uc;
	short sh;
	unsigned short ush;
	unsigned int ui;
	int iarray[2];
	float farray[2];
	char carray[8];
	unsigned char ucarray[8];
}Jval;

int jval_i(Jval i);
float jval_f(Jval f);
Jval new_javal_i(int i);
Jval new_javal_f(float f);int compare_i(Jval *a, Jval *b);
Jval *new_javal_array_i(size_t n, size_t MAX);
int checkArrAscending_i(Jval *A, int size);
void jval_swap_i(Jval *a,size_t j, size_t k);

int main(){
	Jval a,b;
	a = new_javal_i(5);
	b = new_javal_f(3.14);
	printf("%d\n", jval_i(a));
	printf("%d\n", jval_i(b));
	return 0;
}

int jval_i(Jval j){
	return j.i;	
}

float jval_f(Jval j){
	return j.f;
}

Jval new_javal_i(int i){
	Jval j;
	j.i=i;
	return j;
}

Jval new_javal_f(float f){
	Jval j;
	j.f=f;
	return j;
}

int compare_i(Jval *a, Jval *b){
	if (jval_i(*a)==jval_i(*b)) return 0;
	if (jval_i(*a)<jval_i(*b)) return -1;
	else return 1;
	//return jval_i(*a)-jva;_i(*b);
}

Jval *new_javal_array_i(size_t n, size_t MAX){
	srand(time(0));
	Jval *array = (Jval *) malloc(sizeof(Jval)*n);
	for (int i = 0; i < n; i++){
		array[i]=new_javal_i(rand()%MAX);
	}
	return array;
}

int checkArrAscending_i(Jval *A, int size){
	for (int i=0; i<size-1;  i++)
		if (jval_i(A[i])>jval_i(A[i+1])) return -1;
	return 0;
}

void jval_swap_i(Jval *a,size_t j, size_t k){
	int temp =jval_i (a[j]);
	a[j].i = jval_i(a[k]);
	a[k].i = temp;
}
