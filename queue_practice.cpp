#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;

    Node(int value)
    {
        key = value;
        left = right = NULL;
    }
};

// Insert
Node* insertNode(Node* root, int value)
{
    if(root == NULL)
        return new Node(value);

    if(value < root->key)
        root->left = insertNode(root->left, value);
    else if(value > root->key)
        root->right = insertNode(root->right, value);

    return root;
}

// Search
Node* searchNode(Node* root, int target)
{
    if(root == NULL || root->key == target)
        return root;

    if(target < root->key)
        return searchNode(root->left, target);

    return searchNode(root->right, target);
}

// Inorder (Left Root Right)
void inOrder(Node* root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

// Preorder (Root Left Right)
void preOrder(Node* root)
{
    if(root != NULL)
    {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Postorder (Left Right Root)
void postOrder(Node* root)
{
    if(root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->key << " ";
    }
}

int main()
{
    Node* root = NULL;

    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    // Search
    if(searchNode(root, 60) != NULL)
        cout << "60 Found\n";
    else
        cout << "60 Not Found\n";

    cout << "Inorder   : ";
    inOrder(root);

    cout << "\nPreorder  : ";
    preOrder(root);

    cout << "\nPostorder : ";
    postOrder(root);

    cout << endl;

    return 0;
}
