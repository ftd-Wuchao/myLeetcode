class Trie {
private:
	bool end;
	vector<Trie*> next;

public:
    Trie() {
        end = false;
		next.resize(26, NULL);
	}
	void insert(string word) {
		Trie* node = this;
		for (char c : word) {
			if (node->next[c - 'a'] == NULL) node->next[c - 'a'] = new Trie();
			node = node->next[c - 'a'];
		}
        node->end = true;
	}
	bool search(string word, int start) {
        Trie* node = this;
        for(int i=start; i<word.size(); i++){
            if(word[i]=='.'){
                for(int j=0; j<26; j++){
                    if(node->next[j]!=NULL){

                        if(node->next[j]->search(word, i+1)) 
                            return true;   
                    }
                    
                } 
                return false;
            }else{
                if (node->next[word[i] - 'a'] == NULL) return false;
                node = node->next[word[i] - 'a'];
            }
        }
		return node->end;
	}
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        head = new Trie();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        head->insert(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return head->search(word, 0);
    }
private:
    Trie* head;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */