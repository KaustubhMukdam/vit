#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
    
    Node(int val) : key(val), left(nullptr), right(nullptr), height(1) {}
};

class AVLTreeOptimized {
public:
    int getHeight(Node* node) {
        return node ? node->height : 0;
    }
    
    int getBalance(Node* node) {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }
    
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        
        x->right = y;
        y->left = T2;
        
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        
        return x;
    }
    
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        
        y->left = x;
        x->right = T2;
        
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        
        return y;
    }
    
    Node* insert(Node* node, int key) {
        if (!node)
            return new Node(key);
        
        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else {
            cout << "Key " << key << " already exists in the tree" << "\n";
            return node;
        }
        
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
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
    
    Node* deleteNode(Node* node, int key) {
        if (!node) {
            cout << "Key " << key << " not found in the tree" << "\n";
            return node;
        }
        
        if (key < node->key)
            node->left = deleteNode(node->left, key);
        else if (key > node->key)
            node->right = deleteNode(node->right, key);
        else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            
            Node* temp = node->right;
            while (temp->left)
                temp = temp->left;
            
            node->key = temp->key;
            node->right = deleteNode(node->right, temp->key);
        }
        
        if (!node)
            return node;
        
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
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
        Node* current = node;
        while (current) {
            if (key == current->key)
                return true;
            else if (key < current->key)
                current = current->left;
            else
                current = current->right;
        }
        return false;
    }
    
    void inorder(Node* node) {
        if (node) {
            inorder(node->left);
            cout << node->key << " ";
            inorder(node->right);
        }
    }
    
    void preorder(Node* node) {
        if (node) {
            cout << node->key << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }
    
    void displayTree(Node* node, int level = 0, string prefix = "Root: ") {
        if (node) {
            for (int i = 0; i < level * 4; i++) cout << " ";
            cout << prefix << node->key << " (h=" << node->height 
                 << ", b=" << getBalance(node) << ")" << "\n";
            
            if (node->left || node->right) {
                if (node->left) {
                    displayTree(node->left, level + 1, "L--- ");
                } else {
                    for (int i = 0; i < (level + 1) * 4; i++) cout << " ";
                    cout << "L--- None" << "\n";
                }
                
                if (node->right) {
                    displayTree(node->right, level + 1, "R--- ");
                } else {
                    for (int i = 0; i < (level + 1) * 4; i++) cout << " ";
                    cout << "R--- None" << "\n";
                }
            }
        }
    }
};

int main() {
    AVLTreeOptimized avl;
    Node* root = nullptr;
    int choice, key;
    
    while (true) {
        cout << "1. Insert" << "\n";
        cout << "2. Delete" << "\n";
        cout << "3. Search" << "\n";
        cout << "4. Inorder Traversal" << "\n";
        cout << "5. Preorder Traversal" << "\n";
        cout << "6. Display Tree Structure" << "\n";
        cout << "7. Exit" << "\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                root = avl.insert(root, key);
                cout << "Key " << key << " inserted successfully" << "\n";
                break;
            
            case 2:
                if (!root) {
                    cout << "Tree is empty" << "\n";
                } else {
                    cout << "Enter key to delete: ";
                    cin >> key;
                    root = avl.deleteNode(root, key);
                }
                break;
            
            case 3:
                if (!root) {
                    cout << "Tree is empty" << "\n";
                } else {
                    cout << "Enter key to search: ";
                    cin >> key;
                    if (avl.search(root, key))
                        cout << "Key " << key << " found in the tree" << "\n";
                    else
                        cout << "Key " << key << " not found in the tree" << "\n";
                }
                break;
            
            case 4:
                if (!root) {
                    cout << "Tree is empty" << "\n";
                } else {
                    cout << "Inorder Traversal: ";
                    avl.inorder(root);
                    cout << "\n";
                }
                break;
            
            case 5:
                if (!root) {
                    cout << "Tree is empty" << "\n";
                } else {
                    cout << "Preorder Traversal: ";
                    avl.preorder(root);
                    cout << "\n";
                }
                break;
            
            case 6:
                if (!root) {
                    cout << "Tree is empty" << "\n";
                } else {
                    cout << "\nTree Structure:" << "\n";
                    avl.displayTree(root);
                }
                break;
            
            case 7:
                cout << "Exiting..." << "\n";
                return 0;
            
            default:
                cout << "Invalid choice! Please try again" << "\n";
        }
    }
    
    return 0;
}