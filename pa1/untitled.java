
import java.util.*;
import java.io.*;

public class Leap{

public static void main(String args[])
{
	boolean leap;
	 for(int year=1800; year<2501; year++)
	 {
	 	if((year%4==0) && (year%100!=0) || (year%400==0))
	 	{
	 		System.out.printf("leap \n");
	 	}

	 	else
	 	{
	 		System.out.printf("%d \n",year);
	 	}
	 }

}
}