#include <stdio.h> 
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h> 
#include <string.h>

int showcurdir();
void printFileProperties(struct stat stats);
void getFileProperties(char file[100]);
void printFileList(int showhide, int showprop);
char path[100];

int main(int argc, char *argv[ ])         // main function
{
const char argla[3] = "-la";
const char argal[3] = "-al";
const char argl[3] = "-l";
const char arga[3] = "-a";


	if (argv[1])
	{ 

	    if (((strncmp(argla, argv[1], 3) == 0 ) || (strncmp(argal, argv[1], 3) == 0)) && !argv[2]) // -la; -al
		{
			printFileList(1, 1);			
		}
	    else if  ((strncmp(argl, argv[1], 3) == 0) && !argv[2]) //-l
		{
			printFileList(0, 1);
		}
	    else if  ((strncmp(arga, argv[1], 3) == 0) && !argv[2]) //-a
		{
			printFileList(1, 0);
		}
	    else 
		{
			printf("wrong input \n\r");
		}
         }
	else							// no arguments	
	{
		//printf("no arguments.\n");
		printFileList(0, 0);
		
	}
       
return 0;
}



void printFileProperties(struct stat stats)
{
    	struct tm dt;
	
    	printf("Permission: ");                  // File permissions
    	printf( (S_ISDIR(stats.st_mode)) ? "d" : "-");
   	printf( (stats.st_mode & S_IRUSR) ? "r" : "-");
    	printf( (stats.st_mode & S_IWUSR) ? "w" : "-");
    	printf( (stats.st_mode & S_IXUSR) ? "x" : "-");
     	printf( (stats.st_mode & S_IRGRP) ? "r" : "-");
    	printf( (stats.st_mode & S_IWGRP) ? "w" : "-");
    	printf( (stats.st_mode & S_IXGRP) ? "x" : "-");
    	printf( (stats.st_mode & S_IROTH) ? "r" : "-");
    	printf( (stats.st_mode & S_IWOTH) ? "w" : "-");
    	printf( (stats.st_mode & S_IXOTH) ? "x " : "- ");

    	printf("Size: %10ld ", stats.st_size);        // File size

    	// Get file creation time in seconds and 
    	// convert seconds to date and time format
    	dt = *(gmtime(&stats.st_ctime));
    	printf("Created on: %02d-%02d-%d %02d:%02d:%02d ", dt.tm_mday, dt.tm_mon, dt.tm_year + 1900, 
                                              dt.tm_hour, dt.tm_min, dt.tm_sec);

    	// File modification time
    	dt = *(gmtime(&stats.st_mtime));
    	printf("Modified on: %02d-%02d-%d %02d:%02d:%02d \n\r", dt.tm_mday, dt.tm_mon, dt.tm_year + 1900, 
                                              dt.tm_hour, dt.tm_min, dt.tm_sec);

}

void printFileList(int showhide, int showprop){
		
	struct dirent *de; 		 // Pointer for directory entry 
  		
	DIR *dr = opendir(".");		 // opendir() returns a pointer of DIR type. 
     		  
	while ((de = readdir(dr)) != NULL) {   // for readdir()
            	
		if ((de->d_name[0] == '.') && (showhide == 1))
			{
			printf("%-15s ", de->d_name); 
			if (showprop == 1)
				{
				(void)strcpy(path, (*de).d_name); // transmit file name to var path
		    		getFileProperties(path);

				}
  			}
		if (de->d_name[0] != '.')
		 	{
			printf("%-15s ", de->d_name);
			if (showprop == 1)
				{
				(void)strcpy(path, (*de).d_name);
		    		getFileProperties(path);

				}
			}
		     
			//(void)strcpy(path, (*de).d_name);
		    	//getFileProperties(path);
			}
	printf("\n\r");	    
	closedir(dr);     

}

void getFileProperties(char file[100]) {

	struct stat stats;
	//printf("PATH is %s\n", file);	
		   
        // stat() returns 0 on successful operation,
	// otherwise returns -1 if unable to get file properties.
	if (stat(file, &stats) == 0)
	    {
		printFileProperties(stats);
	    }
	else
	    {
		printf("Unable to get file properties.\n");
		printf("Please check whether '%s' file exists.\n", file);
	    }

}
