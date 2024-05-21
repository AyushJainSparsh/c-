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
//using sorted array
tree* create(int a[],int s,int e)
{
    if(s>e)
    return NULL;
    int m=(s+e)/2;
    tree* root=new tree(a[m]);
    root->left=create(a,s,m-1);
    root->right=create(a,m+1,e);
    return root;
}

void preorder(tree* root)
{
    if(root==NULL)
    return;
    cout<<root->data<<"\t";
    preorder(root->left);
    preorder(root->right);
}

void inorder(tree* root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->data<<"\t";
    inorder(root->right);
}

int main()
{           //0, 1, 2, 3, 4, 5, 6
    int a[]={25,45,50,55,60,65,85};
    tree* root=create(a,0,6);
    preorder(root);
    cout<<"\n\n";
    inorder(root);
}