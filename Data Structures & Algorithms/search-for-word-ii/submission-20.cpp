class Node{
public:
    unordered_map<char, Node*> children;
    bool last = false;
    int idx;
};

class Trie{
public:
    Node* root_;

    Trie(vector<string>& words){
        root_ = new Node();
        for(int i=0;i<words.size(); i++) this->add(words[i], i);
    }

    void add(string s, int i){
        Node* root = root_;

        for(auto c:s){
            if(!root->children.contains(c))
                root->children[c] = new Node();
            
            root= root->children[c];
        }

        root->last = true;
        root->idx = i;
    }
};

class Solution {
public:

    void dfs(int i, int j, Node* root, vector<vector<char>>& board, vector<vector<bool>>& visited, string& word, vector<string>& output){
        if(root == nullptr 
        || i < 0 
        || i >= board.size() 
        || j < 0 
        || j >= board[0].size() 
        || !root->children.contains(board[i][j])
        || visited[i][j]
        ) return;

        word += board[i][j];
        if(root->children[board[i][j]]->last) {
            output.push_back(word);
            root->children[board[i][j]]->last = false;
        }
        
        visited[i][j] = true;
        dfs(i+1, j, root->children[board[i][j]], board, visited, word, output);
        dfs(i, j+1, root->children[board[i][j]], board, visited, word, output);
        dfs(i-1, j, root->children[board[i][j]], board, visited, word, output);
        dfs(i, j-1, root->children[board[i][j]], board, visited, word, output);
        visited[i][j] = false;
        word.pop_back();
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* t = new Trie(words);
        set<int> indexes;
        vector<string> output;
        string word = "";
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for(int i=0; i<board.size(); i++)
            for(int j=0; j<board[0].size(); j++){
                
                if(t->root_->children.contains(board[i][j])) dfs(i, j, t->root_, board, visited, word, output);
            }
        
        return output;
    }
};
