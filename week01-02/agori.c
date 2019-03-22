#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 500
#define SMALL_NUMBER 20
#define HUGE_NUMBER 10000000

void swap(int *a, int *b);
void insertionSort(int a[], int size);
void selectionSort(int a[], int size);
void merge(int A[], int first, int mid, int last);
void mergeSort(int A[], int first, int last);
void quickSort(int A[], int first, int last);
int Partition(int A[], int first, int last);
void QuickSort3way_Left(int A[], int left, int right);
int *createArray (int size);
int *dumpArray(int *p, int size);
int checkAscending(int *a, int left, int right);

int main(){	
	int *a1, *a2;
	a1 = createArray(SMALL_NUMBER);
	a2 = dumpArray(a1, SMALL_NUMBER);

	quickSort(a1, 0, SMALL_NUMBER-1);
	int kq =checkAscending(a1, 0, SMALL_NUMBER-1);
	if (kq==0){
		printf("2-way quickSort chay sai\n");
	}
	else printf("2-way quickSort ok\n");

	QuickSort3way_Left(a2, 0, SMALL_NUMBER-1);
	kq =checkAscending(a2, 0, SMALL_NUMBER-1);
	if (kq==0){
		printf("3-way quickSort chay sai\n");
	}
	else printf("3-way quickSort ok\n");
	
	free (a1);free (a2);
	a1=createArray(HUGE_NUMBER);
	a2=dumpArray(a1,HUGE_NUMBER);

	time_t start
}

void swap(int *a, int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void insertionSort(int a[], int size){
	int k,j; 
	for (int k = 0; k < size; k++)
	{
		int temp= a[k];
		int pos =k;
		while (pos>0 && a[pos-1]>temp)
		{
			a[pos]=a[pos-1];
			pos--;
		}
		a[pos]=temp;
	}
}

void selectionSort(int a[], int size){
	int i, j, index_min;
	for(i=0; i<size-1; i++)
	{
		index_min=i;
		for (int j = i+1; j < size; j++)
		{
		if (a[j]< a[index_min]) index_min=j;
		//dua phan tu a[index_min] vao vi tri thu i
		}
		swap(&a[i], &a[index_min]);
	}
}


void merge(int A[], int first, int mid, int last){
	int tempA[MAX_SIZE];	int first1=first;
	int last1=mid;			int first2=mid + 1;
	int last2=last;			int index=first1;
	for(;(first1<=last1)&&(first2<=last2);index++){
		if (A[first1]<A[first2]){
			tempA[index]=A[first1];
			first1++;
		}
		else{
			tempA[index]=A[first2];
			first2++;
		}
	}
	for (;first1<=last1; first1++,index++){
		tempA[index]=A[first1];
	}
	for (;first2<=last2; first2++,index++){
		tempA[index]=A[first2];
	}
	for (index=first; index<=last1;index++){
		A[index]=tempA[index];
	}
}

void mergeSort(int A[], int first, int last){
	if (first<last){
		int mid = (first+last)/2;
		mergeSort(A, first, mid);
		mergeSort(A, mid+1, last);
		merge(A, first, mid, last);
	}
}


void quickSort(int A[], int first, int last){
	int Pivot;
	if ( first< last){
		Pivot = Partition (A, first, last);
		quickSort(A, first, Pivot-1);
		quickSort(A, Pivot + 1, last);
	}
}

int Partition(int A[], int first, int last){
	int big_index = first;
	int small_index = last +1;
	int Pivot = A[first];
	while (big_index < small_index){
		big_index=big_index + 1;
		while (big_index <= last && A[big_index] <= Pivot)
			big_index=big_index+1;
		small_index -=1;
		while (small_index >= first && A[small_index]> Pivot)
			small_index--;
		swap(&A[big_index], &A[small_index]);
	}
	swap(&A[big_index], &A[small_index]);
	swap(&A[small_index], &A[first]);
	return small_index;
}

void QuickSort3way_Left(int A[], int left, int right){
	if(right<=left) return;
	int pivot = A[left];
	int i = left, j= right+1;
	int p = left+1, q=right;
	//Phase 1:
	while (1){
		//tim phan tu dau tien tu trai sang >= pivot:
		while (A[++i]<pivot)
			if (i==right) break;
		//tim phan tu dau tien tu phai sang <=pivot:
		while (pivot<A[--j]);
		if (i>=j) break;
		swap (&A[i], &A[j]);
		if (A[i]==pivot){
			swap (&A[p], &A[i]);
			p++;
		}
		if(A[j]==pivot){
			swap(&A[q],&A[j]);
			q--;
		}
	}
	//Phase 2:
	/* 2.1 Hoan doi cac pha tu ben trai day A [left]... A[p-1]
	co gia tri bang phan tu chot voi cac phan tu bat dau tu A[j] tro ve dau day..*/
	for (int k= left; k < p; k++,j--){
		swap (&A[k],&A[j]);	
	} 
	for (int k=q+1; k<=right; k++, i++){
		swap (&A[k], &A[i]);	
	} 

	//Goi de quy day con trai:
	QuickSort3way_Left(A, left, j);
	//Goi de quy day con phai:
	QuickSort3way_Left(A, i, right);
}

int *createArray (int size){
	int i, *p;
	/*Cap phat bo nho cho mang so nguyen gom size so */
	p =(int *) malloc (size *sizeof(int));
	if (p==NULL){
		printf("Cap phat bo nho khong thanh cong!\n");
		return NULL;
	}
	srand (time(NULL));
	for (i=0; i<size;i++){
		p[i]=1 + rand()%9;
	}
	return p;
}

int *dumpArray (int *p, int size){
	int i, *q;
	q=(int *)malloc(size *sizeof(int));
	if(q==NULL){
		printf("Cap phat bo nho khong thanh cong!\n");
		return NULL;
	}
	for (i = 0; i < size; i++){
		q[i]=p[i];
	}
	return q;
}

int checkAscending(int *a, int left, int right){
	for (int i=left; i< right; i++){
		if (a[i]>a[i+1])
			return 0;
		return 1;
	}
}
