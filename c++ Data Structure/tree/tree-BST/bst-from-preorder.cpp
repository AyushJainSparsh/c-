#include<iostream>
#include<limits.h>
using namespace std;

class tree
{
    public : int data;
    tree* left;
    tree* right;
    tree(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

tree* createBST(int preorder[],int* preorderidx,int key,int min, int max,int n)
{
    if(*preorderidx>=n)
    return NULL;
    tree* root=NULL;
    if(key>min && key<max)
    {
       root=new tree(key);
       *preorderidx=*preorderidx+1;
       if(*preorderidx<n)
       root->left=createBST(preorder,preorderidx,preorder[*preorderidx],min,key,n);
       if(*preorderidx<n)
       root->right=createBST(preorder,preorderidx,preorder[*preorderidx],key,max,n);
    }
    return root;
}

void inorder(tree* root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->data<<"\t";
    inorder(root->right);
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
    int pre[]={10,2,1,13,11};
    int idx=0;
    tree* root=createBST(pre,&idx,pre[0],INT_MIN,INT_MAX,5);
    inorder(root);
    cout<<endl;
    preorder(root);
}