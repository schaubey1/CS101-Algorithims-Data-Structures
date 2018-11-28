
//PA2
//List.c
// -----------------------------------------------------------------------------
// List.c is used to construct a List ADT using a sequence of finite integers. 
// It is used to store an array of strings from the provided input files and perform 
// manipulations on them.
// -----------------------------------------------------------------------------
//List ADT implementation
//----------------------------------------------------------------------------

#include<stdio.h>
#include "List.h"
#include <stdlib.h>

typedef struct NodeObject{
    int data;
    struct NodeObject* prev;
    struct NodeObject* next;

}
NodeObject;
//private node typedef from java file
typedef  NodeObject* Node;
//private list object typdef in java file
typedef  struct ListObj{
    Node front;
    Node back;
    Node cursor;
    int length;
    int index;
} ListObj;
Node newNode(int data, Node prev, Node next)
{

    Node N = malloc(sizeof(NodeObject));
    N -> data= data;
    N -> prev= prev;
    N -> next=next;
    return(N);
}

// Constructors-Destructors ---------------------------------------------------
List newList(void){ //return a new list object
    List L;
    L = malloc(sizeof(ListObj));
    L->back = L->front = L->cursor= NULL;
    L->index = -1;
    L->length = 0;
    return (L);
}

// Access functions
int length(List L)// Returns the number of elements in this List.
{
    if (L==NULL)
    {
        printf ("List error, length cannot execute on a NULL List");
        exit(1);

    }
    return (L->length);
}
int isEmpty(List L){
    if( L==NULL ){
        printf("List Error: isEmpty() cannot be on NULL List reference");
        exit(1);
    }
    return(L->length==0);
}
int index(List L) // If cursor is defined, returns the index of the cursor element,
// otherwise returns -1.
{   if (L==NULL){
    printf ("List error, index() cannot execute on a NULL List");

}
    return(L->index);

}
int front(List L) // Returns front element. Pre: length()>0
{
    if (L == NULL)
    {
        printf("List error, front() cannot execute on a NULL List");
        exit(1);
    }

    return L->front->data;
}
int back(List L) // Returns back element. Pre: length()>0
{
    if (L == NULL)
    {
        printf("List error, back() cannot execute on a NULL List");
        exit(1);    }

    if (L->length <=0) //check if length is less than 0
    {
        printf("List error, back() cannot execute on a NULL List");
        exit(1);
    }

    return L->back->data;

}
int get(List L) // Returns cursor element. Pre: length()>0, index()>=0
{
    if (L == NULL)
    {
        printf("List error, get() cannot execute on a NULL List");
        exit(1);    }

    if (L->length <=0)
    {
        printf("List error, get() cannot execute on a NULL List");
        exit(1);
    }
    return L->cursor->data;

}
int equals(List A,List B) // Returns true if and only if this List and L are the same
// integer sequence. The states of the cursors in the two Lists
// are not used in determining equality.
{   int eq=0;
    Node First =NULL;
    Node Second=  NULL;
    if (A== NULL && B==NULL)
    {
        printf("List error, equals() cannot execute on a NULL List");
        exit(1);

    }
    eq= (A->length== B->length);
    First= A-> front; //iterators for both lists
    Second= B-> front;
    while(First && Second !=NULL) //checks if elements are equal
    {
        eq=(First->data==Second->data);
        First= First->next;
        Second=Second->next;

    }
    return eq;

}
// Manipulation procedures
void clear(List L) // Resets this List to its original empty state.
{
    if (L == NULL)
    {
        printf("List error, clear() cannot execute on a NULL List");
        exit(1);

    }
    else if(L!=NULL)
    {
        L->front=L->back=L->cursor=NULL;
        L->length=0;
        L->index=-1; //reset all variables to 0
    }
    while(length(L)>0)
    {
    	deleteFront(L);
    }
}
void moveFront(List L) // If List is non-empty, places the cursor under the front element,
// otherwise does nothing.
{
    if (L == NULL)
    {
        printf("List error, clear() cannot execute on a NULL List");
        exit(1);

    }
    if (!(isEmpty(L)))
    {
        L->cursor=L->front;
        L->index=0;
    }
}
void moveBack(List L) // If List is non-empty, places the cursor under the back element,
// otherwise does nothing.
{
    if (L == NULL)
    {
        printf("List error, moveBack() cannot execute on a NULL List");
        exit(1);

    }
    if (!(isEmpty(L)))
    {
        L->cursor=L->back;
        L->index=L->length-1;
    }
}
void movePrev(List L) // If cursor is defined and not at front, moves cursor one step toward
// front of this List, if cursor is defined and at front, cursor becomes
// undefined, if cursor is undefined does nothing.
{
    if (L == NULL)
    {
        printf("List error, movePrev() cannot execute on a NULL List");
        exit(1);
    }//move cursor back one node
    if(L->cursor==L->front)
    { L-> cursor=NULL;
        L->index=-1;
    }
    else if (L->cursor !=NULL)
    {
        L->cursor=L->cursor->prev;
        L->index--;
    }

}
void moveNext(List L) // If cursor is defined and not at back, moves cursor one step toward
// back of this List, if cursor is defined and at back, cursor becomes
// undefined, if cursor is undefined does nothing.
{  if (L == NULL)
{
    printf("List error, Movenext() cannot execute on a NULL List");
    exit(1);
}
    if (L->cursor== L->back)
    { L->cursor=NULL;
        L->index= -1;
    }
    if (L->cursor!= NULL)
    {
      L->cursor=L->cursor->next;
      L->index++;
    }
}
void prepend(List L, int data) // Insert new element into this List. If List is non-empty,
// insertion takes place before front element.
{
    if (L == NULL)
    {
        printf("List error, prepend() cannot execute on a NULL List");
        exit(1);
    }
    Node N = newNode(data, NULL, L->front);

    if(!isEmpty(L)) //point front and back to new node
    {
        L->front->prev=N;
        L->front=N;
        if (index(L)!=-1)
        {
            L ->index++;
        }

    }
    else if (length(L) == 0) //make N the front
    {
        L->back= L->front=N;
    }
     N=NULL;
    L->length++;

}

