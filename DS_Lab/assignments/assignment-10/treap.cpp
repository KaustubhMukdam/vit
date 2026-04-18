#include <iostream>
#include <cstdlib>
using namespace std;

// Treap Node
struct TreapNode {
    int key;
    int priority;
    TreapNode* left;
    TreapNode* right;

    TreapNode(int k, int p) {
        key = k;
        priority = p;
        left = right = nullptr;
    }
};

class Treap {
public:
    TreapNode* rightRotate(TreapNode* y) {
        TreapNode* x = y->left;
        y->left = x->right;
        x->right = y;
        return x;
    }

    TreapNode* leftRotate(TreapNode* x) {
        TreapNode* y = x->right;
        x->right = y->left;
        y->left = x;
        return y;
    }

    // Insert operation
    TreapNode* insert(TreapNode* root, int key, int priority) {
        if (!root) return new TreapNode(key, priority);

        if (key <= root->key) {
            root->left = insert(root->left, key, priority);
            // Fix Max-Heap property
            if (root->left->priority > root->priority)
                root = rightRotate(root);
        } else {
            root->right = insert(root->right, key, priority);
            // Fix Max-Heap property
            if (root->right->priority > root->priority)
                root = leftRotate(root);
        }
        return root;
    }

    // Delete operation
    TreapNode* deleteNode(TreapNode* root, int key) {
        if (!root) return root;

        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else {
            // Node with no children
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            }
            // Node with two children
            else if (root->left && root->right) {
                if (root->left->priority > root->right->priority) {
                    root = rightRotate(root);
                    root->right = deleteNode(root->right, key);
                } else {
                    root = leftRotate(root);
                    root->left = deleteNode(root->left, key);
                }
            }
            // Node with one child
            else {
                TreapNode* child = (root->left) ? root->left : root->right;
                delete root;
                return child;
            }
        }
        return root;
    }

    void inorder(TreapNode* root) {
        if (root) {
            inorder(root->left);
            cout << "Key: " << root->key << " | Priority: " << root->priority << "\n";
            inorder(root->right);
        }
    }
};

int main() {
    Treap t;
    TreapNode* root = nullptr;

    // Fixed priorities for demonstration (usually rand() is used)
    root = t.insert(root, 50, 15);
    root = t.insert(root, 30, 20); // Will rotate right
    root = t.insert(root, 70, 10);
    root = t.insert(root, 20, 25); // Will bubble up to root
    root = t.insert(root, 40, 5);

    cout << "Inorder Traversal after Insertion (Should be sorted by Key):\n";
    t.inorder(root);

    cout << "\nDeleting 30...\n";
    root = t.deleteNode(root, 30);

    cout << "Inorder Traversal after Deletion:\n";
    t.inorder(root);

    return 0;
}