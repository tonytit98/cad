#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#define INIT_SIZE 10 //số lượng contact khởi tạo tối đa ban đầu trong phone book
#define INC_SIZE 5      //kích thước tăng thêm mỗi khi tái cấp phát bộ nhớ

typedef struct {
  char phone[15];
  char name[80];
} Entry;

typedef struct {
  Entry *entries;
  size_t size;
  size_t max_size;
} PhoneBook;

PhoneBook createPhoneBook(int n_contact);
void dropPhoneBook(PhoneBook *book);
void addPhoneNumber (char * name, char *phone, PhoneBook *book);
char * getPhoneNumber(char name[80], PhoneBook book);
void printPhoneBook(PhoneBook book);

int main(){
  PhoneBook list;
  list=createPhoneBook(INIT_SIZE);
  char name[80],phone[15];
  strcpy(name,"Nguyen Phuong");
  strcpy(phone,"0941238790");
  addPhoneNumber(name,phone,&list);
  strcpy(name, "Lan Tran");
  strcpy(phone, "0904331233");
  addPhoneNumber(name,phone,&list);
  printPhoneBook(list);
  printf("Nhap ten lien lac can tim kiem:");
  scanf("%s",name);
  char *phonet = getPhoneNumber(name, list);
  if(phonet==NULL) printf("Co dau ma tim....");
  else printf("So phone la: %s\n", phone);
}


PhoneBook createPhoneBook(int n_contact){
  PhoneBook newPB;
  Entry *p_list = (Entry)calloc(n_contact,sizeof(Entry));
  newPB.entries = p_list;
  newPB.size = 0;
  newPB.max_size = n_contact;
  return newPB;
}

void dropPhoneBook(PhoneBook *book){
  free(book->entries);
  free(book);
}

void addPhoneNumber (char * name, char *phone, PhoneBook *book){
  size_t n_memb= book->size;
  size_t max_memb= book->max_size;
  Entry * newaddress;
  if (n_memb>=max_memb){
    newaddress= (Entry*)realloc(book->entries,(max_memb+INC_SIZE)*sizeof(Entry));
    if(!newaddress){
      printf("ERROR");
      return;
    }
  book->entries = newaddress;
  book->max_size+= INC_SIZE;
  }
  int i;
  for(i=0; i<book->size;i++){
    if(strcmp(name,book->entries[i].name)==0){
      strcpy(book->entries[i].phone,phone);
      return;
    }
  strcpy(book->entries[book->size].name,name);
  strcpy(book->entries[book->size].phone,phone);
  book->size++;
  }
}

char * getPhoneNumber(char name[80], PhoneBook book){
  PhoneBook *entry = book.entries;
  for(int i=0; i < book.size; i++)
    if(strcmp(entry[i].name,name)==0)
      return entry[i].phone;
  return NULL; //Không tìm thấy contact trong danh bạ điện thoại
}

void printPhoneBook(PhoneBook book){
  printf("\nSTT\tName\t Phone \n");
  for(int i=0; i<book.size;i++)
    printf("%d\t%-15s\t%15s\n",i+1,book.entries[i].name,book.entries[i].phone);
}
