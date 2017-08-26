class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        isword = false;
        for(int i = 0; i < 26; i++)
        {
            next[i] = NULL;
        }
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* temp = this;
        for(int i = 0; i < word.length(); i++)
        {
            if(temp->next[word[i]-97] == NULL)
            {
                Trie* node = new Trie();
                temp->next[word[i]-97] = node;
            }
            temp = temp->next[word[i]-97];
        }
        temp->isword = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* temp = this;
        for(int i = 0; i < word.length(); i++)
        {
            if(temp->next[word[i]-97] == NULL)
                return false;
            temp = temp->next[word[i]-97];
        }
        return temp->isword;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* temp = this;
        for(int i = 0; i < prefix.length(); i++)
        {
            if(temp->next[prefix[i]-97] == NULL)
                return false;
            temp = temp->next[prefix[i]-97];
        }
        return true;
    }
private:
    Trie* next[26];
    bool isword;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */