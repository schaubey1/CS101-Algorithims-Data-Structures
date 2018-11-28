
// Assignment Name: Programming Assignment 1 -- List ADT
// File: List.java 
// -----------------------------------------------------------------------------
// List.java is used to construct a List ADT using a sequence of finite integers. 
// It is used to store an array of strings from the provided input files and perform 
// manipulations on them.
// -----------------------------------------------------------------------------

public class List {

private int length;
private int index;
private Node back;
private Node front;
private Node cursor;

private class Node {
   Node prevNode;
   Node nextNode;
   int data;

   Node (int data)
   {
      prevNode=nextNode=null;

   }

   public String toString(){

         return String.valueOf(this.data);
      }


}

/*
The underlying data structure for the List ADT will be a doubly linked list. The List class should therefore contain
 a private inner Node class which itself contains fields for an int (the data), and two Node references (the previous
and next Nodes, respectively) which may be null. The Node class should also define an appropriate constructor
as well as a toString() method. 
*/ 

//contain private inner Node class, containing field for an int (data) and 2 nodes (pre and next)


      

      /*
      The List class should contain three private fields of type Node referring to the
front, back, and cursor elements, respectively. The List class should also contain private int fields storing the
length of the List and the index of the cursor element. 

in List() = When the cursor is undefined, an appropriate value the
index field is -1, since that is what is returned by index() in such a case.
*/
   

   List()
    {
      front = back = cursor = null;
      index = -1;
      length = 0;
   }

// Returns true if this List and L are the same integer
 // sequence. The cursor is ignored in both lists.
   boolean equals(List L)
    { if(L.length !=this.length)
      {
         return false;
      }

      Node N, M;
      List X;
      boolean eq;

      if (L instanceof List) {
         X = (List)L;
         M = this.front;
         N = X.front;
         eq = (this.length==X.length);

         while( eq!=false && N!=null ){
            eq = M.equals(N);
            M = M.nextNode;
            N = N.nextNode;
         }
 

      }
     return true;
   }
   // Access functions

   // Returns the number of elements in this List.
   int length()
   {
      return length;
   }

   // If cursor is defined, returns the index of the cursor element,
   // otherwise returns -1.
   int index() 
   {
    
         return index;
      
   }

   // Returns front element. Pre: length()>0
   int front() {
      if (length() > 0) {
         return front.data;
      }
      else
      {
         throw new RuntimeException ("List Error");
      }

   }

   // Returns back element. Pre: length()>0

   int back() {
      if (length() > 0) 
      {
         return back.data;
      }
      else
      {
         throw new RuntimeException ("List Error: back() called on an empty List");
      }
   }


   // Returns cursor element. Pre: length()>0, index()>=0

   int get()
   {
      if (length()>0 && index() >= 0){
         return cursor.data;
   }
      else{
         throw new RuntimeException(
            "List Error: get() called on empty List");
      }
      
   }

// Manipulation procedures

  

   // Resets this List to its original empty state.
   void clear() 
   {
      front = back = cursor = null;
      length = 0;
      index = -1;
   } 

   // If List is non-empty, places the cursor under the front element,
   // otherwise does nothing.
   void moveFront() 
   {
      if (this.length() > 0) 
      {
         cursor = front;
         index = 0;
      }
   }

   // If List is non-empty, places the cursor under the back element,
   // otherwise does nothing.
   void moveBack() {
      if (this.length() > 0) 
      {
         cursor = back;
         index = length()-1;
      }
   }

   // If cursor is defined and not at front, moves cursor one step toward
   // front of this List, if cursor is defined and at front, cursor becomes
   // undefined, if cursor is undefined does nothing.
   void movePrev() 
   {
      if (cursor != null)
       {
         cursor = cursor.prevNode;
         index--;
       } 
   } 

   // If cursor is defined and not at back, moves cursor one step toward
   // back of this List, if cursor is defined and at back, cursor becomes
   // undefined, if cursor is undefined does nothing.
   void moveNext() {

      if (cursor !=null) 
      {
         cursor = cursor.nextNode;
         index++;
      }

      if (cursor==null)
      {
         index = -1;
      }
   }

