#include<stdio.h>
#include<stdlib.h>
#define COUNT 10
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	int height;
};


int height(struct Node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}


int max(int a, int b)
{
	return (a > b)? a : b;
}


struct Node* newNode(int key)
{
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return(node);
}


struct Node* rightRotate(struct Node *y)
{
	struct Node *x = y->left;
	struct Node *T2 = x->right;
	x->right = y;
	y->left = T2;
	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;
	return x;
}


struct Node *leftRotate(struct Node *x)
{
	struct Node *y = x->right;
	struct Node *T2 = y->left;
	y->left = x;
	x->right = T2;
	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;
	return y;
}


int getBalance(struct Node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}


struct Node* insert(struct Node* node, int key)
{
	if (node == NULL)
		return(newNode(key));
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else
		return node;
	node->height = 1 + max(height(node->left),height(node->right));
	int balance = getBalance(node);
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);
	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
    }
	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	return node;
}


struct Node * findmin(struct Node* node)
{
	struct Node* current = node;
    while (current->left != NULL)
		current = current->left;
	return current;
}


struct Node* deleteNode(struct Node* root, int key)
{
	if (root == NULL)
		return root;
	if ( key < root->key )
		root->left = deleteNode(root->left, key);
	else if( key > root->key )
		root->right = deleteNode(root->right, key);
	else
	{
    if(root->left == NULL && root->right == NULL)
    {
        free(root);
        root = NULL;
    }
    else if(root->left == NULL || root->right == NULL)
    {
        struct Node *temp;
        if(root->left == NULL)
            temp = root->right;
        else
            temp = root->left;
        free(root);
        return temp;
    }
    else
    {
        struct Node *temp = findmin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
	}
if (root == NULL)
    return root;

root->height = 1 + max(height(root->left),height(root->right));

int balance = getBalance(root);

if (balance > 1  && key < root->left->key)
    return rightRotate(root);

if (balance < -1 && key > root->right->key)
    return leftRotate(root);

if (balance > 1  && key > root->left->key)
{
    root->left = leftRotate(root->left);
    return rightRotate(root);
}

if (balance < -1 && key < root->right->key)
{
    root->right = rightRotate(root->right);
    return leftRotate(root);
}

return root;
}


struct Node *findmax(struct Node *root)
{
    if(root->right != NULL)
        return findmax(root->right);
    else
        return root;
}


void inorder(struct Node *root) {
  if(root){
    inorder(root->left);
    printf("%d\t",root->key);
    inorder(root->right);
  }
}


void preorder(struct Node *root) {
  if(root){
    printf("%d\t",root->key);
    preorder(root->left);
    preorder(root->right);
  }
}


void postorder(struct Node *root) {
  if(root){
    postorder(root->left);
    postorder(root->right);
    printf("%d\t",root->key);
  }
}
void printtree(struct Node *root, int space)
{
    if (root == NULL)
        return;
    space += COUNT;
    printtree(root->right, space);
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);
    printtree(root->left, space);
}


int main()
{
    int ch, key, count=0, ins=0;
    struct Node *root=NULL;
    struct Node *temp;
    while(1)
    {
        printf("\n\n1. Insert\n2. Delete\n3. Find minimum\n4. Find maximum\n5. Total node count\n6. Inorder\n7. Preorder\n8. Postorder\n 9.Print \n10. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: printf("\nEnter element to insert in tree: ");
                    scanf("%d", &key);
                    root = insert(root, key);
                    ++count;
                    break;

            case 2: if(root == NULL)
                        printf("\nTree empty\n");
                    else {
                        printf("\nEnter element to delete from tree: ");
                        scanf("%d", &key);
                        root = deleteNode(root, key);
                        --count;
                    }
                    break;

            case 3: if(root == NULL)
                        printf("\nTree empty\n");
                    else {
                        temp = findmin(root);
                        printf("\n%d is the min element\n", temp->key);
                    }
                    break;

            case 4: if(root == NULL)
                        printf("\nTree empty\n");
                    else {
                        temp = findmax(root);
                        printf("\n%d is the max element\n", temp->key);
                    }
                    break;

            case 5: printf("\nTotal number of nodes: %d", count);
                    break;

            case 6: if(root == NULL)
                        printf("\nTree empty\n");
                    else
                        inorder(root);
                    break;

            case 7: if(root == NULL)
                        printf("\nTree empty\n");
                    else
                        preorder(root);
                    break;

            case 8: if(root == NULL)
                        printf("\nTree empty\n");
                    else
                        postorder(root);
                    break;

            case 9:
                printtree(root,0);
                break;
            case 10:
                exit(0);

            default: printf("\nInvalid choice\n");
        }
    }
}
