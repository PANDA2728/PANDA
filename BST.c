#include<stdio.h>
#include<stdlib.h>
#define COUNT 10

struct node {
    int data;
    struct node *lchild, *rchild;
};


struct node *create(int data) {
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->lchild = new->rchild = NULL;
    return new;
}


struct node *insert(struct node *root, int data) {
    if(root == NULL)
        return create(data);
    else if(data > root->data)
        root->rchild = insert(root->rchild, data);
    else
        root->lchild = insert(root->lchild, data);

    return root;
}


struct node *findmin(struct node *root) {
    if(root->lchild != NULL)
        return findmin(root->lchild);
    else
        return root;
}


struct node *findmax(struct node *root) {
    if(root->rchild != NULL)
        return findmax(root->rchild);
    else
        return root;
}


struct node *delete(struct node *root, int data)
{
    if(data > root->data)
        root->rchild = delete(root->rchild, data);
    else if(data < root->data)
        root->lchild = delete(root->lchild, data);
    else
    {
        if(root->lchild == NULL && root->rchild == NULL)
        {
            free(root);
            root = NULL;
        }

        else if(root->lchild == NULL || root->rchild == NULL)
        {
            struct node *temp;
            if(root->lchild == NULL)
                temp = root->rchild;
            else
                temp = root->lchild;
            free(root);
            return temp;
        }

        else
        {
            struct node *temp = findmin(root->rchild);
            root->data = temp->data;
            root->rchild = delete(root->rchild, temp->data);
        }

    }

    return root;

}


void inorder(struct node *root) {
  if(root){
    inorder(root->lchild);
    printf("%d\t",root->data);
    inorder(root->rchild);
  }
}


void preorder(struct node *root) {
  if(root){
    printf("%d\t",root->data);
    preorder(root->lchild);
    preorder(root->rchild);
  }
}


void postorder(struct node *root) {
  if(root){
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d\t",root->data);
  }
}


void printtree(struct node *root, int space)
{
    if (root == NULL)
        return;
    space += COUNT;
    printtree(root->rchild, space);
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
    printtree(root->lchild, space);
}


int main() {
    int ch, data, maxdata, mindata, count=0, ins=0;
    struct node *root=NULL;
    struct node *temp;
    while(1) {
        printf("\n\n 1. Insert\n 2. Delete\n 3. Find minimum\n 4. Find maximum\n 5. Total node count\n 6. Inorder\n 7. Preorder\n 8. Postorder\n 9.Print \n 10. Exit\n");
        printf("Enter choice:");
        scanf("%d", &ch);
        switch(ch) {
            case 1: printf("\nEnter element to insert in tree: ");
                    scanf("%d", &data);
                    root = insert(root, data);
                    ++count;
                    break;

            case 2: if(root == NULL)
                        printf("\nTree empty\n");
                    else {
                        printf("\nEnter element to delete from tree: ");
                        scanf("%d", &data);
                        root = delete(root, data);
                        --count;
                    }
                    break;

            case 3: if(root == NULL)
                        printf("\nTree empty\n");
                    else {
                        temp = findmin(root);
                        printf("\n%d is the min element\n", temp->data);
                    }
                    break;

            case 4: if(root == NULL)
                        printf("\nTree empty\n");
                    else {
                        temp = findmax(root);
                        printf("\n%d is the max element\n", temp->data);
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

            case 9: printtree(root, 0);
                    break;


            case 10: exit(0);

            default: printf("\nInvalid choice\n");
        }
    }
}
