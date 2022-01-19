#include <stdio.h>
#include <stdlib.h>

struct BstNode{

  int data;
  struct BstNode* left;
  struct BstNode* right;
};

/* Creating a node in Binary Search Tree */
struct BstNode* GetnewNode(int data){
  struct BstNode* newNode = (struct BstNode*)malloc(sizeof(struct BstNode));
  newNode->data = data;
  newNode->right = newNode->left = NULL;

  return newNode;
}

/* Inserting a node in a Binary Search Tree */
struct BstNode* Insert(struct BstNode* root,int data){
  
  if(root == NULL){
  root = GetnewNode(data);
  }

  else if(data <= root->data){
    root->left = Insert(root->left,data);
  }
  else{
    root->right = Insert(root->right,data);
  }

  return root;
}
/* Searching for a node in a Binary Search Tree */
int search(struct BstNode* root, int  data){

  if(root == NULL){
    return 0;
  }
  else if(root->data == data){
    return 1;
  }
  else if(data <= root->data){
    root = root->left;
  }
  else{
    root = root->right;
  }
}

/* Height of the Tree */
int height(struct Node* root) {
     if(root == NULL) {
		 return 0;
	 } 
	 int left  = height(root->left);
	 int right = height(root->right);

	 return max(left, right) + 1;

	
}


struct BstNode* findMin(struct BstNode* root){
     
     while(root->left != NULL) root = root->left;
     return root;
}

/* Deleting a Node in the binary search tree */
struct BstNode* Delete(struct BstNode* root,int data){
  if(root == NULL) return root;
  else if(data < root->data) root->left = Delete(root->left,data);
  else if(root->data < data) root->right = Delete(root->right,data);
  else{
    
    if(root->right == NULL && root->left == NULL){
         //free(root);
         root = NULL;
    }
    else if(root->right == NULL){
      struct BstNode* temp = root;
      root = root->left;
      free(temp);
    }
    else if(root->left == NULL){
      struct BstNode* temp = root;
      root = root->right;
      free(temp);
    }

    else{
      struct BstNode* temp = findMin(root->right);
      root->data = temp->data;
      root->right = Delete(root->right,temp->data);
    }

  }
  return root;

}
void Inorder(struct BstNode* root){
  if(root == NULL){
    return;
  }
  Inorder(root->left);
  printf("%d ",root->data);
  Inorder(root->right);
}

int main(){

  struct BstNode* root = NULL;
  root =  Insert(root,10);
  root =  Insert(root,8);
  root =  Insert(root,20);
  root =  Insert(root,4);
  root =  Insert(root,9);
  root =  Insert(root,11);
  root =  Insert(root,27);
  root =  Insert(root,23);
  root =  Insert(root,35);
  Inorder(root);
  printf("\n");
  root = Delete(root,11);
  Inorder(root);

  return 0;
}


//second method//
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct bstnode {
    int data;
    struct bstnode* left;
    struct bstnode* right;
};

struct bstnode* getnode(int data)
{
    struct bstnode* x = (struct bstnode*)malloc(sizeof(struct bstnode));
    x->data = data;
    x->left = x->right = NULL;
    return (x);
}
struct bstnode* insert(struct bstnode* root, int key)
{
    if(root==NULL)
    {
        root = getnode(key);
    }
    else if(key<=root->data)
    {
        root->left = insert(root->left, key);
    }
    else {
        root->right = insert(root->right, key);
        }
        return root;
}
void search(struct bstnode* root, int key)
{
    if(root==NULL)
    {
        printf("element not found \n");
    }
    else if(root->data==key)
    {
        printf("element found \n");
    }
    else if(key<=root->data)
    {
         search(root->left,key);
    }
    else
    {
        search(root->right,key);
    }

}

int height(struct bstnode* root)
{
    if(root==NULL)
    {
        return -1;
    }
    else {
        int lst = height(root->left);
        int rst = height(root->right);
        
        if(lst>rst)
        {
            return (lst + 1);
        }
        else {
            return (rst+1);
        }
    }
}
struct bstnode* findmin(struct bstnode* root)
{
    while(root->left !=NULL)
    {
        root=root->left;
    }
    return root;
}

struct bstnode* Delete(struct bstnode* root, int key)
{
    if(root==NULL)
    {
        return root;
    }
    else if(key<root->data)
    {
        root->left = Delete(root->left,key);
    }
    else if(key > root->data)
    {
        root->right = Delete(root->right,key);
    }
    else {
        if(root->left ==NULL && root->right == NULL)
        {
            root=NULL;
        }
        else if(root->left==NULL)
        {
            struct bstnode* temp = root;
            root=root->right;
            free(temp);
        }
        else if(root->right == NULL)
        {
            struct bstnode* temp = root;
            root = root->left;
            free(temp);
        }
        else {
            struct bstnode* temp = findmin(root->right);
            root->data=temp->data;
            root->right = Delete(root->right,temp->data);
        }
    }
    return root;
}

void inorder(struct bstnode* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void preorder(struct bstnode* root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct bstnode* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
int main()
{
    struct bstnode* root;
    int n,d;
    scanf("%d",&n);
    while(n--)
    {
        int val;
        scanf("%d",&val);
      root = insert(root,val);  
    }
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    printf("height of the bst %d \n",height(root));
    int s, val;
    scanf("%d",&s);
    while(s--)
    {
        scanf("%d",&val);
        search(root,val);
    }
      scanf("%d",&d);
     while(d--)
    {
        printf("Deleted element \n");
        int val;
        scanf("%d",&val);
        root = Delete(root,val);
    }
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
     printf("height of the bst %d \n",height(root));
    
    return 0;
}
input:
5
70
20
50
60
80
3
20
50
100
2
20 
50
output:
20 50 60 70 80 
70 20 50 60 80 
60 50 20 80 70 
height of the bst 3 
element found 
element found 
element not found 
Deleted element 
Deleted element 
60 70 80 
70 60 80 
60 80 70 
height of the bst 1 












 

