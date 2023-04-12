#include<iostream>
#include<stack>
#include<bits/stdc++.h>
using namespace std;

class Node
{
	public:								
    Node *lchild,*rchild;
    char data;
};

class Expression_Tree
{
    string infix,prefix,postfix;
    Node* root;
    public:Node* create_tree();
	public:    
    void input_postfix();
    void inorder_recur(Node* root);
    void preorder_recur(Node* root);
    void postorder_recur(Node* root);
    void inorder_non_recur(Node* root);
    void preorder_non_recur(Node* root);
    void nonrec_postorder(Node *root);
    Expression_Tree()
    {
        root = NULL;
    }
};

void Expression_Tree::input_postfix()
{
    cout<<"\nEnter a Postfix Expression : ";
    cin>>postfix;
}

Node* Expression_Tree::create_tree()
{
    Node *New;
    stack<Node*>s;
    for(int i=0;i<postfix.length();i++)
    {
        New = new Node();
        New->data = postfix[i];
        if(isalnum(postfix[i]))
        {
            New->lchild = New->rchild = NULL;
            s.push(New);
        }
        else
        {
            New->rchild = s.top();
            s.pop();
            New->lchild = s.top();
            s.pop();
            s.push(New);
        }
    }
    New = s.top();
    s.pop();
    return New;
}

void Expression_Tree::inorder_recur(Node* root)
{
    if(root)
    {
        inorder_recur(root->lchild);
        cout<<root->data<<" ";
        inorder_recur(root->rchild);
    }
}
void Expression_Tree::preorder_recur(Node* root)
{
    if(root)
    {
        cout<<root->data<<" ";
        preorder_recur(root->lchild);
        preorder_recur(root->rchild);
    }
}
void Expression_Tree::postorder_recur(Node* root)
{
    if(root)
    {
        postorder_recur(root->lchild);
        postorder_recur(root->rchild);
        cout<<root->data<<" ";
    }
}
void Expression_Tree::inorder_non_recur(Node* root)
{
    stack<Node*>s;
    while(root || !s.empty())
    {
        if(root)
        {
            s.push(root);
            root=root->lchild;
        }
        else
        {
            root=s.top();
            s.pop();
            cout<<root->data<<" ";
            root=root->rchild;
        }
    }
}
void Expression_Tree::preorder_non_recur(Node* root)
{
    stack<Node*>s;
    while(root || !s.empty())
    {
        if(root)
        {
            cout<<root->data<<" ";
            s.push(root);
            root=root->lchild;
        }
        else
        {
            root=s.top();
            s.pop();
            root=root->rchild;
        }
    }
}

void Expression_Tree::nonrec_postorder(Node *root)
{
	stack<int>p;									//
	stack<Node *>st;
	st.push(root);
	Node *temp;
	while(!st.empty())
	{
		temp=st.top();
		st.pop();
		p.push(temp->data);								//
		if(temp->lchild)
		st.push(temp->lchild);							
		if(temp->rchild)
		st.push(temp->rchild);
	}
	while(!p.empty())
	{
		char ch = char(p.top());						//
		cout<<ch<<" ";
		p.pop();
	}
}



int main()
{
    Expression_Tree et;
    do
    {
        cout<<"\n-----------------Menu-----------------";
        cout<<"\n\n1.Input Postfix Expression";
        cout<<"\n2.Create Postfix Tree";
        cout<<"\n3.Recursive Inorder Expression";
        cout<<"\n4.Recursive Preorder Expression";
        cout<<"\n5.Recursive Postorder Expression";
        cout<<"\n6.Non-Recursive Inorder Expression";
        cout<<"\n7.Non-Recursive Preorder Expression";
        cout<<"\n8.Non-Recursive Postorder Expression";
        cout<<"\n9.Exit";
        cout<<"\n\nEnter Your Choice : ";
        int choice;
        cin>>choice;

        switch(choice)
        {
            case 1:
                et.input_postfix();
                break;
            case 2:
                et.create_tree();
                cout<<"\nTree Created Successfully!!!\n";
                break;
            case 3:
                cout<<"\nRecursive Inorder Expression : ";
                et.inorder_recur(et.create_tree());
                cout<<endl;
                break;
            case 4:
                cout<<"\nRecursive Preorder Expression : ";
                et.preorder_recur(et.create_tree());
                cout<<endl;
                break;
            case 5:
                cout<<"\nRecursive Postorder Expression : ";
                et.postorder_recur(et.create_tree());
                cout<<endl;
                break;
            case 6:
                cout<<"\nNon-Recursive Inorder Expression : ";
                et.inorder_non_recur(et.create_tree());
                cout<<endl;
                break;
            case 7:
                cout<<"\nNon-Recursive Preorder Expression : ";
                et.preorder_non_recur(et.create_tree());
                cout<<endl;
                break;
            case 8:
                cout<<"\nNon-Recursive Postorder Expression : ";
                et.nonrec_postorder(et.create_tree());
                cout<<endl;
                break;
            case 9:
                cout<<"\n------------------Thank You-------------------\n\n";
                break;
            default:
                cout<<"\n\nInvalid Input\n";
        }
    }while(choice!=9);
    return 0;
}