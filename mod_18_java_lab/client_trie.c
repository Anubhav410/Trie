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
    long ctr;

    init(&t);

    ctr=open(&t,fp,fmeaning);

    char s[20];//="Apple";

    int ch=1;
    int choice=0;

    //fmeaning= fopen("meanings.txt","r");

	//printf("%s",t->link['a'-97]->key);

	//printf("%d",t->link['a'-97]->link['p'-97]->link['p'-97]->link['l'-97]->link['e'-97]->flag);



	while(ch)

    { 

	printf("\nEnter Choice:0:EXIT\n1:search n display\n2:delete\n3.Insert new word\n");

	scanf("%d",&choice);
        if(choice==-1)
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
                        fclose(fmeaning);

       		} 

      		else

	  	{

      			printf("Not found\n");

	  	}

      		break;

	case 2: printf("enter the word to delete\n");

		scanf("%s",s);

		int n=delete_word(s,&t);

		if(n==-1)

		{

			printf("\nnothing to delete...\n");

		}

		else

		{

			printf("\nword deleted\n");

		}

		break;

	 case 3: printf("Enter the word\n");
                 scanf("%s",s);
                 char meaning[40];
                 printf("Enter meaning\n");
                 scanf("%s",meaning);
                 fmeaning=fopen("meanings.txt","a");
                 insertword(&t,s,++ctr,meaning,fmeaning);
                 printf("The new word and meaning have been added\n");
                 fclose(fmeaning);
                 break;
         default:printf("enter a valid choice");

		ch=1;	

     }
     choice=-1;
}

    return 0;

}
