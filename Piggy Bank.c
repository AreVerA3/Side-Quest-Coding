#include <stdio.h>
int main () 
{
    //declare for variables
    int c10, c20, c50, number, day=0, i;
	int sc10=0, sc20=0, sc50=0;
	int Achievement=0;
    double total, totalsaving=0.00;
    char answer;

	
	// User enter their saving goals 
    printf("Set your saving goals :RM", number);
	scanf("%d", &number);

do {    
    // User enter their saving days
    printf("Set your saving days : ", day);
    scanf("%day", &day);
	
	

{	// Body for Saving Details

      for (i=1 ; i<=day; i++)

	{ //for loop body
	    {
	      printf("\nEnter the details of your saving for Day %d:\n",i);
        }
 
	      printf("\tNo of coin (10 sen) :");
	      scanf("%d", &c10);
	
          printf("\tNo of coin (20 sen) :");
	      scanf("%d", &c20);
	
	      printf("\tNo of coin (50 sen) :");
	      scanf("%d", &c50);
    
	      total = ((c10 * 0.10) + (c20 * 0.20 ) + (c50 * 0.50));
          printf("\tTotal of your money :RM%.2f\n",total);
	
          Achievement += (double)total/number* 100 ;
	      printf("\tAchievement : %d% %\n", Achievement);
   

	     if (total!=0 && (Achievement>0 && Achievement<50) )
	  
	       {
	  	     printf("\tMessage : Good!!\n");
	       }
	  
	        else if (total!=0 && (Achievement>=50 && Achievement<100) )
	       {
	  	     printf("\tMessage : Very Good!!\n");
	       }
	  
	        else if (total !=0 && Achievement>=100)
	       {
	  	     printf("\tMessage : Excellent!!\n");
	       }
	 
	        else if((total==0) || (Achievement==0))
	       {
	  	     printf("\tMessage : Oh! Ow..\n");
	       }
	  
	      // To calculate the total of saving from day1
          totalsaving +=total;
          
          // To calculate the total of 10sen,20sen and 50sen that entered by user
	      sc10 +=c10;
	      sc20 +=c20;
	      sc50 +=c50;
        
	} //for loop body
  
  
    printf ("\n=====================================\n");
    printf("    Saving Records Summary Report\n");
    printf ("=====================================\n");
    printf("\nNumber of Saving Days   : %d days. ",day);
    printf("\nSaving Goal\t\t: RM%.2f\n",(double)number); 
    printf("Total Number of Coins\n");
    printf("\t\t10 sen  : %d\n" ,sc10);
    printf("\t\t20 sen  : %d\n" ,sc20);
    printf("\t\t50 sen  : %d\n" ,sc50);
    
	printf("Total Amount Saved\t:RM%.2f\n",totalsaving);
		 
		 if (totalsaving >=number)   
	      {
		    printf("Status of Goal Achievement : ACHIEVED!\n");
		  }   
	
	     else if (totalsaving!=0 && totalsaving<number)
	      {
		    printf("Status of Goal Achievement : FAILED!\n");
	      }
    
    printf ("\n=====================================\n");
    printf ("=====================================\n");
    
} 
  fflush(stdin);
  printf("\nDo you want to add another day for your saving? Press Y to add or any key to exit>> ");
  scanf("%c", &answer);
  printf("\n");
  
} while((answer == 'y') || (answer == 'Y'));

	return 0;
}
