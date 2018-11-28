
//PA2
//List.h
//List ADT implementation
//----------------------------------------------------------------------------

#ifndef List_h_include
#define List_h_include

typedef  struct ListObj* List;

// List.h is used to support the construction of a List ADT using a sequence of finite integers. 
// It is used to store an array of strings from the provided input files and perform 
// manipulations on them.
// -----------------------------------------------------------------------------


// Constructors-Destructors ---------------------------------------------------
List newList(void);
void freeList(List* pL);
// Access functions -----------------------------------------------------------
int length(List L);
int index(List L);
int front(List L);
int back(List L);
int get(List L);
int equals(List A, List B);
// Manipulation procedures ----------------------------------------------------
void clear(List L);
void moveFront(List L);
void moveBack(List L);
void movePrev(List L);
void moveNext(List L);
void prepend(List L, int data);
void append(List L, int data);
void insertBefore(List L, int data);
void insertAfter(List L, int data);
void deleteFront(List L);
void deleteBack(List L);
void delete(List L);
// Other operations -----------------------------------------------------------
void printList(FILE* out, List L);
List copyList(List L);
#endif
