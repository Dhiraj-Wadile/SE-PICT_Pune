#include <bits/stdc++.h>
using namespace std;

template <class T>
class node // Node class
{
public:
    T data;
    node<T> *left;
    node<T> *right;
   
    node(T value) // Parameterized constructor
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

template <class T>
class BinarySearchTree // BST class
{
public:
    node<T> *root;
    BinarySearchTree()
    {
        root = NULL;
    }

    node<T> *insert(node<T> *root, T val) // Function to insert nodes in tree
    {
        node<T> *temp = root;
        if (root == NULL)
        {
            root = new node<T>(val);
        }
        else
        {
            if (val < temp->data)
            {
                temp->left = insert(temp->left, val);
            }
            else if (val > temp->data)
            {
                temp->right = insert(temp->right, val);
            }
            else
            {
                cout << "\nDuplicate values are not allowed." << endl;
            }
        }
        return root;
    }

    void search(node<T> *root, T val) // Function to search a node in tree
    {
        if (root == NULL)
        {
            cout << "\nNot Found." << endl;
            return;
        }
        else
        {
            if (val < root->data)
            {
                search(root->left, val);
            }
            else if (val > root->data)
            {
                search(root->right, val);
            }
            else
            {
                cout << "\nFound." << endl;
                return;
            }
        }
    }

    void inorder(node<T> *root) // Inorder traversal function
    {
        if (root != NULL)
        {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    node<T> *findmin(node<T> *root) // Function to find min node in tree
    {
        node<T> *curr = root;
        if (root == NULL)
        {
            return NULL;
        }
        while (curr->left != NULL)
        {
            curr = curr->left;
        }
        return (curr);
    }

    node<T> *findmax(node<T> *root) // Function to find max node in tree
    {
        node<T> *curr = root;
        if (root == NULL)
        {
            return NULL;
        }
        while (curr->right != NULL)
        {
            curr = curr->right;
        }
        return (curr);
    }

    node<T> *deletenode(node<T> *root, T value) // Function to delete a node in tree
    {
        node<T> *temp = root;
        if (root == NULL)
        {
            return NULL;
        }
        else if (value > temp->data)
        {
            temp->right = deletenode(temp->right, value);
        }
        else if (value < temp->data)
        {
            temp->left = deletenode(temp->left, value);
        }
        else
        {
            if (temp->left == NULL && temp->right == NULL)
            {
                return NULL;
            }
            else if (temp->left == NULL)
            {
                node<T> *temp1 = temp->right;
                free(temp);
                return temp1;
            }
            else if (temp->right == NULL)
            {
                node<T> *temp2 = temp->left;
                free(temp);
                return temp2;
            }
            else
            {
                node<T> *p = findmax(root->left);
                root->data = p->data;
                root->left = deletenode(root->left, p->data);
            }
        }
        return root;
    }

    void mirrorBST(node<T> *root) // Function to mirror a tree
    {
        if (root == NULL)
        {
            return;
        }
        else
        {
            mirrorBST(root->left);
            mirrorBST(root->right);
            node<T> *temp = root->right;
            root->right = root->left;
            root->left = temp;
        }
    }

    void leafNodes(node<T> *temp) // Funtion to print leaf nodes
    {
        node<T> *p = temp;
        if (p == NULL)
        {
            return;
        }
        else
        {
            if (p->left == NULL && p->right == NULL)
            {
                cout << p->data << " ";
                return;
            }
        }
        if (p->left)
        {
            leafNodes(p->left);
        }
        if (p->right)
        {
            leafNodes(p->right);
        }
    }

    void parent_child(node<T>* root)
{
if(!root)
    return;
if(root->left || root->right)
    {
	cout<<"\nParent : "<<root->data;
	if(!root->right)
	{
	cout<<"\nChild : "<<root->left->data<<" "<<"Right Child is Null\n";
	}
	else if(!root->left)
	{
	cout<<"\nChild : "<<root->right->data<<" "<<"Left Child is Null\n";
	}
	else
	{
	cout<<"\nChild : "<<root->left->data<<" "<<root->right->data<<endl;
	}
	 	parent_child(root->left);                //
	 	parent_child(root->right);                //
}
}

int depth(node<T>* root)
{
 	if(!root)
 	return 0;
 	else
 	{
 		return 1 + max(depth(root->left),depth(root->right));
 	}
}

};

int main()
{
    BinarySearchTree<int> s1; // Instance of class
    int choice;
    int val, value, n, t;
    do
    {
        cout << "\n\n";
        cout << "\n------OPERATIONS ON BINARY SEARCH------";
        cout << "\n1.Insert node";
        cout << "\n2.Search node";
        cout << "\n3.Delete node";
        cout << "\n4.Find Maximum node";
        cout << "\n5.Find Minimum node";
        cout << "\n6.Display Binary Search tree";
        cout << "\n7.Mirror of BST";
        cout << "\n8.LeafNodes of BST";
        cout << "\n9.Parent Child";
        cout << "\n10.Depth";
        cout << "\n1.Exit from  operations";
        cout << "\n-------------------------";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            s1.root = (s1.insert(s1.root, 50));
            cout << "\nRoot of Binary Search Tree: 50";
            cout << "\nEnter no of elements you want: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cout << "\nEnter values: ";
                cin >> val;
                s1.insert(s1.root, val);
            }
            break;
        case 2:
            cout << "\nEnter value to be searched: ";
            cin >> value;
            s1.search(s1.root, value);
            break;
        case 3:
            int ch;
            cout << "\nEnter element to delete: ";
            cin >> ch;
            s1.deletenode(s1.root, ch);
            cout << "After deletion: ";
            s1.inorder(s1.root);
            break;
        case 4:
            cout << "\nMaximum node: ";
            cout << (s1.findmax((s1.root))->data);
            break;
        case 5:
            cout << "\nMinimum node: ";
            cout << (s1.findmin((s1.root))->data);
            break;
        case 6:
            cout << "\nBinary search tree: ";
            s1.inorder(s1.root);
            break;
        case 7:
            cout << "\nMirror of BST: ";
            s1.mirrorBST(s1.root);
            s1.inorder(s1.root);
            break;
        case 8:
            cout << "\nLeaf Nodes: ";
            s1.leafNodes(s1.root);
            break;
        case 9:
        cout<<"Parent Child";
            s1.parent_child(s1.root);
            break;
        case 10:
        cout<<"Depth";
            s1.depth(s1.root);
            break;
        case 11:
            cout << "\nExiting the program!";
            break;
        default:
            cout << "Invalid choice.";
        }
    } while (choice !=11);
    return 0;
}