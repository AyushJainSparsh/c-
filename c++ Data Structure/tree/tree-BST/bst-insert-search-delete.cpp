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
        left=NULL;
        right=NULL;
    }
};

tree* insertBST(tree* root,int val)
{
    if(root==NULL)
    return new tree(val);
    if(val < root->data)
    root->left=insertBST(root->left,val);
    else
    root->right=insertBST(root->right,val);
    return root;
}

void inorder(tree* root)
{
    if(root==NULL)
    return ;
    inorder(root->left);
    cout<<root->data<<"\t";
    inorder(root->right);
}

bool search(tree* root,int val)
{
    if(root==NULL)
    return false;
    if(root->data==val)
    return true;
    if(val < root->data)
    return search(root->left,val);
    else
    return search(root->right,val); 
}

tree* inorderSucc(tree* root)
{
    tree* curr=root;
    while(curr && curr->left!=NULL)
    curr=curr->left;
    return curr;
}

tree* delBST(tree* root,int key)
{
    if(key < root->data)
    root->left=delBST(root->left,key);
    else if(key > root->data)
    root->right=delBST(root->right,key);
    else
    {
        if(root->left==NULL)
        {
            tree* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            tree* temp=root->left;
            free(root);
            return temp;
        }
        tree* temp=inorderSucc(root->right);
        root->data=temp->data;
        root->right=delBST(root->right,temp->data);
    }
    return root;
}

/*
         5
       /   \
      2     9
     / \   /
    1   4  6
       /    \
      3      7
*/

int main()
{
    tree* root=NULL;
    root=insertBST(root,5);
    insertBST(root,2);
    insertBST(root,9);
    insertBST(root,4);
    insertBST(root,6);
    insertBST(root,1);
    insertBST(root,3);
    insertBST(root,7);
    inorder(root);
    /*if(search(root,6))
    cout<<"\n value found";
    else
    cout<<"\nvalue not found";
    if(search(root,8))
    cout<<"\nvalue found";
    else
    cout<<"\n value not found";
 */ 
    /*cout<<endl;
    root = delBST(root,2);
    inorder(root);
    cout<<endl;
    root = delBST(root,3);
    inorder(root);  
    cout<<endl;
    root = delBST(root,9);
    inorder(root);
    */
}