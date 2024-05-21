#include<iostream>
using namespace std;

class tree
{
    public: 
    int data;
    tree* left;
    tree* right;
    tree(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

void inorder(tree* root)\
{
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->data<<"\t";
    inorder(root->right);
}

bool isbst(tree* root,tree* min , tree* max)
{
    if(root==NULL)
    return true;
    if(min != NULL && min->data > root->data)
    return false;
    if(max!= NULL && max->data < root->data)
    return false;
    bool l=isbst(root->left,min,root);
    bool r=isbst(root->right, root, max);
    return l and r;
}

int main()
{
    tree* root=new tree(5);
    root->left=new tree(3);
    root->left->left=new tree(2);
    root->left->right=new tree(4);
    root->right=new tree(7);
    root->right->right=new tree(8);
    //root->right->left=new tree(10);
    inorder(root);
    if(isbst(root,NULL,NULL))
    cout<<"\nBalanced";
    else
    cout<<"\nUnbalanced";
}