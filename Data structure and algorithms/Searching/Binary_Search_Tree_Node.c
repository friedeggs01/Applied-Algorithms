#include<stdio.h>
struct TreeNodeRec
{
    float key;

    struct TreeNodeRec* leftPtr;
    struct TreeNodeRec* rightPtr;
};
typedef struct TreeNodeRec TreeNode;

TreeNode* makeTreeNode(float value){
   TreeNode* newTreeNode = NULL;
   newNodePtr = (TreeNode*)malloc(sizeof(TreeNode));

   if(newNodePtr == NULL){
    fprintf(stderr, )
   } else {
    newNodePtr->key = value;
    newNodePtr->leftPtr = NULL;
    newNodePtr->rightPtr = NULL;
   }
   return newNodePtr;
}

TreeNode* findMin(TreeNode* nodePtr){
    if(nodePtr == NULL){
        return NULL;
    } else {
        if(nodePtr -> leftPtr = NULL) return nodePtr;
        else return(findMin(nodePtr->leftPtr));
    }
}

TreeNode* findMax(TreeNode* nodePtr){
    if(nodePtr == NULL){
        return NULL;
    } else {
        if(nodePtr -> rightPtr = NULL) return nodePtr;
        else return(findMax(nodePtr->rightPtr));
    }
}

TreeNode* insert(TreeNode* nodePtr, float item){
    if(nodePtr == NULL){
        nodePtr = makeTreeNode(item);
    } else if(item < nodePtr->key){
        nodePtr->leftPtr = insert(nodePtr->leftPtr, item)
    } else if(item > nodePtr->key){
        nodePtr->rightPtr = insert(nodePtr->rightPtr, item);
    }
    return nodePtr;
}
TreeNode* delete(TreeNode *nodePtr, float item){
    TreeNode tmp;
    if(nodePtr != NULL){
        if(item < nodePtr->key){
            nodePtr->leftPtr = delete(nodePtr->leftPtr, item);
        } else if(item > nodePtr->key){
            nodePtr->rightPtr = delete(nodePtr->rightPtr, item);
        } else { 
            if(nodePtr->leftPtr && nodePtr->rightPtr){
            tmp = findMin(nodePtr->rightPtr);
            nodePtr->key = tmp->key;
            nodePtr->rightPtr = delete(nodePtr->rightPtr, nodePtr->key);
            } else if(nodePtr->leftPtr == NULL){
                nodePtr = nodePtr->rightPtr;
            } else if(nodePtr->rightPtr == NULL){
                nodePtr = nodePtr->leftPtr;
            }
        }
        free(tmp);
    }
    return nodePtr;
}
TreeNode* search(TreeNode* nodePtr, float item){
    if(nodePtr != NULL){
        if(item < nodePtr->key){
            nodePtr = search(nodePtr->leftPtr, item);
        } else if(item > nodePtr->key){
            nodePtr = search(nodePtr->rightPtr, item);
        }
    }
    return nodePtr;
}

void printInorder(const TreeNode* nodePtr);
void printPreorder(const TreeNode* nodePtr);
void printPostorder(const TreeNode* nodePtr);


int main() {

}