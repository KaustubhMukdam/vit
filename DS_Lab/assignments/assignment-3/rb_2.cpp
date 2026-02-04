#include <iostream>
#include <string>
using namespace std;

enum Color { RED, BLACK };

struct Node {
    int key;
    Color color;
    Node* left;
    Node* right;
    Node* parent;
    
    Node(int k) : key(k), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTreeOptimized {
private:
    Node* root;
    Node* NIL;
    
    void leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != NIL) y->left->parent = x;
        y->parent = x->parent;
        if (!x->parent) root = y;
        else if (x == x->parent->left) x->parent->left = y;
        else x->parent->right = y;
        y->left = x;
        x->parent = y;
    }
    
    void rightRotate(Node* x) {
        Node* y = x->left;
        x->left = y->right;
        if (y->right != NIL) y->right->parent = x;
        y->parent = x->parent;
        if (!x->parent) root = y;
        else if (x == x->parent->right) x->parent->right = y;
        else x->parent->left = y;
        y->right = x;
        x->parent = y;
    }
    
    void fixInsert(Node* k) {
        while (k->parent && k->parent->color == RED) {
            if (k->parent == k->parent->parent->right) {
                Node* u = k->parent->parent->left;
                if (u->color == RED) {
                    u->color = BLACK;
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    k = k->parent->parent;
                } else {
                    if (k == k->parent->left) {
                        k = k->parent;
                        rightRotate(k);
                    }
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    leftRotate(k->parent->parent);
                }
            } else {
                Node* u = k->parent->parent->right;
                if (u->color == RED) {
                    u->color = BLACK;
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    k = k->parent->parent;
                } else {
                    if (k == k->parent->right) {
                        k = k->parent;
                        leftRotate(k);
                    }
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    rightRotate(k->parent->parent);
                }
            }
            if (k == root) break;
        }
        root->color = BLACK;
    }
    
    Node* minimum(Node* node) {
        while (node->left != NIL) node = node->left;
        return node;
    }
    
    void transplant(Node* u, Node* v) {
        if (!u->parent) root = v;
        else if (u == u->parent->left) u->parent->left = v;
        else u->parent->right = v;
        v->parent = u->parent;
    }
    
    void fixDelete(Node* x) {
        while (x != root && x->color == BLACK) {
            if (x == x->parent->left) {
                Node* s = x->parent->right;
                if (s->color == RED) {
                    s->color = BLACK;
                    x->parent->color = RED;
                    leftRotate(x->parent);
                    s = x->parent->right;
                }
                if (s->left->color == BLACK && s->right->color == BLACK) {
                    s->color = RED;
                    x = x->parent;
                } else {
                    if (s->right->color == BLACK) {
                        s->left->color = BLACK;
                        s->color = RED;
                        rightRotate(s);
                        s = x->parent->right;
                    }
                    s->color = x->parent->color;
                    x->parent->color = BLACK;
                    s->right->color = BLACK;
                    leftRotate(x->parent);
                    x = root;
                }
            } else {
                Node* s = x->parent->left;
                if (s->color == RED) {
                    s->color = BLACK;
                    x->parent->color = RED;
                    rightRotate(x->parent);
                    s = x->parent->left;
                }
                if (s->right->color == BLACK && s->left->color == BLACK) {
                    s->color = RED;
                    x = x->parent;
                } else {
                    if (s->left->color == BLACK) {
                        s->right->color = BLACK;
                        s->color = RED;
                        leftRotate(s);
                        s = x->parent->left;
                    }
                    s->color = x->parent->color;
                    x->parent->color = BLACK;
                    s->left->color = BLACK;
                    rightRotate(x->parent);
                    x = root;
                }
            }
        }
        x->color = BLACK;
    }
    
    void inorderHelper(Node* node) {
        if (node != NIL) {
            inorderHelper(node->left);
            cout << node->key << " ";
            inorderHelper(node->right);
        }
    }
    
    void displayTreeHelper(Node* node, int level, string prefix) {
        if (node != NIL) {
            string color = (node->color == RED) ? "RED" : "BLACK";
            for (int i = 0; i < level * 4; i++) cout << " ";
            cout << prefix << node->key << " (" << color << ")" << endl;
            if (node->left != NIL || node->right != NIL) {
                if (node->left != NIL) displayTreeHelper(node->left, level + 1, "L--- ");
                else {
                    for (int i = 0; i < (level + 1) * 4; i++) cout << " ";
                    cout << "L--- NIL" << endl;
                }
                if (node->right != NIL) displayTreeHelper(node->right, level + 1, "R--- ");
                else {
                    for (int i = 0; i < (level + 1) * 4; i++) cout << " ";
                    cout << "R--- NIL" << endl;
                }
            }
        }
    }
    
