#include<iostream>
using namespace std;

class tree
{
    public : int data;
    tree* right;
    tree* left;
    tree(int val)
    {
        data=val;
        right=NULL;
        left=NULL;
    }
};

int search(int in[],int s,int e,int c)
{
    for(int i=s;i<=e;i++)
    {
        if(in[i]==c)
        return i;
    }
}

tree* buildtree(int pre[],int in[],int s,int e)
{
    if(s>e)
    return NULL;
    static int idx=0;
    int curr=pre[idx];
    tree* t=new tree(curr);
    idx++;
    if(s==e)
    return t;
    int pos=search(in,s,e,curr);
    t->left=buildtree(pre,in,s,pos-1);
    t->right=buildtree(pre,in,pos+1,e);
    return t;
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
{
    int pre[]={1,2,4,5,3,6,7};
    int in[]={4,2,5,1,6,3,7};
    tree* root=buildtree(pre,in,0,6);
    inorder(root);
}