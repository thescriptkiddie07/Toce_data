#include <stdio.h>
#include <stdlib.h>
struct Node{
int data;
struct Node *left,*right;
};
struct Node* createNode(int value){
struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
newNode->data=value;
newNode->left=newNode->right=NULL;
return newNode;
};
struct Node* insert(struct Node* root,int value){
if(!root)return createNode(value);
if(value<root->data)root->left=insert(root->left,value);
else if(value>root->data)root->right=insert(root->right,value);
return root;
};
void inorder(struct Node* root){
if(root){inorder(root->left);printf("%d ",root->data);inorder(root->right);}
};
void preorder(struct Node* root){
if(root){printf("%d ",root->data);preorder(root->left);preorder(root->right);}
};
void postorder(struct Node* root){
if(root){postorder(root->left);postorder(root->right);printf("%d ",root->data);}
};
struct Node* search(struct Node* root,int key){
if(!root||root->data==key)return root;
if(key<root->data)return search(root->left,key);
return search(root->right,key);
};
int main(){
struct Node* root=NULL;
int choice,key,n=12,elements[12]={6,9,5,2,8,15,24,14,7,8,5,2};
while(1){
printf("\nMenu:\n1. Create BST\n2. Inorder\n3. Preorder\n4. Postorder\n5. Search\n6. Exit\nEnter choice: ");
scanf("%d",&choice);
switch(choice){
case 1:root=NULL;for(int i=0;i<n;i++)root=insert(root,elements[i]);printf("BST created.\n");break;
case 2:printf("Inorder: ");inorder(root);printf("\n");break;
case 3:printf("Preorder: ");preorder(root);printf("\n");break;
case 4:printf("Postorder: ");postorder(root);printf("\n");break;
case 5:printf("Enter element to search: ");scanf("%d",&key);printf(search(root,key)?"Found\n":"Not found\n");break;
case 6:printf("Exiting...\n");exit(0);
default:printf("Invalid choice!\n");break;
}
}
return 0;
}
