#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H
#define MAX_LAST_NAME_SIZE 16
#define TABLE_SIZE 42737

// -- optimized hashfunction used
typedef struct __PHONE_BOOK_ENTRY_NO_LASTNAME {
    char lastName[MAX_LAST_NAME_SIZE];
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
} entry_detail;

//optimize struct
typedef struct __LAST_NAME_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    struct __PHONE_BOOK_ENTRY_NO_LASTNAME *detail;
    struct __LAST_NAME_ENTRY *pNext;
} entry;


int TransHashKey(char *lastName,int size);
entry *findName(char lastname[], entry *pHead);
entry *append(char lastName[], entry *e);
void initialize();

#endif
