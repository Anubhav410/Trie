# ifndef TRIE_H
# define TRIE_H

struct tree
{
    char key[200];
    struct tree* link[26];
    long flag;
};
typedef struct tree tree_t;
void grounder(tree_t*);
void init(tree_t**);
void insert(tree_t**,char[],int,long);
void insertword(tree_t**, char [],long,char [],FILE* fp );
long search(tree_t** ,char []);
void display(long,FILE* );
long open(tree_t**, FILE* f,FILE* k);
int delete_word(char[],tree_t** );
#endif 
