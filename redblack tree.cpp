#include <iostream>
using namespace std;

enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node *left, *right, *parent;

    Node(int data) {
        this->data = data;
        left = right = parent = NULL;
        color = RED;
    }
};

class RBTree {
private:
    Node *root;

    void rotateLeft(Node *&pt) {
        Node *pt_right = pt->right;
        pt->right = pt_right->left;

        if (pt->right != NULL)
            pt->right->parent = pt;

        pt_right->parent = pt->parent;

        if (pt->parent == NULL)
            root = pt_right;
        else if (pt == pt->parent->left)
            pt->parent->left = pt_right;
        else
            pt->parent->right = pt_right;

        pt_right->left = pt;
        pt->parent = pt_right;
    }

    void rotateRight(Node *&pt) {
        Node *pt_left = pt->left;
        pt->left = pt_left->right;

        if (pt->left != NULL)
            pt->left->parent = pt;

        pt_left->parent = pt->parent;

        if (pt->parent == NULL)
            root = pt_left;
        else if (pt == pt->parent->left)
            pt->parent->left = pt_left;
        else
            pt->parent->right = pt_left;

        pt_left->right = pt;
        pt->parent = pt_left;
    }

public:
    RBTree() { root = NULL; }

    void insert(int data) {
        Node *pt = new Node(data);
        root = bstInsert(root, pt);
    }

    Node* bstInsert(Node* root, Node* pt) {
        if (root == NULL)
            return pt;

        if (pt->data < root->data) {
            root->left = bstInsert(root->left, pt);
            root->left->parent = root;
        } else {
            root->right = bstInsert(root->right, pt);
            root->right->parent = root;
        }
        return root;
    }

    void inorder(Node *root) {
        if (root == NULL) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void display() {
        inorder(root);
    }
};

int main() {
    RBTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);

    cout << "Red-Black Tree (Inorder): ";
    tree.display();
}
