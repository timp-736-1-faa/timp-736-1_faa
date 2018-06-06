#include "./git/treeobhod.h"

int main(){
	rot* treel =  CreateTree();
        ht* queue = CreateQueue();
	int count;
        int key;
        int value;
        scanf("%d" , &count);
        for(int i = 0;i < count;++i){
                scanf("%d%d" , &key , &value);
                AddElementOfTree(treel , key , value);
        }
        printf("\n");
	int i = 0;
       	Write(queue , treel->root);
	do{
		if(queue->head->elemtree->right) Write(queue ,queue->head->elemtree->right);
		if(queue->head->elemtree->left)  Write(queue , queue->head->elemtree->left);
		if(!IsEmpty(queue)) printf("%d " , queue->head->elemtree->value);
		DeleteElem(queue);
	}while(!IsEmpty(queue));
	printf("\n");
}
