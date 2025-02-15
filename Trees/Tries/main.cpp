#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

class Trie
{
private:
    TrieNode *root;

    void printHelper(TrieNode *node, string prefix)
    {
        if (node->isEndOfWord)
        {
            cout << prefix << endl;
        }
        for (auto &pair : node->children)
        {
            printHelper(pair.second, prefix + pair.first);
        }
    }

    bool deleteHelper(TrieNode *current, const string &word, int index)
    {
        if (index == word.length())
        {
            if (!current->isEndOfWord)
            {
                return false;
            }
            current->isEndOfWord = false;
            return current->children.empty();
        }

        char ch = word[index];
        if (current->children.find(ch) == current->children.end())
        {
            return false;
        }

        bool shouldDeleteNode = deleteHelper(current->children[ch], word, index + 1);

        if (shouldDeleteNode)
        {
            delete current->children[ch];
            current->children.erase(ch);
            return current->children.empty() && !current->isEndOfWord;
        }

        return false;
    }

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(const string &word)
    {
        TrieNode *current = root;
        for (char ch : word)
        {
            if (current->children.find(ch) == current->children.end())
            {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }
        current->isEndOfWord = true;
    }

    bool search(const string &word)
    {
        TrieNode *current = root;
        for (char ch : word)
        {
            if (current->children.find(ch) == current->children.end())
            {
                return false;
            }
            current = current->children[ch];
        }
        return current->isEndOfWord;
    }

    bool deleteWord(const string &word)
    {
        return deleteHelper(root, word, 0);
    }

    void print()
    {
        printHelper(root, "");
    }
};

int main()
{
    Trie trie;

    trie.insert("apple");
    trie.insert("app");
    trie.insert("banana");
    trie.insert("bat");
    trie.insert("ball");

    cout << "All words in the Trie:" << endl;
    trie.print();

    cout << "Search 'apple': " << (trie.search("apple") ? "Found" : "Not Found") << endl;
    cout << "Search 'app': " << (trie.search("app") ? "Found" : "Not Found") << endl;
    cout << "Search 'appl': " << (trie.search("appl") ? "Found" : "Not Found") << endl;

    cout << "Delete 'app': " << (trie.deleteWord("app") ? "Deleted" : "Not Found") << endl;
    cout << "Search 'app' after deletion: " << (trie.search("app") ? "Found" : "Not Found") << endl;

    cout << "All words in the Trie after deletion:" << endl;
    trie.print();

    return 0;
}