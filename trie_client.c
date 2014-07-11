# include<stdio.h>
# include<string.h> 
# include<stdlib.h>
# include "trie.h"

int main()
{
    FILE *fp,*fmeaning;
    fp = fopen("Letter A.txt","r");
    fmeaning = fopen("meanings.txt","w");
    //fword = fopen("words.txt","w");
    tree_t* t;
    init(&t);
    open(&t,fp,fmeaning);
    char s[20];//="Apple";
    int ch=1;
    //fmeaning= fopen("meanings.txt","r");
	//printf("%s",t->link['a'-97]->key);
	//printf("%d",t->link['a'-97]->link['p'-97]->link['p'-97]->link['l'-97]->link['e'-97]->flag);

	while(ch)
    { 
	int choice=0;
	printf("\nEnter Choice:0:EXIT\n1:search n display\n2:delete");
	scanf("%d",&choice);
	  switch(choice)
	{
	case 0: ch=0;
		break;
	case 1: printf("Enter string\n");
      		scanf("%s",s);
      		long k=search(&t,s);
      		if(k>0)
      		{	
			printf("Found at %ld\n",k);
			fmeaning= fopen("meanings.txt","r");
        		display(k,fmeaning);
       		} 
      		else
	  	{
      			printf("Not found\n");
	  	}
      		break;
	case 2: printf("enter the word to delete\n");
		scanf("%s",s);
		int k=delete(s,&t);
		if(k==-1)
		{
			printf("\nnothing to delete...\n");
		}
		else
		{
			printf("\nword deleted\n");
		}
		break;
	default:printf("enter a valid choice");
		ch=1;	
    }
    return 0;
}