public:
    RedBlackTreeOptimized() {
        NIL = new Node(0);
        NIL->color = BLACK;
        root = NIL;
    }
    
    void insert(int key) {
        Node* node = new Node(key);
        node->left = node->right = NIL;
        
        Node* y = nullptr;
        Node* x = root;
        
        while (x != NIL) {
            y = x;
            if (node->key < x->key) x = x->left;
            else if (node->key > x->key) x = x->right;
            else {
                cout << "Key " << key << " already exists" << endl;
                delete node;
                return;
            }
        }
        
        node->parent = y;
        if (!y) root = node;
        else if (node->key < y->key) y->left = node;
        else y->right = node;
        
        if (!node->parent) {
            node->color = BLACK;
            cout << "Key " << key << " inserted successfully" << endl;
            return;
        }
        if (!node->parent->parent) {
            cout << "Key " << key << " inserted successfully" << endl;
            return;
        }
        
        fixInsert(node);
        cout << "Key " << key << " inserted successfully" << endl;
    }
    
    void deleteNode(int key) {
        Node* z = NIL;
        Node* node = root;
        
        while (node != NIL) {
            if (node->key == key) {
                z = node;
                break;
            }
            node = (node->key < key) ? node->right : node->left;
        }
        
        if (z == NIL) {
            cout << "Key " << key << " not found" << endl;
            return;
        }
        
        Node* y = z;
        Color y_original_color = y->color;
        Node* x;
        
        if (z->left == NIL) {
            x = z->right;
            transplant(z, z->right);
        } else if (z->right == NIL) {
            x = z->left;
            transplant(z, z->left);
        } else {
            y = minimum(z->right);
            y_original_color = y->color;
            x = y->right;
            if (y->parent == z) x->parent = y;
            else {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        
        delete z;
        if (y_original_color == BLACK) fixDelete(x);
        cout << "Key " << key << " deleted successfully" << endl;
    }
    
    bool search(int key) {
        Node* node = root;
        while (node != NIL) {
            if (key == node->key) return true;
            node = (key < node->key) ? node->left : node->right;
        }
        return false;
    }
    
    void inorder() { inorderHelper(root); }
    void displayTree() { displayTreeHelper(root, 0, "Root: "); }
    bool isEmpty() { return root == NIL; }
};

int main() {
    RedBlackTreeOptimized rbt;
    int choice, key;
    
    while (true) {
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Search" << endl;
        cout << "4. Inorder Traversal" << endl;
        cout << "5. Display Tree Structure" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                rbt.insert(key);
                break;
            case 2:
                if (rbt.isEmpty()) cout << "Tree is empty" << endl;
                else {
                    cout << "Enter key to delete: ";
                    cin >> key;
                    rbt.deleteNode(key);
                }
                break;
            case 3:
                if (rbt.isEmpty()) cout << "Tree is empty" << endl;
                else {
                    cout << "Enter key to search: ";
                    cin >> key;
                    cout << "Key " << key << (rbt.search(key) ? " found" : " not found") << endl;
                }
                break;
            case 4:
                if (rbt.isEmpty()) cout << "Tree is empty" << endl;
                else {
                    cout << "Inorder: ";
                    rbt.inorder();
                    cout << endl;
                }
                break;
            case 5:
                if (rbt.isEmpty()) cout << "Tree is empty" << endl;
                else {
                    cout << "\nTree Structure:" << endl;
                    rbt.displayTree();
                }
                break;
            case 6:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }
    
    return 0;
}