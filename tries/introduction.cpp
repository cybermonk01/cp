#include <bits/stdc++.h>

using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    TrieNode(char ch)
    {

        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode *root, string word)
    {

        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // we assume word will be in caps
        int index = word[0] - 'A';
        TrieNode *child;

        // present

        if (root->children[index] != NULL)
        { // agar present hai to child ko move kro root ke children pe
            child = root->children[index];
        }
        else
        {

            child = new TrieNode(word[0]); // naya child banao aur root ke children me daal do
            root->children[index] = child;
        }

        // recursion

        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode *root, string word)
    {

        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            // present

            child = root->children[index];
        }
        else
        {

            // absent
            return false;
        }

        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }

    void removeUtil(TrieNode *root, string word)
    {

        if (word.length() == 0)
        {

            root->isTerminal = false;
            return;
        }

        int index = word[0] - 'A';
        TrieNode *child;

        if (root->children[index] != nullptr)
        {
            child = root->children[index];

            removeUtil(child, word.substr(1));

            if (child->isTerminal == false && allChildrenNull(child))
            {
                delete child;
                root->children[index] = nullptr;
            }
        }
    }

    bool allChildrenNull(TrieNode *node)
    {
        for (int i = 0; i < 26; i++)
        {
            if (node->children[i] != nullptr)
            {
                return false;
            }
        }
        return true;
    }
    void removeWord(string word)
    {
        removeUtil(root, word);
    }
};

int main()
{

    Trie *t = new Trie();

    t->insertWord("ABCD");
    t->insertWord("DP");
    t->insertWord("TIME");

    cout << "present or not " << t->searchWord("ABCD") << endl;
    cout << "present or not " << t->searchWord("DP") << endl;

    cout << "deleted word ";
    t->removeWord("DP");
    cout << "present or not " << t->searchWord("DP") << endl;
}