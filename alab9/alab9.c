
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h>
#include <sys/stat.h>
  

long filesize(FILE *fp);

int main() 
{ 
    FILE *fptr1, *fptr2; 
    char filename[100]; 
  
    printf("Enter the filename to open for reading \n"); 
    scanf("%s", filename); 
  
    
    fptr1 = fopen(filename, "r"); 
    if (fptr1 == NULL) 
    { 
        printf("Cannot open file %s \n", filename); 
        exit(0); 
    } 
  
    printf("Enter the filename to open for writing \n"); 
    scanf("%s", filename); 
  
  
    fptr2 = fopen(filename, "w"); 
    if (fptr2 == NULL) 
    { 
        printf("Cannot open file %s \n", filename); 
        exit(0); 
    } 
  
   
    char line[256];
    int i = 1;

    while (fgets(line, sizeof(line), fptr1)) {
        if(i % 2 == 0)
        {
        	fputs(line, fptr2);       	
        }
        i++;
    }

    
  
    printf("\nContents copied to %s\n\n", filename); 

    long f1Size = filesize(fptr1);
    long f2Size = filesize(fptr2);

    printf("Size of f1 is %ld bytes\n", f1Size);
    printf("Size of f2 is %ld bytes\n", f2Size);
  
    fclose(fptr1); 
    fclose(fptr2); 
    return 0; 
}

long filesize(FILE *fp)
{
	fseek(fp, 0, SEEK_END);
    long bytes = ftell(fp);
    rewind(fp);
    return bytes;
}