#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#define MAX_PHONE_NUMBER 1000 //số lượng contact khởi tạo tối đa ban đầu trong phone book
#define INIT_SIZE 100
#define INC_SIZE 10     //kích thước tăng thêm mỗi khi tái cấp phát bộ nhớ

typedef struct {
  void * key; // name of contact
  void * value; //phone number
} Entry;

typedef struct {
  Entry entries[MAX_PHONE_NUMBER];
  int total;
} PhoneBook;

typedef struct {
  Entry * entries;
  int max_size, size;
  Entry (*makeNode)(void*, void*);
  int (*compare)(void*, void*);
} SymbolTable;

SymbolTable createSymbolTable(Entry (makeNode *)(void*, void*), int (compare*)(void*, void*));
void dropSymbolTable(SymbolTable* table);
void addEntry(void* key, void* value, SymbolTable* table);
Entry * getEntry(void* key, const SymbolTable table);
Entry makePhoneBook(void* phone, void* name);
int comparePhone(void * key1, void* key2);
SymbolTable phoneBook = createSymbolTable(makePhoneBook,comparePhone);
void printPhoneBook(SymbolTable table);

int main(){
  SymbolTable phoneBook = createSymbolTable(makePhone,comparePhone);
  char number [80], name [80];
  Entry *entry;
  int i, c;
  do{
    system("cls");
    printf("1.Add phone\n2.Search Phone\n3.Print list\n4.Exit\n Your choice: ");
    scanf("%d", &c)
    switch(c){
      case 1:
        fflush(stdin);
        printf("Ten contact: "); gets(name);
        fflush(stdin);
        printf("Phone number: "); scanf ("%s", number);
        addEntry(name, number, &phoneBook);
        break;
      case 2:
        fflush(stdin);
        printf("Ten contact: "); gets(name);
        entry = getEntry(name, phoneBook);
        if (entry==NULL)
          printf("Khong tim thay so dien thoai cua %s trong danh ba\n", name);
        else printf("So dien thoai cua contact %s : %s\n", name, entry->value);
        getch();
        break;
      case 3:
        printPhoneBook(phoneBook);
        getch();
        break;
      case 4:
      dropSymbolTable(&phoneBook);
      break;
    }
  }while(n!=4);
  return 0;
}

SymbolTable createSymbolTable(Entry (makeNode*)(void*, void*),int (compare*)(void*, void*)){
  SymbolTable table;
  Entry *entry = (Entry *)calloc(INIT_SIZE,sizeof(Entry));
  table.entries=entry;
  table.size=0;
  table.max_size=INIT_SIZE;
  table.compare=compare;
  table.makeNode=makeNode;
  return table;
}

Entry makePhoneBook(void* phone, void* name){
  Entry newContact;
  newContact.key = strdup( (char*)name ); //string duplicate
  newContact.value = strdup( (char*)phone); //string duplicate
  return newContact;
}

int comparePhone(void * key1, void* key2){
  return strcmp((char*)key1, (char*)key2);
}

void dropSymbolTable(SymbolTable *table){
  // free the memory allocated for each entry
  for (int i=0; i<table->size; i++){
    free(table->entries[i].key);
  free(table->entries[i].value);
  }
  free(table->entries);
  free(table);
}

Entry * getEntry(void* key, const SymbolTable table){
  int i;
  Entry *entry = table.entries;
  for(i=0;i < table.size;i++)
    if(table.compare(key, entry[i].key)==0)
      return &entry[i];
  return NULL;
}

void addEntry(void* key, void* value, SymbolTable* table){
  if (table->size>=table->max_size){
    Entry *newEntryAddress;
    newEntryAddress=(Entry*)realloc(table->entries, ((table->max_size+INC_SIZE)*sizeof(Entry)));
    if (!newEntryAddress){
      printf("\n Error: Khong the cap phat bo nho!!!, so contact hien tai = %d", table->size);
      return;
    }
    table->entries = newEntryAddress;
    table->max_size += INC_SIZE;
  }
  Entry *entries = table->entries;
  Entry *find = getEntry(key, *table);
  if (find) //Da ton tai key trong table
    *find=table->makeNode(key, value);
  else{
    entries[table->size]=table->makeNode(key, value);
    table->size;
  }
}

void printPhoneBook(SymbolTable table){
  printf("\nSTT\tName\t Phone \n");
  for(int i=0; i < table.size; i++)
    printf("%d\t%-15s\t%15s\n",
      i+1,table.entries[i].name,table.entries[i].phone);
}

