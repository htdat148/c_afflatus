#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};

/* helper function thatt allocates a new node */
/* with the given data and NULL left and right pointer */
struct node* NewNode(int data){
  struct node *nodeRef = (struct node *)malloc(sizeof(struct node));
  nodeRef->data = data;
  nodeRef->left = NULL;
  nodeRef->right = NULL;

  return (nodeRef);
}

/* Given a binary search tree and a number, inserts a new node */
/* with the given number in the correct place in the tree */
/* Return the new root pointer wich the caller should then use */
/* the standart trich to avoid using reference */
struct node* insert(struct node* node, int data){
  if (node == NULL){
    return (NewNode(data));
  }
  else{
    /* the left node */
    if (data <= node->data)
      node->left = insert(node->left, data);
    else
      node->right = insert(node->right, data);
    return (node);
    
  }
}


struct node* build123(){
  /* calling newNode three timer, and using three pointer variable */
  /* struct node *rootNode = NewNode(2); */
  /* rootNode->left = NewNode(1); */
  /* rootNode->right = NewNode(3); */
  /* return (rootNode); */

  /* by calling insert() three times passing it the root pointer  */
  /* to build up the tree */
  
  struct node* rootNode;
  rootNode = insert(rootNode, 2);
  rootNode = insert(rootNode, 1);
  rootNode = insert(rootNode, 3);
  return (rootNode);
  
  
}

int size(struct node *node){
  int count = 0;
  if(node != NULL ){
    count++;
    count = count + size(node->left) + size(node->right);
    return count;
  }
  else{
    return count;
  }
  
}

int maxDepth(struct node* node){
  int countLeft = 0;
  int countRight = 0;


  if(node != NULL){
    countLeft++;
    countRight++;
    
    countLeft = countLeft + maxDepth(node->left);
    countRight = countRight + maxDepth(node->right);
  }

  
  if(countLeft <= countRight)
    return countRight;
  else
    return countLeft;
}

int minValue(struct node *node){
  /* only focus the left side */
  if(node->left != NULL)
    minValue(node->left);
  else
    return node->data;
}

void printTree(struct node* node){

  /* print left side */
  if(node->left != NULL)
    printTree(node->left);

  printf(" %d", node->data);
  

  /* print right side */
  if(node->right != NULL)
    printTree(node->right);
}


int main(){
  struct node *rootNode = NULL;

  rootNode = build123();
  insert(rootNode, 7);
  insert(rootNode, 4);
  insert(rootNode, 7);
  insert(rootNode, 5);
  insert(rootNode, 6);
  insert(rootNode, -3);
  insert(rootNode, -100);
  printf("Size: %d\n", size(rootNode));
  printf("Depth: %d\n", maxDepth(rootNode));
  printf("min: %d\n", minValue(rootNode));
  printTree(rootNode);
  
}
