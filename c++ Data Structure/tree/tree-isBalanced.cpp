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

int height(tree* root)
{
    if(root==NULL)
    return 0;
    int l=height(root->left);
    int r=height(root->right);
    return max(l,r)+1;
}

bool isBal(tree* root)
{
    if(root==NULL)
    return true;
    if(isBal(root->left)==false || isBal(root->right)==false)
    return false;
    int lh=height(root->left);
    int rh=height(root->right);
    if(abs(lh-rh)<=1)
    return true;
    else
    return false;
}

int main()
{
    tree* root= new tree(1);
    root->left=new tree(2);
    root->right=new tree(3);
    root->left->left=new tree(4);
    root->left->right=new tree(5);
    root->right->left=new tree(6);
    root->left->left->left=new tree(7);
    root->left->left->left->left=new tree(8);
    if(isBal(root))
    cout<<"Balanced\n";
    else
    cout<<"Not Balanced\n";
}