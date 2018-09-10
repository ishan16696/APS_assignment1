#include<stdio.h>
#include<stdlib.h>
 
struct nod
{
    int info;
    struct nod *left;
    struct nod *right;
    int no;
    int height;
};
 
int maximum(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}


int height(struct nod *l)
{
    if (l == NULL)
        return 0;
    return l->height;
}
 

struct nod* new_node(int info)
{
    struct nod* node = (struct nod*)malloc(sizeof(struct nod));
    node->info   = info;
    node->left   = NULL;
    node->right  = NULL;
    node->no = 1;
    node->height = 1;  
    return(node);
}
 
int no_up(struct nod *x)
{   
    return 1+x->left->no+x->right->no;
}

struct nod *right_Rot(struct nod *t)
{
    struct nod *x = t->left;
    struct nod *m = x->right;
 
   
    x->right = t;
    t->left = m;
 
    
    t->height = maximum(height(t->left), height(t->right))+1;
    t->no = no_up(t);
    x->height = maximum(height(x->left), height(x->right))+1;
    x->no = no_up(x);
   
    return x;
}
 

struct nod *left_Rot(struct nod *x)
{
    struct nod *y = x->right;
    struct nod *m = y->left;
 
    
    y->left = x;
    x->right = m;
    x->height = maximum(height(x->left), height(x->right))+1;
    y->height = maximum(height(y->left), height(y->right))+1;
    return y;
}
 

int balance_getter(struct nod *p)
{
    if (p == NULL)
        return 0;
    return height(p->left) - height(p->right);
}
 
struct nod* insertion(struct nod* node, int info)
{
    
    if (node == NULL)
        return(new_node(info));
 
    if (info < node->info)
        node->left  = insertion(node->left, info);
    else if (info > node->info)
        node->right = insertion(node->right, info);
    else 
        return node;
 
   
    node->height = 1 + maximum(height(node->left), height(node->right));
 
    
    int balance = balance_getter(node);
 
    
    if (balance > 1 && info < node->left->info)
        return right_Rot(node);
 
    
    if (balance < -1 && info > node->right->info)
        return left_Rot(node);
 
   
    if (balance > 1 && info > node->left->info)
    {
        node->left =  left_Rot(node->left);
        return right_Rot(node);
    }
 
   
    if (balance < -1 && info < node->right->info)
    {
        node->right = right_Rot(node->right);
        return left_Rot(node);
    }
 
    
    return node;
}
 

struct nod * minVal_node(struct nod* node)
{
    struct nod* current = node;
 
    
    while (current->left != NULL)
        current = current->left;
 
    return current;
}
 

struct nod* del_node(struct nod* root, int info)
{
    if (root == NULL)
        return root;
    
   if ( info < root->info )
        root->left = del_node(root->left, info);
 
    else if( info > root->info )
        root->right = del_node(root->right, info);
   
    else
    {
        
       if( (root->left == NULL) || (root->right == NULL) )
        {
            struct nod *var = root->left ? root->left :root->right;
 
            if (var == NULL)
            {
                var = root;
                root = NULL;
            }
            else 
             *root = *var; 
            free(var);
        }
        else
        {
 
            struct nod* var = minVal_node(root->right);
  
            root->info = var->info;
            root->right = del_node(root->right, var->info);
        }
    }
 
    
    if (root == NULL)
      return root;
 
   
    root->height = 1 + maximum(height(root->left), height(root->right));
 
    
    int bal = balance_getter(root);
 
    
    if (bal > 1 && balance_getter(root->left) >= 0)
        return right_Rot(root);
 
    
    if (bal > 1 && balance_getter(root->left) < 0)
    {
        root->left =  left_Rot(root->left);
        return right_Rot(root);
    }
 
    if (bal < -1 && balance_getter(root->right) <= 0)
        return left_Rot(root);
 
    
    if (bal < -1 && balance_getter(root->right) > 0)
    {
        root->right = right_Rot(root->right);
        return left_Rot(root);
    }
 
    return root;
}
 
int main()
{
  struct nod *root = NULL;
 
  
    root = insertion(root, 9);
    root = insertion(root, 5);
    root = insertion(root, 10);
    root = insertion(root, 0);
    root = insertion(root, 6);
    root = insertion(root, 11);
    root = insertion(root, -1);
    root = insertion(root, 1);
    root = insertion(root, 2);
 
    printf("Preorder traversal of the constructed AVL ""tree is \n");
   // preOrder(root);
 
    root = del_node(root, 10);
    printf("\nPreorder traversal after deletion of 10 \n");
    //preOrder(root);
 
    return 0;
}