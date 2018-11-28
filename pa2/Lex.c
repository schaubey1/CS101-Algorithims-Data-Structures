
//PA2
//Lex.c
// -----------------------------------------------------------------------------
// Lex.c is the main program that is utilized to implement the List ADT in order
// to test the functions of sorting an array, reading strings, and applying InsertionSort
// to store the indices in a sorted order. It saves the manipulated final array to a file after all manipulation is complete.
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "List.h"

#define MAX_LEN 170 //define max length

int stringCompare(char *str1, char *str2){ //https://www.techonthenet.com/c_language/standard_library_functions/string_h/strcmp.php due to strings.h causing issues, I found a different way to use string compare. using strings.h, my index and strcompare wwere no longer working due to multiple function definitions.
  int i = 0;
  while (str1[i] == str2[i] && str1[i] != '\0')
    i++;

  if (str1[i] > str2[i])
    return 1;
  if (str1[i] < str2[i])
    return -1;

  return 0;
}

int main(int argc, char* argv[])
{
    int linecount=0;
    FILE *in, *out; //define file pointers
    char line[MAX_LEN]; //define input pointer

    if (argc !=3) //check amount of arguements
    {
        printf("Lex error: More/Less than 2 strings\n");
        exit(1);
    }
    in=fopen(argv[1], "read");
    out=fopen(argv[2],"write");

    if(in==NULL)
    {
        printf("Lex error: Unable to open file for read");

    }

    else if (out==NULL)
    {
        printf("Lex error: Unable to open file for write");

    }
    while (fgets(line,MAX_LEN, in) !=NULL) //increment for size of array till the end of the file
    {
        linecount++;
    }
    //string array corresponding to line count
    char strARR[linecount][MAX_LEN];
    //rest file cursor to beginning
    fseek(in,0,SEEK_SET);
    //read file into array
    for (int i=0; i<linecount;i++)
    {
      fgets(line,MAX_LEN,in);
      int k=0;
      while (line[k]!='\0')
      {
        strARR[i][k] = line[k];
        k++;
      }
      strARR[i][k] = '\0';
    }
    //create  new list
    List myList=newList();
    append(myList, 0);
    for(int i=1; i<linecount; i++)
    {
        char *temp=strARR[i];
        int x=i;
        moveBack(myList);
        while (index(myList)>=0 && stringCompare(temp, strARR[get(myList)])<0)
        {
            movePrev(myList);
            x--;
        }
        if (x>0) //insert after if element is less than 0
        {
            insertAfter(myList, i);
            moveNext(myList);
        }
        else
        {
            prepend(myList, i);
            moveFront(myList);
        }
    }//output the array
    for(moveFront(myList); index(myList)>=0; moveNext(myList))
    {
        fprintf(out,"%s", strARR[get(myList)]);
    }

    fclose(in);
    fclose(out);

    return(0);
}
