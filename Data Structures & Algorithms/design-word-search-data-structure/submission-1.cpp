class Node{
public:
    unordered_map<char, Node*> children;
    bool last = false;
};

class WordDictionary {
private:
    Node* root_;
public:
    WordDictionary() {
        root_ = new Node();
    }
    
    void addWord(string word) {
        Node* root = root_;
        for(auto c:word){
            if(!root->children.contains(c))
                root->children[c] = new Node();
            root = root->children[c];
        }
        root->last = true;
    }
    
    bool search(string word) {
        Node* root = root_;

        return search(0, root, word);
    }

    bool search(int x, Node* root, string word){
        bool find = false;
        if(x == word.size()) return root->last;
        if(word[x] == '.'){
            for(auto a:root->children){
                find |= search(x+1, a.second, word);
            }
        }
        else {
            if(!root->children.contains(word[x])) return false;
            find |= search(x+1, root->children[word[x]], word);
        }

        return find;
    }
};
