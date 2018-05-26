// C++ program to insert a node in AVL tree 
#include <iostream>
#include <climits>
#include <cstdlib>
using namespace std;
 /*
height: sends height of the node
max: returns max between 2 numbers
calculate sum: calculates sum variable of the structure
prefix sum: calculate sum of all numbers <= the key of the given node
new node: creates new node and initializes values
get mingap,get min,get max,get num:calcultes values of the structure variable
right rotate, left rotate, get balance, insert, preorder
find min: actually not needed. still finds the inorder successor for deletion function
del
search: tells whether the given key is a node or not
get rank: gives rank when given an element
get element: gives element when given a rank
betweennum: returns the number of elements present in the tree in the given range
betweensum: calulates sum of all numbers present in the tree in the given range
maxgap: return max gap
*/
// An AVL tree node
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
    int num;
    int sum;
    int max,min,mingap;
};
 

// A utility function to get height of the tree
int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
 
// A utility function to get maximum of two integers
int max(int a, int b)
{
    return (a > b)? a : b;
}

int calculatesum(struct Node* t)
{

if(t!=NULL)
{
int r=t->key;
if(t->left!=NULL)
r=r+t->left->sum;


if(t->right!=NULL)
r=r+t->right->sum;

return r;
}
}
/* Helper function that allocates a new node with the given key and
    NULL left and right pointers. */
int prefixsum(struct Node* root,int k)
{
int sum=0;
while(root)
{
	if(root->key==k)
	{
	if(root->left!=NULL)
	return (sum+root->left->sum+root->key);
	else
	return (sum+root->key);
	}
	if(root->key<k)
	{ if(root->left!=NULL)
          sum=sum+root->left->sum+root->key;
	else
	  sum=sum+root->key;
	root=root->right;
	}
	else
	root=root->left;
}
return sum;
}
struct Node* newNode(int key)
{
    struct Node* node = (struct Node*)
                        malloc(sizeof(struct Node));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;  // new node is initially added at leaf
    node->num=1;
    node->sum=key;
    node->min=key;
    node->max=key;
    node->mingap=INT_MAX;
    return(node);
}
int getmingap(struct Node *t)
{ int a=0,b=0,c=0,d=0;
if(t->left!=NULL){
a=t->left->mingap;
b=t->key-(t->left->max);
if(b<a)
a=b;
}

if(t->right!=NULL){
c=t->right->mingap;
d=t->right->min-t->key;
if(d<c)
c=d;
}
if(a==0&&c==0) return INT_MAX;
if(a!=0&&c==0) return a;
if(a==0&&c!=0) return c;
if(a!=0&&c!=0) return (a<c)?a:c;
}
int getmin(struct Node *t)
{
if(t!=NULL)
{
	if(t->left!=NULL)
	return t->left->min;
	return t->key;
}
return 0;
}

int getmax(struct Node *t)
{
if(t!=NULL)
{
	if(t->right!=NULL)
	return t->right->max;
	return t->key;
}
return 0;
}

int getnum(struct Node *node)
{
int a,b;
if(node->left==NULL)
a=0;
else
a=node->left->num;

if(node->right==NULL)
b=0;
else
b=node->right->num;

return a+b;
}
 
// A utility function to right rotate subtree rooted with y
// See the diagram given above.
struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
    x->num=1+getnum(x);
    y->num=1+getnum(y);
    x->sum=calculatesum(x);
    y->sum=calculatesum(y);
    x->min=getmin(x);
    y->min=getmin(y);
    x->max=getmax(x);
    y->max=getmax(y);
    x->mingap=getmingap(x);
    y->mingap=getmingap(y);
    // Return new root
    return x;
}
 
// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
     x->num=1+getnum(x);
    y->num=1+getnum(y);
    x->sum=calculatesum(x);
    y->sum=calculatesum(y);
    x->min=getmin(x);
    y->min=getmin(y);
    x->max=getmax(x);
    y->max=getmax(y);
    x->mingap=getmingap(x);
    y->mingap=getmingap(y);
    // Return new root
    return y;
}
 

// Get Balance factor of node N
int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
 

// Recursive function to insert key in subtree rooted
// with node and returns new root of subtree.
struct Node* insert(struct Node* node, int key)
{
    /* 1.  Perform the normal BST insertion */
    if (node == NULL)
        return(newNode(key));
 
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Equal keys are not allowed in BST
        return node;
 
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left),
                           height(node->right));
    node->num=1+getnum(node); 
    node->sum=calculatesum(node);
    node->min=getmin(node);
    node->max=getmax(node);

    node->mingap=getmingap(node);
    /* 3. Get the balance factor of this ancestor
          node to check whether this node became
          unbalanced */
    int balance = getBalance(node);
 
    // If this node becomes unbalanced, then
    // there are 4 cases
 
    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
 
    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
 
    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
 
    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 
    /* return the (unchanged) node pointer */
    return node;
}
 
