/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <stack>


using namespace std;

typedef struct Node {
    public:
    Node *left;
    Node *right;
    int data;
    
    Node (int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    
}Node;

class Tree
{
    Node *root;
    public:
    Tree (int data)
    {
        root = new Node(data);
    }
    
    void insert (int data)
    {
        Node *itr = root;
        while (itr != NULL)
        {
            if (data <= itr->data)
            {
                if (itr->left != NULL)
                {
                    itr = itr->left;
                }
                else
                {
                    itr->left = new Node(data);
                    return;
                }
            }
            else
            {
                if (itr->right != NULL)
                {
                    itr = itr->right;
                }
                else
                {
                    itr->right = new Node(data);
                    return;
                }
            }
        }
    }
    // Recursive traversal functions for BST
    void preOrderTraversal (Node *itr)
    {
        if (itr == NULL)
            return;
        cout << itr->data << " ";
        preOrderTraversal(itr->left);
        preOrderTraversal(itr->right);
    }
    void preOrder ()
    {
        preOrderTraversal(this->root);
        cout << endl;
    }
    void inOrderTraversal (Node *itr)
    {
        if (itr == NULL)
            return;
        inOrderTraversal(itr->left);
        cout << itr->data << " ";
        inOrderTraversal(itr->right);
    }
    void inOrder ()
    {
        inOrderTraversal(this->root);
        cout << endl;
    }
    void postOrderTraversal(Node *itr)
    {
        if (itr == NULL)
            return;
        postOrderTraversal(itr->left);
        postOrderTraversal(itr->right);
        cout << itr->data << " ";
    }
    void postOrder()
    {
        postOrderTraversal(this->root);
        cout << endl;
    }
    
    // Iterative traversal functions for BST
    //Method 1
    // void preOrderItr ()
    // {
    //     // empty tree
    //     if (root == NULL)
    //         return;
    //     Node *itr = root;
    //     stack<Node*> st;
    //     st.push(root);
    //     while (!st.empty())
    //     {
    //         if (itr != NULL)
    //         {
    //             cout << itr->data << " ";
    //             st.push(itr);
    //             itr = itr->left;
    //         }
    //         else
    //         {
    //             itr = st.top();
    //             st.pop();
    //             itr = itr->right;
    //         }
    //     }
    // }
    //Method 2
    void preOrderItr ()
    {
        if (root == NULL)
            return;
        stack<Node*> st;
        st.push(root);
        while (!st.empty())
        {
            Node *itr = st.top();
            st.pop();
            cout << itr->data << " ";
            if (itr->right)
                st.push(itr->right);
            if (itr->left)
                st.push(itr->left);
        }
        cout << endl;
    }
    void inOrderItr ()
    {
        
    }
    void postOrderItr ()
    {
        
    }
};

int main()
{
    Tree t(10);
    
    t.insert(40);
    t.insert(20);
    t.insert(25);
    t.insert(15);
    t.insert(50);
    t.insert(30);
    t.insert(35);
    t.insert(90);
    t.insert(55);
    t.insert(60);
    
    cout << "Recursive traversal results " << endl;
    
    t.preOrder();
    t.inOrder();
    t.postOrder();
    
    cout << "Iterative traversal results " << endl;
    
    t.preOrderItr();
    t.inOrderItr();
    t.postOrderItr();

    return 0;
}