// Sequence to preorder and Inorder is given and we will build tree from it
// ALGOTITHM
/*
1. Pick element from end of postorder and create a node.
2. Decrement postorder idx.
3. Search for picked element's pos in inorder.
4. Call to build right subtree from inorder's pos+1 to n.
5. Call to build left subtree from inorder's 0 to pos-1.
6. Return the node.
*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int search(int inorder[], int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == curr)
            return i;
    }

    return -1;
}

Node *buildTree(int postorder[], int inorder[], int start, int end)
{
    static int idx = end;
    if (start > end)
    {
        return NULL;
    }
    int curr = postorder[idx];
    idx--;
    Node *node = new Node(curr);
    if (start == end)
        return node;

    int pos = search(inorder, start, end, curr);
    node->right = buildTree(postorder, inorder, pos + 1, end);
    node->left = buildTree(postorder, inorder, start, pos - 1);

    return node;
}

void inorderprint(struct Node *root)
{
    if (root == NULL)
        return;

    inorderprint(root->left);
    cout << root->data << " ";
    inorderprint(root->right);
}

int main()
{
    int postorder[] = {4, 2, 5, 3, 1};
    int inorder[] = {4, 2, 1, 5, 3};

    // BuildTree
    Node *root = buildTree(postorder, inorder, 0, sizeof(inorder) / sizeof(inorder[0]) - 1);
    inorderprint(root);
    return 0;
}
