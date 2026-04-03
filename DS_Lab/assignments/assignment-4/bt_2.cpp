#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class BNode {
public:
    vector<int> keys;
    vector<BNode*> children;
    bool leaf;
    int t;
    
    BNode(int _t, bool _leaf) : t(_t), leaf(_leaf) {}
    
    void insertNonFull(int k);
    void splitChild(int i, BNode* y);
    void traverse();
    BNode* search(int k);
    void remove(int k);
    int findKey(int k);
    void removeFromLeaf(int idx);
    void removeFromNonLeaf(int idx);
    int getPred(int idx);
    int getSucc(int idx);
    void fill(int idx);
    void borrowFromPrev(int idx);
    void borrowFromNext(int idx);
    void merge(int idx);
    
    friend class BTree;
};

class BTree {
    BNode* root;
    int t;
    
public:
    BTree(int _t) : root(nullptr), t(_t) {}
    
    void traverse() {
        if (root) root->traverse();
    }
    
    BNode* search(int k) {
        return root ? root->search(k) : nullptr;
    }
    
    void insert(int k);
    void remove(int k);
    void display(BNode* node, int level);
    void displayTree() {
        if (root) display(root, 0);
    }
    
    bool isEmpty() {
        return !root || root->keys.empty();
    }
};

int BNode::findKey(int k) {
    int idx = 0;
    while (idx < keys.size() && keys[idx] < k)
        idx++;
    return idx;
}

void BNode::traverse() {
    int i;
    for (i = 0; i < keys.size(); i++) {
        if (!leaf)
            children[i]->traverse();
        cout << keys[i] << " ";
    }
    if (!leaf)
        children[i]->traverse();
}

BNode* BNode::search(int k) {
    int i = findKey(k);
    
    if (i < keys.size() && keys[i] == k)
        return this;
    
    if (leaf)
        return nullptr;
    
    return children[i]->search(k);
}

void BTree::insert(int k) {
    if (!root) {
        root = new BNode(t, true);
        root->keys.push_back(k);
    } else {
        if (root->keys.size() == 2 * t - 1) {
            BNode* s = new BNode(t, false);
            s->children.push_back(root);
            s->splitChild(0, root);
            
            int i = (s->keys[0] < k) ? 1 : 0;
            s->children[i]->insertNonFull(k);
            root = s;
        } else {
            root->insertNonFull(k);
        }
    }
}

void BNode::insertNonFull(int k) {
    int i = keys.size() - 1;
    
    if (leaf) {
        keys.push_back(0);
        while (i >= 0 && keys[i] > k) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = k;
    } else {
        i = findKey(k);
        
        if (children[i]->keys.size() == 2 * t - 1) {
            splitChild(i, children[i]);
            if (keys[i] < k)
                i++;
        }
        children[i]->insertNonFull(k);
    }
}

void BNode::splitChild(int i, BNode* y) {
    BNode* z = new BNode(y->t, y->leaf);
    
    z->keys.assign(y->keys.begin() + t, y->keys.end());
    
    if (!y->leaf)
        z->children.assign(y->children.begin() + t, y->children.end());
    
    keys.insert(keys.begin() + i, y->keys[t - 1]);
    children.insert(children.begin() + i + 1, z);
    
    y->keys.resize(t - 1);
    if (!y->leaf)
        y->children.resize(t);
}

void BTree::remove(int k) {
    if (!root) return;
    
    root->remove(k);
    
    if (root->keys.empty()) {
        BNode* tmp = root;
        root = root->leaf ? nullptr : root->children[0];
        delete tmp;
    }
}

void BNode::remove(int k) {
    int idx = findKey(k);
    
    if (idx < keys.size() && keys[idx] == k) {
        if (leaf)
            removeFromLeaf(idx);
        else
            removeFromNonLeaf(idx);
    } else {
        if (leaf) return;
        
        bool flag = (idx == keys.size());
        
        if (children[idx]->keys.size() < t)
            fill(idx);
        
        if (flag && idx > keys.size())
            children[idx - 1]->remove(k);
        else
            children[idx]->remove(k);
    }
}

void BNode::removeFromLeaf(int idx) {
    keys.erase(keys.begin() + idx);
}

