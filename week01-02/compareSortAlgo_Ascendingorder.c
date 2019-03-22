#define SMALL_NUMBER 100
#define HUGE_NUMBER 100000000
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
	int temp =*a;
	*a=*b;
	*b=temp;
}


//tao mang du lieu kieu int, luu tru bo nho dong
int * createArray(int size)
{
    int i, *p;
    /* Cap phát bo nho cho mang so nguyên gom size so */
    p = (int *)malloc(size * sizeof(int));
    if (p == NULL)
    {
        printf("Cap phát bo nho không thành công!\n");
        return NULL;
    }
    srand(time(NULL));
    for (i=0;i<size;i++) p[i] = 1 + rand()%9;
    return p;
}


//Hàm cho phép sao chép mot mang so nguyên da có
int *dumpArray(int *p, int size)
{
    int i, *q;
	q = (int *)malloc(size * sizeof(int));
    if (q == NULL)
    {
        printf("Cap phát bo nho không thành công!\n");
        return NULL;
    }
    for (i=0;i<size;i++) q[i] = p[i];
    return q;
}


void printArr(int a[],int l, int r)
{
	for (int k=l;k<=r;k++)
	  printf("%d  ",a[k]);
	printf("\n");  
}

//QuickSort: Chon phan tu dau lam phan tu chot:
int Partition(int A[], int left, int right)	
{
	 int i = left; int j = right+1; 
     int pivot = A[left];
	 while (1) 
	 {
	 	//Tim tu trai sang phan tu dau tien >pivot:
	 	while (A[++i] < pivot)
	 	   if (i==right) break;
	 	//Tim tu phai sang trai phan tu dau tien < pivot
		while (pivot < A[--j]);
		 //  if (j==left) break; //khong can thiet vi phan tu chot a[left] acts as sentinel
		if (i >= j) break;
  	    swap(&A[i], &A[j]);
	}
    swap(&A[j], &A[left]);
    return j;
}



void QuickSort2way(int A[], int Left, int Right)
{
	int index_Pivot;
	if  (Left < Right ) 
	{
		index_Pivot =Partition(A,Left,Right);
		QuickSort2way(A,Left, index_Pivot-1);
        QuickSort2way(A, index_Pivot +1, Right);
 	}
}



/*Bentley-Mcllroy 3-way partitioning quick sort 
Phan tu chot pivot la phan tu dau day */
void QuickSort3way_Left(int A[], int left, int right) {
	if (right <= left) return;
	int pivot = A[left];
	int i = left, j = right+1;
	int p = left+1, q = right;
	//Phase 1:
	while (1)	{
		//tim phan tu dau tien tu trai sang >=pivot:
		while (A[++i] < pivot) 
		    if (i==right) break;
		//tim phan tu dau tien tu phai sang <=pivot:
		while (pivot < A[--j]); 
		if (i >= j) break;
		swap(&A[i],&A[j]);
		if (A[i]==pivot) {
			swap(&A[p],&A[i]);
			p++;
		}
		if (A[j]==pivot){
			swap(&A[q],&A[j]);
			q--;
		} 
	}
     //Phase 2:
   /* 2.1 Hoan doi cac phan tu ben trai day A[left]..A[p-1] 
	co gia tri bang phan tu chot voi cac phan tu bat dau tu A[j] tro ve dau day..*/
	for (int k = left; k < p; k++,j--) swap(&A[k],&A[j]);
    /*2.2 Hoan doi cac phan tu ben phai day A[q+1]...A[right]
	co gia tri bang phan tu chot voi cac phan tu bat dau tu A[i] tro ve cuoi day..*/
 	for (int k = q+1; k <=right; k++,i++) swap(&A[k],&A[i]);
	
	//Goi de quy day con trai:
	QuickSort3way_Left(A, left, j);
	//Goi de quy day con phai:
	QuickSort3way_Left(A, i, right);
}

