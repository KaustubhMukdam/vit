#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    bool left_thread;
    bool right_thread;
    
    Node(int val) : data(val), left(nullptr), right(nullptr), 
                     left_thread(false), right_thread(false) {}
};

class ThreadedBinaryTreeOptimized {
    Node* root;
    Node* dummy;
    
public:
    ThreadedBinaryTreeOptimized() {
        root = nullptr;
        dummy = new Node(-1);
        dummy->left = dummy;
        dummy->right = dummy;
        dummy->left_thread = true;
        dummy->right_thread = true;
    }
    
    void insert(int data) {
        Node* newNode = new Node(data);
        
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
        
        while (true) {
            if (data < current->data) {
                if (current->left_thread == false) {
                    current = current->left;
                } else {
                    newNode->left = current->left;
                    newNode->left_thread = true;
                    newNode->right = current;
                    newNode->right_thread = true;
                    current->left = newNode;
                    current->left_thread = false;
                    return;
                }
            } else {
                if (current->right_thread == false) {
                    current = current->right;
                } else {
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
        if (root == nullptr) {
            return;
        }
        
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
    
    void preorder() {
        if (root == nullptr) {
            return;
        }
        
        Node* current = root;
        
        while (current != dummy) {
            cout << current->data << " ";
            
            if (current->left_thread == false) {
                current = current->left;
            } else {
                while (current != dummy && current->right_thread == true) {
                    current = current->right;
                }
                
                if (current != dummy) {
                    current = current->right;
                }
            }
        }
    }
    
    bool isEmpty() {
        return root == nullptr;
    }
};

int main() {
    ThreadedBinaryTreeOptimized tbt;
    int choice, data;
    
    while (true) {
        cout << "\n===== THREADED BINARY TREE (TBT) =====" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Inorder Traversal (Stackless)" << endl;
        cout << "3. Preorder Traversal (Stackless)" << endl;
        cout << "4. Exit" << endl;
        cout << "=======================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> data;
                tbt.insert(data);
                cout << "Data " << data << " inserted successfully" << endl;
                break;
            
            case 2:
                if (tbt.isEmpty()) {
                    cout << "Tree is empty" << endl;
                } else {
                    cout << "Inorder Traversal: ";
                    tbt.inorder();
                    cout << endl;
                }
                break;
            
            case 3:
                if (tbt.isEmpty()) {
                    cout << "Tree is empty" << endl;
                } else {
                    cout << "Preorder Traversal: ";
                    tbt.preorder();
                    cout << endl;
                }
                break;
            
            case 4:
                cout << "Exiting..." << endl;
                return 0;
            
            default:
                cout << "Invalid choice! Please try again" << endl;
        }
    }
    
    return 0;
}