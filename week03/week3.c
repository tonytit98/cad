#define SMALL_NUMBER 100
#define HUGE_NUMBER 100000000
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void *memcpy(void *region1, const void* region2, size_t n);
void swap(void* v1, void* v2, int size);
void qsort3way_gen();
int int_comparatorTangDan (const void *a, const void *b);
void QuickSort3way(int A[], int left, int right);

struct {
	char name [40];
	int mark[10];
}student, student_copy;


int main(){
	char myname[]="Tony Tit";
	memcpy (student.name, myname, strlen(myname)+1);
	int arr[6]={1,2,3,4,5,6};
	memcpy (student.mark, arr, 6);
	memcpy (&student_copy, &student, sizeof(student));
	printf("student_copy: %s, %d\n", student_copy.name, student_copy.mark[1]);
	return 0;
}

void *memcpy(void *region1, const void *region2, size_t n){
	const char *first = (const char *) region2;
	const char *last = ((const char *) region2) +n;
	char *result = (char *) region1;
	while (first!=last) *result++=*first++;
	return result;
}

void swap(void *v1, void *v2, int size){
	char buffer[size];
	memcpy(buffer, v1, size);
	memcpy(v1,v2, size);
	memcpy(v2,buffer,size);
}

void qsort3way_gen(
	void *buff, size_t num, size_t size, int (*compare)(void const *, void const *);
);


int int_comparatorTangDan (const void *a, const void *b){
	int m, n;
	m = *((int*)a);
	n = *((int*)b);
	return (m-n);
}
/*
void QuickSort3way(int A[], int left, int right){
	if (right<=left) return;
	int pivot = A[left];
	int i = left, j = right +1;
	int p = left +1, q = right;
	//Phase 1:
	while (1){
		//tim phan tu dau tien tu trai sang >= pivot
		while (A[++i]<pivot){
			 if (i==right) break;
		}
		while (pivot< A[--j]){
			if (i>=j) break;
		}
		swap
	}
}
*/