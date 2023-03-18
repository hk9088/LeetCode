#include<iostream>
#include<vector>
using namespace std;

class TrieNode{
public:
    char letter;
    vector<TrieNode> connectedNodes;
    bool endOfWord = false;
};

class Trie {
public:
    TrieNode root;
    Trie() {
        
    }
    
    void insert(string word) {
        TrieNode* currentNode = &root;
        for(int c=0;c<word.size();c++){
            bool flag = true;

    
            for(int i=0;i<currentNode->connectedNodes.size();i++){
                if(word[c] == currentNode->connectedNodes[i].letter){
                    currentNode = &currentNode->connectedNodes[i];
                    if(c == word.size() - 1){
                        currentNode->endOfWord = true;
                    }
                    flag = false;
                    break;
                }
            }
            
            if(flag){
                TrieNode newNode;
                newNode.letter = word[c];

                if(c == word.size() - 1){
                    newNode.endOfWord = true;
                }

                currentNode->connectedNodes.push_back(newNode);
                currentNode = &currentNode->connectedNodes[currentNode->connectedNodes.size()-1];
            }
        }
        
    }
    
    bool search(string word) {
        bool flag;
        TrieNode* currentNode = &root;
        for(int c=0;c<word.size();c++){
            flag = true;
            for(int i=0;i<currentNode->connectedNodes.size();i++){
                if(word[c] == currentNode->connectedNodes[i].letter){
                    currentNode = &currentNode->connectedNodes[i];
                    flag = false;
                    break;
                }
            }
            if(flag){
                return false;
            }

            if((c == word.size() - 1) && currentNode->endOfWord == false){
                return false;
            }
            
        }

        return true;
    }
    
    bool startsWith(string prefix) {
        bool flag;
        TrieNode* currentNode = &root;
        for(int c=0;c<prefix.size();c++){
            flag = true;
            for(int i=0;i<currentNode->connectedNodes.size();i++){
                if(prefix[c] == currentNode->connectedNodes[i].letter){
                    currentNode = &currentNode->connectedNodes[i];
                    flag = false;
                    break;
                }
            }
            if(flag){
                return false;
            }
        }

        return true;
        
    }
};

int main(){
    Trie* obj = new Trie();
    obj->insert("apple");
    bool param_2 = obj->search("apple");
    bool param_3 = obj->search("app");
    bool param_4 = obj->startsWith("app");
    obj->insert("app");
    bool param_5 = obj->search("app");
    obj->insert("xxlm");
    bool param_6 = obj->startsWith("xx");

    //cout<<param_6;
    cout<<param_2<<" "<<param_3<<" "<<param_4<<" "<<param_5;
}