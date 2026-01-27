// Assignment based on TBT (Threaded Binary Tree) creation and performing Stackless Traversals (Inorder Traversal)

//Approach-2: Dummy Node
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
    }
};

class ThreadedBinaryTree {
    Node* root;
    Node* dummy;

    public:
        ThreadedBinaryTree() {
            root = nullptr;
            dummy = new Node(-1);
            dummy->left = dummy;
            dummy->right = dummy;
            dummy->left_thread = true;
            dummy->right_thread = true;
        }

        void insert(int val) {
            Node* newNode = new Node(val);

            if (root == nullptr) {
                root = newNode;
                root->left = dummy;
                root->right = dummy;
                root->left_thread = true;
                root->right_thread = true;
                dummy->left = root;
                dummy->left_thread = false;
                return;
            }
            
            Node* current = root;

            while(true) {
                if (val < current->data) {
                    if (current->left_thread == false) {
                        current = current->left;
                    }
                    else {
                        newNode->left = current->left;
                        newNode->left_thread = true;
                        newNode->right = current;
                        newNode->right_thread = true;
                        current->left = newNode;
                        current->left_thread = false;
                        return;
                    }
                }
                else {
                    if (current->right_thread == false) {
                        current = current->right;
                    }
                    else {
                        newNode->right = current->right;
                        newNode->right_thread = true;
                        newNode->left = current;
                        newNode->left_thread = true;
                        current->right = newNode;
                        current->right_thread = false;
                        return;
                    }
                }
            }
        }

        void inorder() {
            if (root == nullptr) return;
            
            Node* current = root;
            
            while (current != dummy) {
                while (current->left_thread == false) {
                    current = current->left;
                }
                
                cout << current->data << " ";
                
                while (current->right_thread == true) {
                    current = current->right;
                    if (current == dummy) return;
                    cout << current->data << " ";
                }
                
                current = current->right;
            }
        }
};

int main() {
    ThreadedBinaryTree tbt;

    tbt.insert(50);
    tbt.insert(30);
    tbt.insert(70);
    tbt.insert(20);
    tbt.insert(40);
    tbt.insert(60);
    tbt.insert(80);

    cout << "Inorder Traversal of Threaded Binary Tree: ";
    tbt.inorder();
    cout << "\n";

    return 0;
}