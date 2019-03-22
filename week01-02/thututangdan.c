#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int age, mark;
	char name[30];
}Student;

struct{
	char nam
}

int int_compare (void const *x, void const *y);
int int_markcompare(void const *x, void const *y);
void InputStudent(Student sv[], int *size);
void PrintStudent(Student sv[], int size);
int int_agecompare (const void *x, const void *y);
int min(int a, int b);
int binarysearch_gem(void *buf,  int size, int left, int right, void *item, int(*compare)(void*, void*));

int main () {
	int a[]={20,16,100,2,12};
	int n=5;
	printf("Day truoc khi sap xem la: ");
	for (int i=0; i< n; i++){
		printf("%d ", a[i]);
	}
	printf("\n\n");
	qsort(a,n,sizeof(int), int_compare);
	printf("Day sau khi sap xem la:   ");
	for (int i=0; i< n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0; 
	
	/*Student VNK63[10];
	int n;
	InputStudent(VNK63, &n);
	qsort(VNK63,n, sizeof(Student), int_markcompare);
	printf("Danh sach sau ko sap xep thu tu diem tang dan: \n");
	PrintStudent(VNK63,n);
	return 0;
	*/
	/*int (*pf)(int,int);
	pf=min;
	printf("Min cua 4 va 5 la %d\n", pf(5,4));
	return 0;
	*/
}

int int_compare (void const *x, void const *y){
	int m, n;
	m= *((int*)x);
	n= *((int*)y);
	return m-n;
}

int int_markcompare(void const *x, void const *y){
	int m,n;
	m= ((Student *) x) ->mark;
	n= ((Student *) y) ->mark;
	return (m-n);
}

void InputStudent(Student sv[], int *size){
	printf("So luong sinh vien ban muon nhap (<100)? ");
	scanf("%d%*c", size);
	for (int i=0;i<*size; i++){
		printf("***** Nhap thong tin cho sinh vien thu %d ***** \n", i+1);
		printf("Name: ");
		scanf("%s", sv[i].name);
		printf("Age: ");
		scanf("%d", &sv[i].age);
		printf("Mark: ");
		scanf("%d", &sv[i].mark);
	}
}

void PrintStudent(Student sv[], int size){
	printf("Danh sach sinh vien: \n");
	for (int i = 0; i < size; ++i){
		printf("****** Sinh vien thu %d ******\n", i+1);
		printf("Name: %s \n", sv[i].name);
		printf("Age : %d \n", sv[i].age);
		printf("Mark: %d \n", sv[i].mark);
	}
}

int int_agecompare (const void *x, const void *y){
	int m = ((Student *)x) ->age;
	int n= ((Student *) y) ->age;
	return (m-n);
}

int min (int a, int b){
	if (a>b) return b;
	return a;
}

int binarysearch_gem(void *buf,  int size, int left, int right, void *item, int(*compare)(void*, void*)){
	if(right >= left){ 
		int mid = (left+right)/2;
		int res = compare (items, (char *)buf+(size*mid));
		if(res==0) return mid; //tim thay item o vi tri mid
		else if{ (res<0) //phan tu item nho hon phan tu mid -> tim nua trai
			return binarysearch(buf, size, left, mid-1, item, compare);
		}
		else //tim nua phai
			return binarysearch(buf, size, mid+1, right, item, compare);
	}
	return -1; //item khong co trong mang
}

