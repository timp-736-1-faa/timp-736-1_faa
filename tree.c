#include "treeobhod.h"

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
		++level;
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
	}
}