void BNode::removeFromNonLeaf(int idx) {
    int k = keys[idx];
    
    if (children[idx]->keys.size() >= t) {
        int pred = getPred(idx);
        keys[idx] = pred;
        children[idx]->remove(pred);
    } else if (children[idx + 1]->keys.size() >= t) {
        int succ = getSucc(idx);
        keys[idx] = succ;
        children[idx + 1]->remove(succ);
    } else {
        merge(idx);
        children[idx]->remove(k);
    }
}

int BNode::getPred(int idx) {
    BNode* cur = children[idx];
    while (!cur->leaf)
        cur = cur->children.back();
    return cur->keys.back();
}

int BNode::getSucc(int idx) {
    BNode* cur = children[idx + 1];
    while (!cur->leaf)
        cur = cur->children[0];
    return cur->keys[0];
}

void BNode::fill(int idx) {
    if (idx != 0 && children[idx - 1]->keys.size() >= t)
        borrowFromPrev(idx);
    else if (idx != keys.size() && children[idx + 1]->keys.size() >= t)
        borrowFromNext(idx);
    else {
        if (idx != keys.size())
            merge(idx);
        else
            merge(idx - 1);
    }
}

void BNode::borrowFromPrev(int idx) {
    BNode* child = children[idx];
    BNode* sibling = children[idx - 1];
    
    child->keys.insert(child->keys.begin(), keys[idx - 1]);
    if (!child->leaf)
        child->children.insert(child->children.begin(), sibling->children.back());
    
    keys[idx - 1] = sibling->keys.back();
    sibling->keys.pop_back();
    if (!sibling->leaf)
        sibling->children.pop_back();
}

void BNode::borrowFromNext(int idx) {
    BNode* child = children[idx];
    BNode* sibling = children[idx + 1];
    
    child->keys.push_back(keys[idx]);
    if (!child->leaf)
        child->children.push_back(sibling->children[0]);
    
    keys[idx] = sibling->keys[0];
    sibling->keys.erase(sibling->keys.begin());
    if (!sibling->leaf)
        sibling->children.erase(sibling->children.begin());
}

void BNode::merge(int idx) {
    BNode* child = children[idx];
    BNode* sibling = children[idx + 1];
    
    child->keys.push_back(keys[idx]);
    child->keys.insert(child->keys.end(), sibling->keys.begin(), sibling->keys.end());
    
    if (!child->leaf)
        child->children.insert(child->children.end(), sibling->children.begin(), sibling->children.end());
    
    keys.erase(keys.begin() + idx);
    children.erase(children.begin() + idx + 1);
    
    delete sibling;
}

void BTree::display(BNode* node, int level) {
    if (node) {
        cout << "Level " << level << ": ";
        for (int key : node->keys)
            cout << key << " ";
        cout << endl;
        
        if (!node->leaf) {
            for (BNode* child : node->children)
                display(child, level + 1);
        }
    }
}

int main() {
    int t;
    cout << "Enter the minimum degree (t) of B-Tree: ";
    cin >> t;
    
    if (t < 2) {
        cout << "Minimum degree must be at least 2" << endl;
        return 0;
    }
    
    BTree btree(t);
    int choice, key;
    
    while (true) {
        cout << "\nB-TREE OPERATIONS (t=" << t << ")" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Search" << endl;
        cout << "4. Display Tree (Level-wise)" << endl;
        cout << "5. Inorder Traversal" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                btree.insert(key);
                cout << "Key " << key << " inserted successfully" << endl;
                break;
            
            case 2:
                if (btree.isEmpty()) {
                    cout << "Tree is empty" << endl;
                } else {
                    cout << "Enter key to delete: ";
                    cin >> key;
                    if (btree.search(key)) {
                        btree.remove(key);
                        cout << "Key " << key << " deleted successfully" << endl;
                    } else {
                        cout << "Key " << key << " not found" << endl;
                    }
                }
                break;
            
            case 3:
                if (btree.isEmpty()) {
                    cout << "Tree is empty" << endl;
                } else {
                    cout << "Enter key to search: ";
                    cin >> key;
                    cout << "Key " << key << (btree.search(key) ? " found" : " not found") << endl;
                }
                break;
            
            case 4:
                if (btree.isEmpty()) {
                    cout << "Tree is empty" << endl;
                } else {
                    cout << "\nB-Tree Structure:" << endl;
                    btree.displayTree();
                }
                break;
            
            case 5:
                if (btree.isEmpty()) {
                    cout << "Tree is empty" << endl;
                } else {
                    cout << "Inorder Traversal: ";
                    btree.traverse();
                    cout << endl;
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