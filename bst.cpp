#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int val;
    node *left;
    node *right;

    node(int val)
    {
        this->left = NULL;
        this->right = NULL;
        this->val = val;
    }
    node* insert(node *root, int val)
    {
        if (!root )
            return new node(val);
        else
        {
            if (val < root->val)
            {
                root->left = insert(root->left, val);
            }
            else if (val > root->val)
                root->right = insert(root->right, val);
        }
        return root;
    }

    node* search(node* root,int val){
    	if(!root || root-> val == val) return root;
    	if(val < root->val) return search(root->left,val);
    	else return search(root->right,val);
    }

    node* inorderSuccessor(node* root){
    	while(root->left){
    		root = root->left;
    	}
    	return root;
    }

    node* deleteINBST(node* root,int val){
    	if(!root) return root;
    	else if(val < root->val) root->left = deleteINBST(root->left,val);
    	else if (val > root->val) root->right = deleteINBST(root->right,val);

    	else {
    		if(!root->left && !root->right){
    			delete root;
    			root = NULL;
    		}
    		else if(root->left == NULL){
    			node* temp= root;
    			root = root->right;
    			delete temp;
    		}
    		else if (root->right == NULL){
    			node* temp = root;
    			root = root->left;
    			delete temp;
    		}
    		else {
    			node* temp= inorderSuccessor(root->right);
    			root->val = temp->val;
    			deleteINBST(root->right,root->val);
    		}

    	}

    	return root;
    }

    void inorder(node* root){
    	if(root){
    		inorder(root->left);
    		cout<< root->val << " ";
    		inorder(root->right);
    	}
    }
};

 int main(int argc, char const *argv[])
 {
 	
 	node* root = new node(20);
 	int arr[]={14,15,12,18,17,16,30,25,23,21,27,35};
 	for(auto val:arr){
 		root = root->insert(root,val);
 	}

 	// root->inorder(root);
 	// cout<<"\n";
 	// cout<<root->search(root,32)->val;

 	// cout<< root->inorderSuccessor(root->search(root,18))->val;

 	root->deleteINBST(root,35);
 	root->inorder(root);
 	// node* find = root->search(root,25);
 	// cout<< root->inorderSuccessor(find->right)->val;
 	return 0;
 }