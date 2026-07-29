class Node{
public:
    unordered_map<char, Node*> children;
    bool last = false;
};

class PrefixTree {
    Node* root_;
public:
    PrefixTree() {
        root_ = new Node();
    }
    
    void insert(string word) {
        Node* root = root_;
        for(auto c:word){
            if(!root->children.contains(c)){
                root->children[c] = new Node();
            }
            root = root->children[c];
        }
        root->last = true;
    }
    
    bool search(string word) {
        Node* root = root_;

        for(int i=0;i<word.size();i++){
            if(!root->children.contains(word[i])) return false;
            if(i == word.size()-1 && root->children[word[i]]->last == false) return false;
            
            root = root->children[word[i]];
        }

        return true;
    }
    
    bool startsWith(string prefix) {
        Node* root = root_;

        for(int i=0;i<prefix.size();i++){
            if(!root->children.contains(prefix[i])) return false;
            root = root->children[prefix[i]];
        }

        return true;
    }
};
