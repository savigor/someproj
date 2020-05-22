#include <stdio.h>              	 //connect modules 
#include <math.h>
#include <stdlib.h>             	 //for  atoi

int main(int argc, char *argv[])         // main function
{

    int result;
    int n = atoi (argv[1]); 	 	 //convert 1-st arg to int
    int k = atoi (argv[2]);  		 //convert 2-nd arg to int 
//printf("%d, %d\n", n, k);		 // some check ;) 

    if ((n % ( k + 1 ) ) > 0 )     	 //check is able shot step
	{

	    result = n / (k + 1) + 1;   // if shot step is able

	}
	else
        {

	   result =  n / (k + 1) ;  	//if shot step isn't able

        }
    printf("%d\n ", result);            // print result to console 
    return 0;
}

