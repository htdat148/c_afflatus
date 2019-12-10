#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};

/* helper function thatt allocates a new node */
/* with the given data and NULL left and right pointer */
struct node* newNode(int data){
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
    return (newNode(data));
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
  struct node *rootNode = newNode(2);
  rootNode->left = newNode(1);
  rootNode->right = newNode(3);
  return (rootNode);

  /* by calling insert() three times passing it the root pointer  */
  /* to build up the tree */
  
  /* struct node* rootNode; */
  /* rootNode = insert(rootNode, 2); */
  /* rootNode = insert(rootNode, 1); */
  /* rootNode = insert(rootNode, 3); */
  /* return (rootNode); */
  
  
}

int sizeTree(struct node *node){
  int count = 0;
  if(node != NULL ){
    count++;
    count = count + sizeTree(node->left) + sizeTree(node->right);
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

/* change a tree s that the roles of the left and right */
/* pointer are swapped at every node */
void minorTree(struct node *node){
 
  if(node ==NULL)
    return;

  else{
    struct node* temp;

    /* swap the pointer in this node */
    temp = node->left;
    node->left = node->right;
    node->right = temp;

    /* do the subtree */
    minorTree(node->left);
    minorTree(node->right);

  }
  
}

/* double tree */
/* For each node in a binary tree, create a new duplicate node */
/* and insert the duplicates as the left child of the origin node */
void doubleTree(struct node *node){
  
  if(node == NULL)
    return;
  else {
    struct node *tempNode;

    tempNode = node->left;
    node->left = (struct node*)malloc(sizeof(struct node));
    node->left->data = node->data;
    
    node->left->left = tempNode;
    node->left->right = NULL;
    /* do the subtree */
    doubleTree(node->left->left);
    doubleTree(node->right);
    
  }
}

/* return 1 if same */
/* Otherwise return 0 */
/* both empty will be considered the same */
int sameTree(struct node *tree1, struct node *tree2){
  /* tree have different size */
  if(sizeTree(tree1) != sizeTree(tree2))
    return 0;

  /* the size of both trees are equal */
  else if(sizeTree(tree1) == sizeTree(tree2)){

    /* both trees are empty */
    if(tree1 == NULL && tree2 == NULL)
      return 1;
  
    else if((tree1 != NULL && tree2 == NULL) ||
	    (tree1 == NULL && tree2 != NULL))
      return 0;

    else if (tree1->data == tree2->data){
      if(sameTree(tree1->left,tree2->left) &&
	  sameTree(tree1->right, tree2->right))
	return 1;
      else
	return 0;
    }
  }
}


int main(){
  struct node *rootNode = NULL;
  struct node *headNode = NULL;

  
}
