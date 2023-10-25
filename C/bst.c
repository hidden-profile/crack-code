#include <stdio.h>
#include <stdlib.h>
struct node
{
    int val;
    struct node *l;
    struct node *r;
};
struct node *ins(int x)
{
    struct node *p;
    p = malloc(sizeof(struct node));
    p->val = x;
    p->l = NULL;
    p->r = NULL;
    return p;
}
struct node *insert(struct node *root, int x)
{
    if (root == NULL)
    {
        return ins(x);
    }
    else if (root->val < x)
    {
        root->r = insert(root->r, x);
    }
    else if (root->val > x)
    {
        root->l = insert(root->l, x);
    }
    return root;
}
void inorder(struct node *ro)
{
    if (ro == NULL)
        return;
    inorder(ro->l);
    printf("%d ", ro->val);
    inorder(ro->r);
}
void preorder(struct node *ro)
{
    if (ro == NULL)
        return;
    printf("%d ", ro->val);
    preorder(ro->l);
    preorder(ro->r);
}
void postorder(struct node *ro)
{
    if (ro == NULL)
        return;
    postorder(ro->l);
    postorder(ro->r);
    printf("%d ", ro->val);
}
struct node *find_minimum(struct node *root)
{
    if (root == NULL)
        return NULL;
    else if (root->l != NULL)
        return find_minimum(root->l);
    return root;
}
struct node *delete(struct node *root, int x)
{
    if (root == NULL)
        return NULL;
    if (x > root->val)
        root->r = delete (root->r, x);
    else if (x < root->val)
        root->l = delete (root->l, x);
    else
    {
        if (root->l == NULL && root->r == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->l == NULL || root->r == NULL)
        {
            struct node *temp;
            if (root->l == NULL)
                temp = root->r;
            else
                temp = root->l;
            free(root);
            return temp;
        }
        else
        {
            struct node *temp = find_minimum(root->r);
            root->val = temp->val;
            root->r = delete (root->r, temp->val);
        }
    }
    return root;
}
void topview(struct node *root)
{
    struct node *temp = root;
    int a[1000];
    a[0] = root->val;
    int i = 1, j;
    while (root->l != NULL)
    {
        a[i] = root->l->val;
        root = root->l;
        i++;
    }
    for (j = i - 1; j >= 0; j--)
    {
        printf("%d ", a[j]);
    }
    while (temp->r != NULL)
    {
        printf("%d ", temp->r->val);
        temp = temp->r;
    }
}

int main()
{
    int t, n, i, j, k, m, p, q;
    struct node *newnode = NULL, *r;
    int x = 1;
    while (x)
    {
        printf("1.insert\n2.delete\n3.findminimum\n4.preorder\n5.postorder\n6.inorder\n7.exit\n");
        printf("enter your choice");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("enter element\n");
            scanf("%d", &p);
            newnode = insert(newnode, p);
            break;
        case 2:
            printf("enter element\n");
            scanf("%d", &p);
            newnode = delete (newnode, p);
            break;
        case 3:
            r = find_minimum(newnode);
            printf("min val=%d\n", r->val);
            break;
        case 4:
            printf("preorder\n");
            preorder(newnode);
            printf("\n");
            break;
        case 5:
            printf("post order\n");
            postorder(newnode);
            printf("\n");
            break;
        case 6:
            printf("inorder\n");
            inorder(newnode);
            printf("\n");
            break;
        case 7:
            x = 0;
            break;
        case 8:
            topview(newnode);
            break;
        default:
            printf("invalid choice enter again \n");
        }
    }
    return 0;
}