/*Bentley-Mcllroy 3-way partitioning quick sort 
Phan tu chot pivot la phan tu cuoi day */
void QuickSort3way_Right(int A[], int left, int right) {
/* This function partitions a[] in three parts 
   a) a[l..i] contains all elements smaller than pivot 
   b) a[i+1..j-1] contains all occurrences of pivot 
   c) a[j..r] contains all elements greater than pivot */
    if (right <= left) return; 
    int pivot = A[right]; 
    int i = left-1; int j = right; 
    int p = left-1, q = right; 

    //Phase 1: 
    while (1) 
    { 
        // From left, find the first element greater than 
        // or equal to v. This loop will definitely terminate 
        // as v is last element: 
        while (A[++i] < A[right]); 
  
        // From right, find the first element smaller than or 
        // equal to v: 
        while (A[right] < A[--j]) 
            if (j == left) break; 
  
        // If i and j cross, then we are done:
        if (i >= j) break; 
  
        // Swap, so that smaller goes on left greater goes on right 
        swap(&A[i], &A[j]); 
  
        // Move all same left occurrence of pivot to beginning of 
        // array and keep count using p: 
        if (A[i] == A[right]) 
        { 
            p++; 
            swap(&A[p], &A[i]); 
        } 
        
  
        // Move all same right occurrence of pivot to end of array 
        // and keep count using q: 
        if (A[j] == A[right]) 
        { 
            q--; 
            swap(&A[j], &A[q]); 
        } 
    } 
  
     //Phase 2:
    // Move all left same occurrences from beginning 
    // to adjacent to arr[i] 
    j = i-1; 
    for (int k = left; k <= p; k++) {
        swap(&A[k], &A[j]); 
        j--;
	}
  
    // Move all right same occurrences from end 
    // to adjacent to arr[i] 
    for (int k = right; k >= q; k--){
        swap(&A[i], &A[k]); 
        i++;
	} 
    //Goi de quy nua trai va nua phai:
	QuickSort3way_Right(A,left,j);    
    QuickSort3way_Right(A,i,right);
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
    int tempA[HUGE_NUMBER];    int first1=first;
    int last1=mid;          int first2=mid + 1;
    int last2=last;         int index=first1;
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



/*Neu mang a duoc sap xep theo thu tu tang dan, ham tra ve gia tri 1;
Neu khong ham tra ve gia tri 0*/ 
int checkAscending(int *a, int l, int r){
	for (int i=l;i<r;i++)
	 if (a[i]>a[i+1]) return 0;
	 return 1;
}

int main() {
	int *a1, *a2 , *a3;
    a1 = createArray(SMALL_NUMBER);
	a2 = dumpArray(a1, SMALL_NUMBER);
	a3 = dumpArray(a1, SMALL_NUMBER);
	
	QuickSort2way(a1, 0, SMALL_NUMBER-1);
    int kq=checkAscending(a1,0, SMALL_NUMBER-1);
    if (kq==0) printf("2-way QuickSort chay sai \n");
    else printf("2-way QuickSort OK \n");

	QuickSort3way_Left(a2, 0, SMALL_NUMBER-1);
    kq=checkAscending(a2,0, SMALL_NUMBER-1);
    if (kq==0) printf("3-way QuickSort chay sai \n");
    else printf("3-way QuickSort OK \n");


	QuickSort3way_Right(a3, 0, SMALL_NUMBER-1);
    kq=checkAscending(a3,0, SMALL_NUMBER-1);
    if (kq==0) printf("3-way QuickSort_Right chay sai \n");
    else printf("3-way QuickSort_Right OK \n");
	    
	free(a1);free(a2);free(a3);

    a1 = createArray(HUGE_NUMBER);
	a2 = dumpArray(a1, HUGE_NUMBER);
	a3 = dumpArray(a1, HUGE_NUMBER);
	// compare the time to execute sorting:
	time_t start, end1, end2,end3;
	start = clock();
	QuickSort2way(a1, 0, HUGE_NUMBER-1);
	end1 = clock();
	QuickSort3way_Left(a2, 0, HUGE_NUMBER-1);
    end2 = clock();
	QuickSort3way_Right(a3, 0, HUGE_NUMBER-1);
    end3 = clock();
    printf("Mang gom %d phan tu: \n",HUGE_NUMBER);
    printf("Running time of 2-way Quicksort: %f seconds \n",((double) (end1 - start)) / CLOCKS_PER_SEC);
    printf("Running time of 3-way_L Quicksort: %f seconds \n",((double) (end2 - end1)) / CLOCKS_PER_SEC);
    printf("Running time of 3-way_R Quicksort: %f seconds \n",((double) (end3 - end2)) / CLOCKS_PER_SEC);
	free(a1);free(a2);free(a3);
	return 0;
}