void append(List L, int data) // Insert new element into this List. If List is non-empty,
// insertion takes place after back element.
{
  if (L == NULL)
  {
      printf("List error, prepend() cannot execute on a NULL List");
      exit(1);
  }
  Node N = newNode(data, L->back, NULL);

  if(!isEmpty(L))
  {
      L->back->next=N;
      L->back=N;
   }
   else if (length(L) == 0)
   {
       L->front= L->back=N;
   }

   N=NULL;
   L->length++;
}

void insertBefore(List L, int data) // Insert new element before cursor.
// Pre: length()>0, index()>=0
{
    if(L==NULL)
    {
        printf("List error, insertBefore() cannot execute on a NULL List");
        exit(1);

    }
    if (length(L)==0 || L->cursor == L->front)
    {
        prepend(L,data);
        return;

    }
    else
    {
        Node old= newNode(data, L->cursor->prev, L->cursor);
        L->cursor->prev->next=old;
        L->cursor->prev=old;
    }
    L->length++;
    L->index++;

}
void insertAfter(List L, int data) // Inserts new element after cursor.
// Pre: length()>0, index()>=0
{
    if(L==NULL)
    {
        printf("List error, insertAfter() cannot execute on a NULL List");
        exit(1);

    }
    L->length++;
    Node post=newNode(data, L->cursor, L->cursor->next);
    if (L->cursor !=L->back)
    {
        L->cursor->next->prev=post;
    }
    L->cursor->next=post;
    if(L->cursor==L->back)
    {
        L->back=post;
    }
}
void deleteFront(List L) // Deletes the front element. Pre: length()>0
{
    if(L==NULL)
    {
        printf("List error, deletefront() cannot execute on a NULL List");
        exit(1);

    }
    if (L->length<=1)
    {
        L->front=L->back=NULL; //delete front

    }
    else
    {
        L->front=L->front->next;
        L->front->prev=NULL;
    }
    L->length--;
}
void deleteBack(List L) // Deletes the back element. Pre: length()>0
{   if(L==NULL)
{
    printf("List error, deleteBack() cannot execute on a NULL List");
    exit(1);

}    if(L->length>1)
{
    L->back=L->back->prev; //switch back with previous
    L->back->next=NULL;
}
else if (L->length==1)
{
    L->front=L->back=NULL;
}
    L->length--;
}

void delete(List L)
{
    if(L==NULL)
    {
        printf("List error, deleteBack() cannot execute on a NULL List");
        exit(1);
    }
    if (L->length>1)
    {
        L->cursor=L->cursor->next;

    }
    else if (L->length<1)
    {
        L->front=L->back=NULL; //delete back element
    }
    L->length--;

}
List copyList(List L){
    if(L==NULL)
    {
        printf("List error, copylist() cannot execute on a NULL List");
        exit(1);
    }
    List newlist= newList(); //create a list for copy destination
    if(length(L)==0)
        return(newlist);
    Node N=NULL;
    N=L->front;

    while(N != NULL) {
        append(newlist, N->data);
        N = N->next;
    }
    return(newlist);
}
void freeList(List* pL)
    {
        if(pL!=NULL && *pL!=NULL) {
            while( !isEmpty(*pL) ) {
                deleteFront(*pL);

            }
            free(*pL);
            *pL = NULL;
        }
}
void printList (FILE* out, List L)
{
    Node N=NULL;
    if(L==NULL)
    {
        printf("List error, copylist() cannot execute on a NULL List");
        exit(1);
    }
    if(out==NULL)
    {
        printf("List error, copylist() cannot execute on a NULL List");
        exit(1);
    }
    N=L->front;


    while(N != NULL)
    {
        fprintf(out, "%d", N->data);
        if (N->next != NULL) {
          fprintf(out, " ");
        }
        N= N->next;
    }
    // printf("\n");
}
