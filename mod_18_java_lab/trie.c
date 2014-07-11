#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include "trie.h"
void grounder(tree_t* temp)
{
	int i;
	for(i=0;i<26;++i)
	{
	temp->link[i] = 0;
	}
}
//**********************************************************************************************************************
void init(tree_t** ptr_head)
{
	tree_t* head = (tree_t*)malloc(sizeof(tree_t));
	*ptr_head = head;
	grounder(head);
}

//***********************************************************************************************************************
void insert(tree_t** ptr_head,char k[],int d,long c)
{       
	k[0]=tolower(k[0]);
	tree_t* p = (tree_t*)malloc(sizeof(tree_t));
	p = (*ptr_head);
	int i=0,
	l = strlen(k);
	tree_t* temp = (tree_t*)malloc(sizeof(tree_t));
	grounder(temp);
	strcpy(temp->key,k);
	if(l==1)
	{
		if((*ptr_head)->link[*(k+0)-97]== NULL)
		{
			(*ptr_head)->link[*(k+0)-97]= temp;
		}

	}

	else
	{
		for(i = 0;i<l-1;++i)
		{
			p = p->link[*(k+i)-97];
		}
		if(p->link[*(k+i)-97] == NULL)
		{
			p->link[*(k+i)-97] = temp;
		}

	}

	if(l==d)
	{
		p->link[*(k+i)-97]->flag = c;
	}

}
//***********************************************************************************************************************
void insertword(tree_t** ptr_head, char in[],long key,char m[],FILE* fp)
{
	int i = 0;
	int d = strlen(in);
	char send[20];
	strcpy(send,"");
	for(i=1;i<=d;++i)
	{
		strcpy(send,in);
		*(send+i)= '\0';
		insert(ptr_head,send,d,key);
	}
        fprintf(fp,"%ld %s",key,m);
}
//***********************************************************************************************************************

long search(tree_t** ptr_head,char s[])
{ 
  int i=0;
  tree_t* t= *ptr_head;
  while(t!=NULL && s[i]!='\0')   //replaced 0 with null
    { 
	  t=t->link[*(s+i)-97];
      ++i;
    } 
  if(s[i]!='\0')     
    { 
		return -1;
    }
  else
    { 
		return t->flag;
    }
} 
//***********************************************************************************************************************
void display(long k,FILE* fp)
{ 
  long p = 0;
 // FILE* yupiie = fp;
  char mean[20000];
  //#if 0
  while(p!=k)
  { 
//	printf("Value of k %d",k);
	fgets(mean,20000,fp);
	++p;
  }
  
  printf("Meaning %s",mean);
  //#endif
  
  
}
//***********************************************************************************************************************
long  open(tree_t** t,FILE* fp,FILE* fmeaning)
{   char a[1000];
    char word[100] ;//= "apple";
    long count=0;
	
	
	
    while(fgets(a,1000,fp))
    {
        ++count;
        int i=0;
        int n=strlen(a); 
        while((i<=n)&&(isalpha(a[i])))
            i++;
        strncpy(word,a,i);
        strcpy(a,(a+i));
        *(word+i) = '\n';
        *(word+i) = '\0';
        //fprintf(fword,"%s",word);
        insertword(t,word,count,a,fmeaning);
        //fprintf(fmeaning,"%ld %s",count,a);
    }
    fclose(fp);   
    //fclose(fword);
    fclose(fmeaning);
    printf("Finished insertion\n");
    /*
    fp=fopen("words.txt","r");
    while(fgets(word,100,fp))// what does this do??? 
    {
        if(strcmp(word,"\n"))
        {
            word[0] +=32;
            insertword(t,word);
        }
    }
    fclose(fp);
	
    */
    return count;
	
} 
int delete_word(char word[],tree_t**ptr_head )
{
	int k = search(ptr_head,word);
	if(k>0)
	{
		int i=0;
  		tree_t* t= *ptr_head;
  		while(t!=NULL && word[i]!='\0')   //replaced 0 with null
    		{ 
	  		t=t->link[*(word+i)-97];
      			++i;
    		} 
		t->flag = 0;
		return 1;
	}
	else 
		return -1;
  
}
     
  
      
