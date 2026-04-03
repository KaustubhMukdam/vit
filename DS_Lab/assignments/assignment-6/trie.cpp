#include <iostream>
#include <string>
using namespace std;

// Each Trie node holds 26 children and an end-of-word flag
struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() { root = new TrieNode(); }

    // INSERT: O(L) where L = word length
    void insert(string word) {
        TrieNode* curr = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!curr->children[idx])
                curr->children[idx] = new TrieNode();
            curr = curr->children[idx];
        }
        curr->isEndOfWord = true;
    }

    // SEARCH: Returns true if exact word exists
    bool search(string word) {
        TrieNode* curr = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!curr->children[idx]) return false;
            curr = curr->children[idx];
        }
        return curr->isEndOfWord;
    }

    // PREFIX SEARCH: Returns true if any word starts with prefix
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char ch : prefix) {
            int idx = ch - 'a';
            if (!curr->children[idx]) return false;
            curr = curr->children[idx];
        }
        return true; // No end-of-word check!
    }

    // Helper: check if node has no children
    bool isEmpty(TrieNode* node) {
        for (int i = 0; i < 26; i++)
            if (node->children[i]) return false;
        return true;
    }

    // DELETE (Recursive helper)
    TrieNode* deleteHelper(TrieNode* curr, string word, int depth) {
        if (!curr) return nullptr;
        if (depth == word.size()) {
            curr->isEndOfWord = false;       // Unmark end
            if (isEmpty(curr)) {             // Safe to delete leaf
                delete curr;
                return nullptr;
            }
            return curr;
        }
        int idx = word[depth] - 'a';
        curr->children[idx] = deleteHelper(curr->children[idx], word, depth + 1);
        if (isEmpty(curr) && !curr->isEndOfWord) {
            delete curr;
            return nullptr;
        }
        return curr;
    }

    void deleteWord(string word) {
        root = deleteHelper(root, word, 0);
        cout << "Deleted: " << word << endl;
    }
};

int main() {
    Trie t;

    // Insert words
    t.insert("cat");
    t.insert("car");
    t.insert("can");
    t.insert("bat");

    // Search
    cout << "Search 'cat':  " << (t.search("cat")    ? "Found" : "Not Found") << endl;
    cout << "Search 'cab':  " << (t.search("cab")    ? "Found" : "Not Found") << endl;

    // Prefix Search
    cout << "Prefix 'ca':   " << (t.startsWith("ca") ? "Exists" : "No")      << endl;
    cout << "Prefix 'do':   " << (t.startsWith("do") ? "Exists" : "No")      << endl;

    // Delete
    t.deleteWord("cat");
    cout << "After delete, search 'cat': " << (t.search("cat") ? "Found" : "Not Found") << endl;
    cout << "After delete, search 'car': " << (t.search("car") ? "Found" : "Not Found") << endl;

    return 0;
}
