#include<iostream>
using namespace std;

class tree
{
    public : int data;
    tree* left;
    tree* right;
    public : tree(int val)
    {
        data=val;
        right=NULL;
        left=NULL;
    }
};

void preorder(tree* root)
{
    if(root==NULL)
    return ;
    cout<<root->data<<" , ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(tree* root)
{
    if(root==NULL)
    return ;
    inorder(root->left);
    cout<<root->data<<" , ";
    inorder(root->right);
}

void postorder(tree* root)
{
    if(root==NULL)
    return ;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" , ";
}

int main()
{
    tree* root= new tree(1);
    root->left=new tree(2);
    root->right=new tree(3);
    root->left->left=new tree(4);
    root->left->right=new tree(5);
    root->right->left=new tree(6);
    root->right->right=new tree(7);
    cout<<"\npreorder-\n";
    preorder(root);
    cout<<"\n\ninorder-\n";
    inorder(root);
    cout<<"\n\npostorder-\n";
    postorder(root);
}
//preorder- 1,2,4,5,3,6,7
//inorder- 4,2,5,1,6,3,7
//postorder-4,5,2,6,7,3,1
/*
         1
       /   \
      2     3
     / \   / \
    4   5 6   7
*/