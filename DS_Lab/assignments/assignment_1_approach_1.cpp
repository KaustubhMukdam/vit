// Assignment based on TBT (Threaded Binary Tree) creation and performing Stackless Traversals (Inorder Traversal)

//Approach-1: Basic TBT
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    bool left_thread;
    bool right_thread;

    Node(int val) {
        data = val;
        left = right = nullptr;
        left_thread = right_thread = false;
    };

};

class ThreadedBinaryTree {
    Node* root;

    Node* leftmost(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        while (node->left != nullptr && !node->left_thread) {
            node = node->left;
        }
        return node;
    }

    public:
        ThreadedBinaryTree() {
            root = nullptr;
        }

        void insert(int val) {
            Node* newNode = new Node(val);

            if (root == nullptr) {
                root = newNode;
                return;
            }

            Node* parent = nullptr;
            Node* current = root;

            while (current != nullptr) {
                parent = current;

                if (val < current -> data) {
                    if (current->left_thread == false) {
                        current = current->left;
                    }
                    else {
                        break;
                    }
                }
                else {
                    if (current->right_thread == false) {
                        current = current->right;
                    }
                    else {
                        break;
                    }
                }
            }

            if (val < parent -> data) {
                newNode->left = parent->left;
                newNode->left_thread = true;
                newNode->right = parent;
                newNode->right_thread = true;
                parent->left = newNode;
                parent->left_thread = false;
            }
            else {
                newNode->right = parent->right;
                newNode->right_thread = true;
                newNode->left = parent;
                newNode->left_thread = true;
                parent->right = newNode;
                parent->right_thread = false;
            }
        }

        void inorder() {
            Node* current = leftmost(root);
            while (current != nullptr) {
                cout << current->data << " ";
                if (current->right_thread == false) {
                    current = leftmost(current->right);
                }
                else {
                    current = current->right;
                }
            }
        }
};

int main() {
    ThreadedBinaryTree tbt;
    tbt.insert(5);
    tbt.insert(3);
    tbt.insert(7);
    tbt.insert(2);
    tbt.insert(4);
    tbt.insert(6);
    tbt.insert(8);
    tbt.inorder();
    return 0;
}