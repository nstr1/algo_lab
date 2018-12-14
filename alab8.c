#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char name [40];
    int bdate;
    int exam [3];
    float mark;
}ABITUR;

int main (){
    FILE *f;
   
    ABITUR arr[3];

    f = fopen("f.txt", "wb");

    if (f==NULL){
        return 1;
        //In case of error exits from function
        }

    int i;
    
    for(i=1; i<=3;i++){
        //reading from user 

        printf("PIB = ");
        scanf("%s",&arr[i].name);
        fprintf(f, "%c", arr[i].name);

        printf("Birth date = ");
        scanf("%i",&arr[i].bdate);
        fprintf(f, "%c", arr[i].bdate);

        for(int k = 0;k<3; k++){
            printf("Exam%d = ", k + 1);
            scanf("%i",&arr[i].exam[k]);
            fprintf(f, "%c", arr[i].exam[k]);
            }

        printf("Average mark = ");
        scanf("%f",&arr[i].mark);
        fprintf(f, "%c", arr[i].mark);
        //write to file
        printf("writing to file\n");
        fprintf(f, "%\n");
        
            
        printf("Success while writing to file\n\n");
        }

    fclose(f);
    //end of writing to file

    f=fopen("f.txt", "rb");

    if (f == NULL){
        exit(3);
    }
    char ch;
    while((ch = fgetc(f)) != EOF)
      printf("%c", ch);
    fclose(f);
    //end of reading file
    free(f);
    return 0;
}
