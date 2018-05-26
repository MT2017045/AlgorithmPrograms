// C++ program to insert a node in AVL tree 
#include <iostream>
#include <climits>
#include <cstdlib>
using namespace std;
  
struct node
{
    int key;
    struct node *left, *right;
};
  

struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
  

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }

}
 void preorder(struct node *root)
{
    if (root != NULL)
    {
        cout<<root->key<<" ";
        preorder(root->left);
        preorder(root->right);
    }

}
  

struct node* insert(struct node* node, int key)
{

    if (node == NULL) return newNode(key);
 

    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);   
 
    return node;
}
struct node* findmin(struct node* root)
{
while(root->left!=NULL)
{

root=root->left;
}

return root;
}
struct node* del(struct node *root,int key)
{
if(root==NULL)
return root;

if(key<root->key)
root->left=del(root->left,key);


else if(key>root->key)
root->right=del(root->right,key);

else
{
	if(root->left==NULL)
	{
	struct node* temp=root->right;
	free(root);
	return temp;
	}
	else if(root->right==NULL)
	{struct node* temp=root->left;
	free(root);
	return temp;
	}
	else
	{
         
	struct node* temp=findmin(root->right);
	root->key=temp->key;
	root->right=del(root->right,temp->key);	
	}
}
}  

int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
   // insert(root,10);
   
    insert(root, 60);
    insert(root, 80);
   del(root,50);
    // print inoder traversal of the BST
    inorder(root);
   cout<<"\n";
 preorder(root);  
    return 0;
}

