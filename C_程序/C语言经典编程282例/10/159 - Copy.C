#include<stdio.h>
#include<dos.h> 

main() 
{ 
   struct SREGS	 seg_stacks;
   segread(&seg_stacks);
   printf("\nCS:%X\tDS:%X\tSS:%X\tES:%X",seg_stacks.cs,
   seg_stacks.ds,seg_stacks.ss,seg_stacks.es);
} 
