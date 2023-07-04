#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    int Height;
};

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int getHeight(Node *node)
{
    if (node == NULL)
        return 0;
    else
        return node->Height;
}

int BL(Node *node)
{
    return (getHeight(node->left)) - getHeight(node->right);
}

void XoayTrai(Node *&x)
{
    Node *y = x->right;
    Node *tmp = y->left;
    // xoay
    y->left = x;
    x->right = tmp;

    x->Height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->Height = max(getHeight(y->left), getHeight(y->right)) + 1;

    x = y;
}

void XoayPhai(Node *&x)
{
    Node *y = x->left;
    Node *tmp = y->right;
    // Xoay
    y->right = x;
    x->left = tmp;

    x->Height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->Height = max(getHeight(y->left), getHeight(y->right)) + 1;

    x = y;
}

Node *makeNode(int x)
{
    Node *newNode = new Node();
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->Height = 1;
    return newNode;
}

void addNode(Node *&root, int x)
{
    if (root == NULL)
    {
        root = makeNode(x);
        return;
    }

    if (x < root->data)
    {
        addNode(root->left, x);
    }
    else if (x > root->data)
    {
        addNode(root->right, x);
    }
    else
    {
        return;
    }

    root->Height = max(getHeight(root->left), getHeight(root->right)) + 1;
    int Balance = BL(root);
    // LL
    if (Balance > 1 && x < root->left->data)
    {
        XoayPhai(root);
    }
    // RR
    if (Balance < -1 && x > root->right->data)
    {
        XoayTrai(root);
    }
    if (Balance > 1 && x > root->left->data)
    {
        XoayTrai(root->left);
        XoayPhai(root);
    }
    if (Balance < -1 && x < root->right->data)
    {
        XoayPhai(root->right);
        XoayTrai(root);
    }
}

void duyetNLR(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << endl;
        duyetNLR(root->left);
        duyetNLR(root->right);
    }
}

void timMax(Node *root)
{
    if (root != NULL)
    {
        timMax(root->right);
        cout << root->data << endl;
    }
}

int main()
{
    Node *root = NULL;
    addNode(root, 7);
    addNode(root, 1);
    addNode(root, 3);
    addNode(root, 8);
    addNode(root, 2);
    addNode(root, 6);
    duyetNLR(root);

    return 0;
}
