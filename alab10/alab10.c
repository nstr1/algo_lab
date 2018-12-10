#include <stdio.h>
#include <stdlib.h>


void insert(int *arr, int index, int val, int *size, int *capacity)
{
	if(*size > *capacity)
	{
		realloc(arr, sizeof(arr) *2);
		*capacity = sizeof(arr) * 2;
	}

	arr[index] = val;
}

void delete(int *arr, int size, int index)
{
	for(int i = index; i < size; i++)
	{
		arr[i] = arr[i + 1];
	}
}


void print(int *arr, int size)
{
	printf("Current array is:\n");
    printf("{ ");
	for(int i = 0; i < size; i++)
	{
		printf("%d, ", arr[i]);
	} 
	printf("}\n");
}

int main(void)
{
	//dynamic arr 
	
	int capacity = 10;

	int a = 10;
	int b = 10;
	int *arr = malloc(a * b * sizeof(int));

	
	printf("Enter a: ");
	scanf("%d", &a);

	printf("Enter b: ");
	scanf("%d", &b);

	printf("Generating elements...\n");
	for(int i = 0; i < size; i++)
	{	
		insert(arr, i, rand(), &size, &capacity);
	}

    print(arr, size);

	int del_index;
	printf("Which element would you like to delete?: ");
	scanf("%d", &del_index);
	del_index -= 1;//because count starts from 0

	delete(arr, size, del_index);
	

	print(arr, size);

	int el;
    int pos;
    printf("Element that you would like to add: \n");
    scanf("%d",&el);

    printf("Position: \n");
    scanf("%d",&pos);

    int *Narr; 
    Narr = malloc((size+1)*sizeof(int));

    pos -= 1;//count starts from 0

    for(int i = 0;i < pos;i++)
    {
    	Narr[i]=arr[i];
    }

    Narr[pos]= el;
    for(int i = pos+1;i<size+1;i++)
    {
    	Narr[i]=arr[i-1];
    }

	print(Narr, size + 1);


	free(arr);
    free(Narr); 
    return 0;
}

