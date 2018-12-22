#include <stdio.h>
int main()
{
  char grade;
  scanf("%c",&grade);
  printf("Your score:");
  switch(grade)
  { 
	 case 'A': printf("85бл100\n");break;
     case 'B': printf("70бл84\n");break;
     case 'C': printf("60бл69\n");break;
     case 'D': printf("<60\n");break;   
     default:  printf("data error!\n");	 
  }
  return 0;
 }
