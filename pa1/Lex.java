//

import java.util.*;
import java.io.*;

public class Lex
{
	
	public static void main(String[] args) throws IOException
	{
	  if (args.length < 2)
	  {
	    System.err.println("Insufficent line arguements, 2 needed.");
	    System.exit(0);
	  }

	  Scanner inputFile = new Scanner(args[0]); //store input file name
	
	  String [] strArg=null;
	 
	 ArrayList <String> readIn=new ArrayList <String>(); //create an array list
     int length;
     int count;
     int data = 0;
     int i;
     List L = new List();
     
     PrintWriter outputFile = new PrintWriter(args[1]);
    while (inputFile.hasNextLine())
     {
			readIn.add(inputFile.nextLine());
				//read file and add to array list
	  }
			 L.append(0);
		

			for(i = 0; i < strArg.length; i++)
			{
				L.moveBack();
				data=i-1;

				if (L.index() == 0)
		{ //if index is 0 make it the new front of the list
			L.prepend(i);
		}
		else if (L.index()==-1)
		{
			L.prepend(i);
		}
		
		else //if not, then put it behind the indices it is greater than
		{
			L.insertAfter(i);
		}
				while (L.index()>=0) //get current index
				{
					data=L.get();
					//check if it is less than to the List
					if (strArg[i].compareTo(strArg[data])<0)
					{   //move to next element in list
						L.movePrev();
					}

				}
		}
		while(L.index()==0)
		{
			L.movePrev();
			data--;
		}

		PrintWriter output = new PrintWriter(outputFile);  //store output file name
		
		for(i = 0; i < L.length(); i++)		
		{
			outputFile.println(strArg[L.get()]);
			outputFile.flush();
		}

		L.moveNext();

		outputFile.close();	
	}

  }

