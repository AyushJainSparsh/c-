#include<iostream>
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

int search(int in[],int s,int e,int c)
{
    for(int i=s;i<=e;i++)
    {
        if(in[i]==c)
        return i;
    }
}

tree* buildtree(int post[],int in[],int s,int e)
{
    if(s>e)
    return NULL;
    static int idx=e;
    int curr=post[idx];
    idx--;
    tree* t=new tree(curr);
    if(s==e)
    return t;
    int pos=search(in,s,e,curr);
    t->right=buildtree(post,in,pos+1,e);
    t->left=buildtree(post,in,s,pos-1);

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
    int post[]={4,5,2,6,7,3,1};
    int in[]={4,2,5,1,6,3,7};
    tree* root=buildtree(post,in,0,6);
    inorder(root);
}