class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        isword = false;
        for(int i = 0; i < 26; i++)
        {
            next[i] = NULL;
        }
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        WordDictionary* temp = this;
        for(int i = 0; i < word.length(); i++)
        {
            if(temp->next[word[i]-97] == NULL)
                temp->next[word[i]-97] = new WordDictionary();
            temp = temp->next[word[i]-97];
        }
        temp->isword = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        int len = word.length();
        return searchword(word, len, 0, this);
    }
    
    bool searchword(string& word, int len, int start, WordDictionary* root)
    {
        if(root == NULL)
            return false;
        if(start == len-1)
        {
            if(word[start] == '.')
            {
                for(int i = 0; i < 26; i++)
                {
                    if(root->next[i] != NULL && root->next[i]->isword)
                        return true;
                }
                return false;
            }
            else
            {
                if(root->next[word[start] - 97] != NULL && root->next[word[start] - 97]->isword)
                    return true;
                else
                    return false;
            }
        }
        else
        {
            if(word[start] == '.')
            {
                for(int i = 0; i < 26; i++)
                {
                    if(searchword(word, len, start+1, root->next[i]))
                        return true;
                }
                return false;
            }
            else
            {
                if(searchword(word, len, start+1, root->next[word[start] - 97]))
                    return true;
                return false;
            }
        }
    }
private:
    WordDictionary* next[26];
    bool isword;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */