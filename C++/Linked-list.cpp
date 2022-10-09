#include<iostream>
#include<string>
#include<vector>

using std::cout; using std::cin;
using std::endl; using std::string;
using std::vector; using std::pair;

struct Node {
    struct Node *next{};
    string city;
    string country;
    int key{};
};

struct Node *addNewNode(struct Node *node, int key, string &city, string &country) {
    node->next = new Node;
    node->next->key = key;
    node->next->city = city;
    node->next->country = country;
    return node;
}

void freeNodes(struct Node *node) {
    struct Node *tmp = nullptr;
    while (node) {
        tmp = node;
        node = node->next;
        delete tmp;
    }
}

void printNodeData(struct Node *node) {
    cout << "key: " << node->key << endl
        << "city: " << node->city << endl
        << "county: " << node->country << endl << endl;
}

int main() {
    struct Node *tmp, *root;
    struct Node *end = nullptr;

    vector<pair<string, string>> list = {{"Tokyo",  "Japan"},
                              {"New York",  "United States"},
                              {"Mexico City",  "Mexico"},
                              {"Tangshan",  "China"},
                              {"Tainan",  "Taiwan"}};

    root = new Node;
    tmp = root;
    for (int i = 0; i < list.size(); ++i) {
        tmp = addNewNode(tmp, i+1, list[i].first, list[i].second);
        tmp = tmp->next;
    }

    tmp = root->next;
    for (const auto &item : list) {
        printNodeData(tmp);
        tmp = tmp->next;
    }

    freeNodes(root->next);
    delete root;

    return EXIT_SUCCESS;
}