   // Insert new element into this List. If List is non-empty,
   // insertion takes place before front element.
void prepend(int data)
{  
   Node nNode=new Node(data);
   nNode.nextNode=front;

   if (front != null) 
   { 
      front.prevNode=nNode;
   }

   front=nNode;
   length++;

   if (cursor != null)
   {
      index++;
   }

   if(length==1)
   {
      back=nNode;
   }
   
}


   // Insert new element into this List. If List is non-empty,
   // insertion takes place after back element.
void append(int data) 
{  Node nNode=new Node(data);
   nNode.prevNode=back;

   if (length() > 0) 
   {
      back.nextNode = nNode;

   }
   back=nNode;
   length++;

   if(length ==1 )
   {
      front=nNode;
   }
}


   // Insert new element before cursor.
   // Pre: length()>0, index()>=0
void insertBefore(int data) {
   if (length() <= 0) {
      throw new RuntimeException(
         "List Error: insertBefore length called on an empty List");
      }
   else{
      Node nNode= new Node(data);
      nNode.prevNode = cursor.prevNode;
      nNode.nextNode=cursor;
      index++;
      length++;

      if(front==cursor)
      {
         front=nNode;

      }

      else 
      {
         cursor.prevNode.nextNode=nNode;
      }
   }
}

   // Inserts new element after cursor.
   // Pre: length()>0, index()>=0

void insertAfter(int data) {
   if (length() <= 0) {
      throw new RuntimeException(
         "List Error: insertAfter length called on empty List");
      }
   else if (index() < 0){
      throw new RuntimeException(
         "List Error: insertAfter index called on empty List");
   }

   Node nNode=new Node(data);
   nNode.nextNode =cursor.nextNode;
   nNode.prevNode=cursor;
   length++;


   if(cursor !=back)
   {
      cursor.nextNode.prevNode=nNode;
   }

   if(cursor==back)
   {
      back=nNode;
   }

   cursor.nextNode=nNode;
}
   // Deletes the front element. Pre: length()>0
   void deleteFront() {
   if (length()<=0) {
      throw new RuntimeException(
         "List Error: deleteFront length called on empty List");
   }
   else 
   {
      if (cursor == front)

      {
         cursor = null;
         index = -1;
      }

         front = front.nextNode;
        

         if (front !=null)
         {
             front.prevNode = null;
         }

         length--;
        if(cursor !=null)
        {
         index--;
        }

      }
   }

   // Deletes the back element. Pre: length()>0
   void deleteBack() 
   {

       if (length()<=0) 
   {

      throw new RuntimeException("List Error: deleteBack length called on empty List");
   }

      if (cursor==back)
      {
         cursor=null;
         index=-1;
         back=back.prevNode;
      }
      

      if (back !=null)
      {
         back.nextNode=null;
      }
      length--;
}
   

   // Deletes cursor element, making cursor undefined.
   // Pre: length()>0, index()>=0
   // Other methods
  void delete(){
   if (length()<=0) {
      throw new RuntimeException(
         "List Error: delete length called on empty List");
   }
   else if (index()<0) {
      throw new RuntimeException(
         "List Error: delete index called on empty List");
   } 
   else {
      if (cursor == front){
         deleteFront();
      }
      else if (cursor == back){
         deleteBack();
      }
      else if (this.length()>1)
       {
         cursor.prevNode.nextNode=cursor.nextNode;
         cursor.nextNode.prevNode=cursor.prevNode;
         index=-1;
         cursor=null;
         length--;
      }
   }
}


// Overrides Object's toString method. Returns a String
//  representation of this List consisting of a space
//  separated sequence of integers, with front on left.
public String toString(){
      StringBuffer sb = new StringBuffer();
      Node N = front;
      while(N!=null){
         sb.append(" ");
         sb.append(N.toString());
         N = N.nextNode;
      }
      return new String(sb);
   }
   


// Returns a new List representing the same integer sequence as this
 // List. The cursor in the new list is undefined, regardless of the
 // state of the cursor in this List. This List is unchanged.
List copy() {

      List copy = new List();
      Node N = front;

      while( N!=null ){
         copy.append(N.data);
         N = N.nextNode;
      }
      return copy;
      
   }


//not working
// List concat(List L)
// {
//     List nlist2=L.copy();

//    List nList=this.copy();

//    nList.back.nextNode=nList2.front;
//    nList2.front.prevNode=nList.back;
   
//    return nList;
// }

}
