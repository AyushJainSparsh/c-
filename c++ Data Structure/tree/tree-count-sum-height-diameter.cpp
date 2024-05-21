#include<iostream>
using namespace std;

class tree
{
    public: int data;
    tree* right;
    tree* left;
    tree(int val)
    {
        data=val;
        right=NULL;
        left=NULL;
    }
};

int count(tree* root)
{
    if(root==NULL)
    return 0;
    return count(root->left)+count(root->right)+1;
}

int sumNodes(tree* root)
{
    if(root==NULL)
    return 0;
    return sumNodes(root->left)+sumNodes(root->right)+root->data;
}

int height(tree* root)
{
    if(root==NULL)
    return 0;
    int l=height(root->left);
    int r=height(root->right);
    return max(l,r)+1;
}

int dia(tree* root)
{
    if(root==NULL)
    return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    int ch=lh+rh+1;
    int ld=dia(root->left);
    int rd=dia(root->right);
    return max(ch,max(ld,rd));
}

int main()
{
    tree* root=new tree(1);
    root->left=new tree(2);
    root->right=new tree(3);
    root->left->left=new tree(4);
    root->left->right=new tree(5);
    root->right->left=new tree(6);
    root->right->right=new tree(7);
    cout<<"Count = "<<count(root)<<endl;
    cout<<"Sum of all nodes = "<<sumNodes(root)<<endl;
    cout<<"Height of tree = "<<height(root)<<endl;
    cout<<"Diameter of tree = "<<dia(root)<<endl;
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