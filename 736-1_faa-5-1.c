#define MALLOC(a , b) a* b = malloc(sizeof(a)); \
		      if(b ==NULL) exit(1); 	


#include <stdbool.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct ElementOfTree{
        struct ElementOfTree* right;
        struct ElementOfTree* left;
        int key;
	int value;
        } eot;

typedef struct RootOfTree{
	struct ElementOfTree* root;
	} rot;

rot* CreateTree(){
	MALLOC(rot , newroot)
	newroot->root = NULL;
	return newroot;
}

void AddElementOfTree(rot* head , int newkey , int newvalue){
	MALLOC(eot , newelement)
	newelement->key = newkey;
	newelement->value = newvalue;
	newelement->right = newelement->left = NULL;
	if(head->root == NULL){
		head->root = newelement;
		return;
	}
	eot* elem = head->root;
	while(1){
		if(newkey == elem->key){
			elem->value = newvalue;
			free(newelement);
			return;
		}
		if(newkey > elem->key ){
			if(elem->right == NULL){
				elem->right = newelement;
				return;
			}
			elem = elem->right;
		}
		else{
			if(elem->left == NULL){
				elem->left = newelement;
				return;
			}
			elem = elem->left;
		}
	}
}

void FindElement(rot* head , int needkey){
	int level = 0;
	eot* elem = head->root;
	while(1){
		if(elem->key == needkey){
			printf("%d %d\n", level , elem->value);
			return;
		}
    		 if(needkey > elem->key ){
                        if(elem->right == NULL){
                               	printf("-1\n");
				return;
                        }
                        elem = elem->right;
                }
                else{
                        if(elem->left == NULL){
                                printf("-1\n");
                                return;
                        }
                        elem = elem->left;
                }
		level++;
	}
}

int main(){
	rot* tree1 =  CreateTree();
	int count;
	int key;
	int value;
	scanf("%d" , &count);
	for(int i = 0;i < count;++i){
		scanf("%d%d" , &key , &value);
		AddElementOfTree(tree1 , key , value);
	}
	printf("\n");
	for(int i=0; i < 3; ++i){
		scanf("%d" , &key);
		FindElement(tree1 , key);
	}
}
