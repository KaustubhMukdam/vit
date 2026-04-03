#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define MAX_CHAR 256

struct SuffixTrieNode {
    SuffixTrieNode* children[MAX_CHAR];
    vector<int> indexes;   // Stores position of each char in original text

    SuffixTrieNode() {
        for (int i = 0; i < MAX_CHAR; i++)
            children[i] = nullptr;
    }

    // Recursively insert a suffix starting at 'index'
    void insertSuffix(const string& s, int index) {
        indexes.push_back(index);          // Store position at every visited node
        if (!s.empty()) {
            int cIdx = (unsigned char)s[0];
            if (!children[cIdx])
                children[cIdx] = new SuffixTrieNode();
            children[cIdx]->insertSuffix(s.substr(1), index + 1);
        }
    }

    // Returns pointer to node where pattern ends, or nullptr if not found
    SuffixTrieNode* search(const string& pat) {
        if (pat.empty()) return this;
        int cIdx = (unsigned char)pat[0];
        if (children[cIdx])
            return children[cIdx]->search(pat.substr(1));
        return nullptr;
    }
};

class SuffixTrie {
    SuffixTrieNode* root;
    string text;

public:
    SuffixTrie(const string& txt) : text(txt) {
        root = new SuffixTrieNode();
        // Insert every suffix of the text
        for (int i = 0; i < (int)txt.size(); i++)
            root->insertSuffix(txt.substr(i), i);
    }

    // Search and print all positions of pattern in text
    void searchPattern(const string& pat) {
        SuffixTrieNode* result = root->search(pat);

        if (!result) {
            cout << "Pattern \"" << pat << "\" NOT FOUND in text.\n";
            return;
        }

        int patLen = pat.size();
        cout << "Pattern \"" << pat << "\" found at position(s): ";
        for (int idx : result->indexes)
            cout << (idx - patLen) << " ";
        cout << "\n";
    }
};

int main() {
    string text = "banana";
    cout << "Text: \"" << text << "\"\n";

    SuffixTrie st(text);

    st.searchPattern("ana");        
    st.searchPattern("nan");       
    st.searchPattern("banana");   
    st.searchPattern("xyz");        

    return 0;
}
