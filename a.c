#include<stdio.h> 
#include<conio.h> 
#include<string.h> 
char state[10]; 
void pickup(int); 
void test(int); 
void putdown(int); 
void print_status(); 
char pname[10][10]; 
char hun[10]; 
int no_phil,max_eater; 
void main() 
{ 
int i,j,k,n,pos,no_eat,round=1; 
char c; 
clrscr(); 
printf("\nEnter number of philosophers: "); 
scanf("%d",&no_phil); 
max_eater=no_phil/2; 
printf("\n%d philosophers can eat at a time to avoid deadlock.",max_eater); 
printf("\nEnter %d philosopher's names one by one: ",no_phil); 
for(i=0;i<no_phil;i++) 
 { 
  scanf("%s",pname[i]); 
 } 
 for(i=0;i<no_phil;i++) 
  state[i]='t'; 
 for(i=0;i<no_phil;i++) 
 { 
  printf("\nposition %d:%s",i,pname[i]); 
 } 
 getch(); 
 while(1) 
 { 
  clrscr(); 
  printf("\nROUND%d",round); 
  printf("\n-------"); 
  printf("\nstatus: "); 
  print_status(); 
  no_eat=0; 
  for(j=0;j<no_phil;j++) 
  { 
   if(state[j]=='h') 
   { 
    pickup(j); 
    if(state[j]=='e') 
     no_eat++; 
   } 
  } 
  printf("\nEnter %d philosophers who wants to eat: ",(max_eater-no_eat)); 
  for(i=0;i<(max_eater-no_eat);i++) 
  { 
   lab: 
    printf("\n\nEnter hungry philosopher%d: ",(i+1)); 
    scanf("%s",hun); 
    for(j=0;j<no_phil;j++) 
    { 
     k=strcmp(pname[j],hun); 
     if(k==0) 
     { 
      pos=j; 
      break; 
     } 
    } 
    pickup(pos); 
    if(state[pos]=='h') 
     goto lab; 
  } 
getch(); 
clrscr(); 
printf("\nCurrent status: "); 
print_status(); 
for(j=0;j<no_phil;j++) 
{ 
if(state[j]=='e') 
{ 
putdown(j); 
} 
} 
printf("\nDo you want to continue?(y/n): "); 
c=getch(); 
if(c=='n'||c=='N') 
break; 
else 
round++; 
} 
getch(); 
} 
void pickup(int i) 
{ 
state[i]='h'; 
test(i); 
} 
void print_status() 
{ 
int i; 
printf("\nPHILOSOPHER\tSTATE"); 
for(i=0;i<no_phil;i++) 
{ 
printf("\n%s\t\t%c",pname[i],state[i]); 
} 
} 
void test(int i) 
{ 
if((state[(i+(no_phil-1))%no_phil]!='e')&&(state[i]=='h')&&(state[(i+1)%no_phil]!='e')) 
{ 
state[i]='e'; 
} 
if(state[i]!='e') 
printf("\n%s must wait since her neighbour is eating",pname[i]); 
else  
Page | 39  
Department of Computer Science and Engineering  
2023-2024 
if(state[i]=='e') 
printf("\nHungry philosopher %s is granted to eat",pname[i]); 
} 
void putdown(int i) 
{ 
state[i]='t'; 
} 