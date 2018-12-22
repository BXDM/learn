#include <stdio.h>
int main()
 {struct student
   {long int num;
    char name[20];
    char sex;
    char addr[20];
   }a;
             //={10101,"Li Lin",'M',"123 Beijing Road"};
scanf("%ld%s%c%c%s",&a.num,a.name,&a.sex,&a.sex,a.addr);
//scanf("%ld",&a.num);
//scanf("%s",a.name);
//scanf("%s",a.addr);
//scanf("%c%c",&a.sex,&a.sex);
  printf("NO.:%ld\nname:%s\nsex:%c\naddress:%s\n",a.num,a.name,a.sex,a.addr);
  return 0;
}
