#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
    
    Node(int val) {
        key = val;
        left = right = nullptr;
        height = 1;
    }
};

class AVLTree {
public:
    int getHeight(Node* node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }
    
    int getBalance(Node* node) {
        if (node == nullptr)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }
    
    void updateHeight(Node* node) {
        if (node == nullptr)
            return;
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    }
    
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        
        x->right = y;
        y->left = T2;
        
        updateHeight(y);
        updateHeight(x);
        
        return x;
    }
    
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        
        y->left = x;
        x->right = T2;
        
        updateHeight(x);
        updateHeight(y);
        
        return y;
    }
    
    Node* insert(Node* node, int key) {
        if (node == nullptr)
            return new Node(key);
        
        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else {
            cout << "Key " << key << " already exists in the tree" << endl;
            return node;
        }
        
        updateHeight(node);
        int balance = getBalance(node);
        
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);
        
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);
        
        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        
        return node;
    }
    
    Node* getMinValueNode(Node* node) {
        Node* current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }
    
    Node* deleteNode(Node* node, int key) {
        if (node == nullptr) {
            cout << "Key " << key << " not found in the tree" << endl;
            return node;
        }
        
        if (key < node->key)
            node->left = deleteNode(node->left, key);
        else if (key > node->key)
            node->right = deleteNode(node->right, key);
        else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            
            Node* temp = getMinValueNode(node->right);
            node->key = temp->key;
            node->right = deleteNode(node->right, temp->key);
        }
        
        if (node == nullptr)
            return node;
        
        updateHeight(node);
        int balance = getBalance(node);
        
        if (balance > 1 && getBalance(node->left) >= 0)
            return rightRotate(node);
        
        if (balance > 1 && getBalance(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        
        if (balance < -1 && getBalance(node->right) <= 0)
            return leftRotate(node);
        
        if (balance < -1 && getBalance(node->right) > 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        
        return node;
    }
    
    bool search(Node* node, int key) {
        if (node == nullptr)
            return false;
        
        if (key == node->key)
            return true;
        else if (key < node->key)
            return search(node->left, key);
        else
            return search(node->right, key);
    }
    
    void inorder(Node* node) {
        if (node == nullptr)
            return;
        inorder(node->left);
        cout << node->key << " ";
        inorder(node->right);
    }
    
    void preorder(Node* node) {
        if (node == nullptr)
            return;
        cout << node->key << " ";
        preorder(node->left);
        preorder(node->right);
    }
    
    void postorder(Node* node) {
        if (node == nullptr)
            return;
        postorder(node->left);
        postorder(node->right);
        cout << node->key << " ";
    }
    
    void displayTree(Node* node, int level = 0, string prefix = "Root: ") {
        if (node != nullptr) {
            for (int i = 0; i < level * 4; i++) cout << " ";
            cout << prefix << node->key << " (h=" << node->height 
                 << ", b=" << getBalance(node) << ")" << endl;
            
            if (node->left != nullptr || node->right != nullptr) {
                if (node->left) {
                    displayTree(node->left, level + 1, "L--- ");
                } else {
                    for (int i = 0; i < (level + 1) * 4; i++) cout << " ";
                    cout << "L--- None" << endl;
                }
                
                if (node->right) {
                    displayTree(node->right, level + 1, "R--- ");
                } else {
                    for (int i = 0; i < (level + 1) * 4; i++) cout << " ";
                    cout << "R--- None" << endl;
                }
            }
        }
    }
};

int main() {
    AVLTree avl;
    Node* root = nullptr;
    int choice, key;
    
    while (true) {
        cout << "\n========== AVL TREE OPERATIONS ==========" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Search" << endl;
        cout << "4. Inorder Traversal" << endl;
        cout << "5. Preorder Traversal" << endl;
        cout << "6. Postorder Traversal" << endl;
        cout << "7. Display Tree Structure" << endl;
        cout << "8. Exit" << endl;
        cout << "=========================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                root = avl.insert(root, key);
                cout << "Key " << key << " inserted successfully" << endl;
                break;
            
            case 2:
                if (root == nullptr) {
                    cout << "Tree is empty" << endl;
                } else {
                    cout << "Enter key to delete: ";
                    cin >> key;
                    root = avl.deleteNode(root, key);
                }
                break;
            
            case 3:
                if (root == nullptr) {
                    cout << "Tree is empty" << endl;
                } else {
                    cout << "Enter key to search: ";
                    cin >> key;
                    if (avl.search(root, key))
                        cout << "Key " << key << " found in the tree" << endl;
                    else
                        cout << "Key " << key << " not found in the tree" << endl;
                }
                break;
            
            case 4:
                if (root == nullptr) {
                    cout << "Tree is empty" << endl;
                } else {
                    cout << "Inorder Traversal: ";
                    avl.inorder(root);
                    cout << endl;
                }
                break;
            
            case 5:
                if (root == nullptr) {
                    cout << "Tree is empty" << endl;
                } else {
                    cout << "Preorder Traversal: ";
                    avl.preorder(root);
                    cout << endl;
                }
                break;
            
            case 6:
                if (root == nullptr) {
                    cout << "Tree is empty" << endl;
                } else {
                    cout << "Postorder Traversal: ";
                    avl.postorder(root);
                    cout << endl;
                }
                break;
            
            case 7:
                if (root == nullptr) {
                    cout << "Tree is empty" << endl;
                } else {
                    cout << "\nTree Structure:" << endl;
                    avl.displayTree(root);
                }
                break;
            
            case 8:
                cout << "Exiting..." << endl;
                return 0;
            
            default:
                cout << "Invalid choice! Please try again" << endl;
        }
    }
    
    return 0;
}