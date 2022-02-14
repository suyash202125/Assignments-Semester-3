/* Write a program to implement all the tree traversal methods - Preorder, Inorder, Postorder */
#include<iostream>
using namespace std;
 
class Node {
    public:
    	int data;
    	Node *left;
    	Node *right;
    	
    	Node(int d)
        {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Tree_Traversal
{
    public:
    //Function to visit nodes in Preorder
    void preorder(Node *root)
    {
        // base condition for recursion
        // if tree/sub-tree is empty, return and exit
        if(root == NULL)
        {
            return;
        }

        cout << root->data << " "; // Print data
        preorder(root->left);     // Visit left subtree
        preorder(root->right);    // Visit right subtree
    }

    //Function to visit nodes in Inorder
    void inorder(Node *root)
    {
        if(root == NULL)
        {
            return;
        }

        inorder(root->left);            //Visit left subtree
        cout << root->data << " ";      //Print data
        inorder(root->right);           // Visit right subtree
    }

    //Function to visit nodes in Postorder
    void postorder(Node *root)
    {
        if(root == NULL)
        {
            return;
        }

        postorder(root->left);           // Visit left subtree
        postorder(root->right);          // Visit right subtree
        cout << root->data << " ";       // Print data
    }

};
 
int main() {
    
    Tree_Traversal tt;
	/*input tree is made below
	             5
	           /   \
			  /     \
			 6       4
		   /  \     /  \
	      3    7   2    9
    */
    Node *root = new Node(5);
    root -> left = new Node(6);
    root -> right = new Node(4);
    root -> left -> left = new Node(3);
    root -> left -> right = new Node(7);
    root -> right -> left = new Node(2);
    root -> right -> right = new Node(9);

    cout << endl << "Printing the nodes of the tree: " << endl << endl;
	//Printing nodes in Preorder. 
	cout<<"Preorder: ";
	tt.preorder(root);
	cout << endl << endl;
	
	//Printing nodes in Inorder
	cout<<"Inorder: ";
	tt.inorder(root);
	cout << endl << endl;
	
	//Printing nodes in Postorder
	cout<<"Postorder: ";
	tt.postorder(root);
	cout << endl << endl;
	
	
	return 0;
}