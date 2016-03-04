#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H
#define MAX_LAST_NAME_SIZE 16
// -- optimized LAST_NAME_ENTRY  struct size
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

entry *findName(char lastname[], entry *pHead);
entry *append(char lastName[], entry *e);

#endif
