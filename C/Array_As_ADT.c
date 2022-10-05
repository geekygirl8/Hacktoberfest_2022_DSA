#include <stdio.h>
#include <stdlib.h>
struct myArray
{
   int totalSize;
   int usedSize;
   int *ptr;
};
void createArray(struct myArray *a, int tSize, int uSize)
{
   //  (*a).totalSize = tSize;
   //  (*a).usedSize = uSize;
   //  (*a).ptr = (int *) malloc(tSize*sizeof(int)); // returns a pointer to the first element of
   a->totalSize = tSize;
   a->usedSize = uSize;
   a->ptr = (int *)malloc(tSize * sizeof(int));
}

void set(struct myArray *a){
   int n;
   for(int i=0;i<a->usedSize;i++){
      printf("Enter elements at index %d \n",i);
      scanf("%d",&n);
      a->ptr[i]=n;
   }
}

void show(struct myArray *a)
{
   for (int i = 0; i < a->usedSize; i++)
   {
      printf("%d\n", a->ptr[i]);
   }
}

int main()
{

   struct myArray marks;
   createArray(&marks, 100, 5); // passing the address as create array takes a pointer
   set(&marks);
   show(&marks);
   return 0;
}