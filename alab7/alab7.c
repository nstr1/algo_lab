#include <stdio.h>
#include <stdarg.h>

int sum(int num_args, ...) {
   int val = 0;
   va_list sum;
   int i;

   va_start(sum, num_args);
   for(i = 0; i < num_args; i++) {
      val += va_arg(sum, int);
   }
   va_end(sum);
 
   return val;
}


int main() {
   printf("Sum of 2, 3, 4 = %d\n", sum(2, 3, 4));

   printf("Sum of 5, 10, 15, 6, 8, 4, 16 = %d\n", sum(5, 10, 15, 6, 8, 4, 16));
   
   printf("Sum of 1, 15, 32, 45, 12, 7, 8, 5, 13, 25, 67 = %d\n", sum(1, 15, 32, 45, 12, 7, 8, 5, 13, 25, 67));
}