// A utility function to print preorder traversal
// of the tree.
// The function also prints height of every node
void preOrder(struct Node *root)
{
    if(root != NULL)
    {
        cout<<root->key<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
   
}


struct Node* findmin(struct Node* root)
{
	while(root->left!=NULL)
	{
	root=root->left;
	}

	return root;
}

struct Node* del(struct Node *root,int key)
{
	if(root==NULL)
	return root;
	
	if(key<root->key)
	root->left=del(root->left,key);
	

else if(key>root->key)
root->right=del(root->right,key);

else
{  //root ka left null hoga to poora right wala daal denge,bhale hi right wala null kyu na ho (no child case ho jayega)
	if(root->left==NULL)
	{
	struct Node* temp=root->right;
	free(root);
	return temp;
	}
  //root ka right null hoga, to poora left daal denge
	else if(root->right==NULL)
	{struct Node* temp=root->left;
	free(root);
	return temp;
	}
 //jab dono child ho to inorder successor use krenge
	else
	{
         
	struct Node* temp=findmin(root->right);
	root->key=temp->key;
	root->right=del(root->right,temp->key);	
	}
}

 if (root == NULL)
      return root;
 
    // STEP 2: UPDATE HEIGHT and number OF THE CURRENT NODE
    root->height = 1 + max(height(root->left),
                           height(root->right));

     root->num=1+getnum(root); 
     root->sum=calculatesum(root);
     root->min=getmin(root);
     root->max=getmax(root);
     root->mingap=getmingap(root);
    
    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
    // check whether this node became unbalanced)
    int balance = getBalance(root);
 
    // If this node becomes unbalanced, then there are 4 cases
 
    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
 
    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }
 
    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
 
    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
 
    return root;

}

  
bool search(struct Node *root,int key)
{
while(root){
if(root->key<key)
root=root->right;
else if(root->key>key)
root=root->left;
else return true;
}
return false;
}


int getRank(struct Node * node , int k)
{
int r=0;
if(k>node->max) return 1;
if(k<node->min) return getRank(node,node->min);
if(!search(node,k)) r++;
while(node)
{
	if(node->key<k)
		node=node->right;
       
	else
	{
	if(node->right!=NULL)
	r=r+1+(node->right->num);
        else r++;
	node=node->left;
	}
}
return r;
}

int findElement(struct Node * t, int k)
{ int r=0;
while(t)
	{
	if(t->right!=NULL)
	r=t->right->num;
        else r=0;
	if(r+1==k) return t->key;
	else if(r+1<k)
	{
	k=k-(r+1);
	t=t->left;
	}
	else
	t=t->right;
	}

}

int betweennum(struct Node *root,int x,int y)
{   
   return (getRank(root,x)-getRank(root,y)+1);
}
 

int betweensum(struct Node *root,int x,int y)
{   
   return (prefixsum(root,y)-prefixsum(root,x-1));
}
 
int maxgap(struct Node* root)
{
return root->max-root->min;
}


/* Drier program to test above function*/
int main()
{
  struct Node *root = NULL;
 
  /* Constructing tree given in the above figure */
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
 

  root = insert(root, 25);
  root = insert(root, 5);
  root = insert(root, 4);
  del(root,5);
  /* The constructed AVL Tree would be
            30
           /  \
         20   40
        /  \     \
       10  25    50  
      / 
     4   
*/
  cout<<"Preorder traversal of the constructed AVL"
         " tree is \n";
  preOrder(root);
 cout<<"rank of is: "<<getRank(root,3)<<"\n";
 cout<<"element with rank 7 is "<<findElement(root,7)<<"\n";
 cout<<"no. of elements between 10 ans 40 is "<<betweennum(root,9,40)<<"\n";
cout<<"sum of elements between 10 ans 40 is "<<betweensum(root,9,40)<<"\n";
 cout<<"preifx sum of 40 is"<<prefixsum(root,40)<<"\n";
  cout<<"minimum element= "<<root->min<<" maximum element= "<<root->max<<"\n";
cout<<"maximum gap of tree is "<<maxgap(root)<<"\n";
cout<<"minimum gap of tree is "<<root->mingap<<"\n";

  return 0;
}
