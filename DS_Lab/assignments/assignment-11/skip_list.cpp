#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

// Node Structure
struct Node {
    int value;
    vector<Node*> forward;

    Node(int val, int level) {
        value = val;
        // Allocate space for pointers at each level
        forward.assign(level + 1, nullptr);
    }
};

class SkipList {
    int MAX_LEVEL;
    float P;
    int current_level;
    Node* head;

public:
    SkipList(int max_lvl, float p) {
        MAX_LEVEL = max_lvl;
        P = p;
        current_level = 0;
        head = new Node(-1, MAX_LEVEL); // Sentinel Head
    }

    // Probabilistic Coin Flip
    int randomLevel() {
        float r = (float)rand() / RAND_MAX;
        int lvl = 0;
        while (r < P && lvl < MAX_LEVEL) {
            lvl++;
            r = (float)rand() / RAND_MAX;
        }
        return lvl;
    }

    void insertElement(int value) {
        Node* current = head;
        vector<Node*> update(MAX_LEVEL + 1, nullptr);

        // Find position
        for (int i = current_level; i >= 0; i--) {
            while (current->forward[i] != nullptr && current->forward[i]->value < value) {
                current = current->forward[i];
            }
            update[i] = current;
        }

        current = current->forward[0];

        // Insert if it does not exist
        if (current == nullptr || current->value != value) {
            int rLevel = randomLevel();

            if (rLevel > current_level) {
                for (int i = current_level + 1; i <= rLevel; i++)
                    update[i] = head;
                current_level = rLevel;
            }

            Node* n = new Node(value, rLevel);

            // Rewire pointers
            for (int i = 0; i <= rLevel; i++) {
                n->forward[i] = update[i]->forward[i];
                update[i]->forward[i] = n;
            }
            cout << "Inserted: " << value << "\n";
        }
    }

    void deleteElement(int value) {
        Node* current = head;
        vector<Node*> update(MAX_LEVEL + 1, nullptr);

        for (int i = current_level; i >= 0; i--) {
            while (current->forward[i] != nullptr && current->forward[i]->value < value)
                current = current->forward[i];
            update[i] = current;
        }

        current = current->forward[0];

        if (current != nullptr && current->value == value) {
            // Bypass pointers
            for (int i = 0; i <= current_level; i++) {
                if (update[i]->forward[i] != current) break;
                update[i]->forward[i] = current->forward[i];
            }

            // Reduce height of Skip List if top levels are empty
            while (current_level > 0 && head->forward[current_level] == nullptr)
                current_level--;
            
            cout << "Deleted: " << value << "\n";
            delete current;
        }
    }

    void searchElement(int value) {
        Node* current = head;
        for (int i = current_level; i >= 0; i--) {
            while (current->forward[i] != nullptr && current->forward[i]->value < value)
                current = current->forward[i];
        }
        current = current->forward[0];

        if (current != nullptr && current->value == value)
            cout << "Search " << value << " : Found\n";
        else
            cout << "Search " << value << " : Not Found\n";
    }

    void display() {
        cout << "\n--- Skip List ---\n";
        for (int i = current_level; i >= 0; i--) {
            Node* node = head->forward[i];
            cout << "Level " << i << ": ";
            while (node != nullptr) {
                cout << node->value << " ";
                node = node->forward[i];
            }
            cout << "\n";
        }
        cout << "-----------------\n\n";
    }
};

int main() {
    srand(time(0));
    SkipList sl(3, 0.5);

    sl.insertElement(3);
    sl.insertElement(6);
    sl.insertElement(7);
    sl.insertElement(9);
    sl.insertElement(12);

    sl.display();

    sl.searchElement(7);
    sl.searchElement(15);

    sl.deleteElement(7);
    sl.display();

    return 0;
}