#include<iostream>
using namespace std;
class tree
{
    public :
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

void sumReplace(tree* &root)
{
    if(root==NULL)
    return ;
    sumReplace(root->left);
    sumReplace(root->right);
    if(root->left!=NULL)
    root->data+=root->left->data;
    if(root->right!=NULL)
    root->data+=root->right->data;
}

void preorder(tree* root)
{
    if(root==NULL)
    return;
    cout<<root->data<<"\t";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    tree* root=new tree(1);
    root->left=new tree(2);
    root->right=new tree(3);
    root->left->left=new tree(4);
    root->left->right=new tree(5);
    sumReplace(root);
    preorder(root);
}