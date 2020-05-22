#include <stdio.h>              	 //connect modules 
#include <stdlib.h>             	 //for  atoi

int main(int argc, char *argv[2])         // main function
{

    int result;
    int n = atoi (argv[1]); 	 	 //convert 1-st arg to int
    int d = atoi (argv[2]);  		 //convert 2-nd arg to int 
//printf("%d, %d\n", n, d);		 // some check ;) 

    result  = (n * (2 * d + (n - 1) * d)) / 2;   	//compute sum of all cables by arithmetic sequence formula 


    printf("%d\n ", result);            // print result to console 
    return 0;
}

