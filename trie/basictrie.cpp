#include<bits/stdc++.h>
using namespace std;

#define hashmap unordered_map<char,node*>

// class node{
//     public:
//       char data;
//       hashmap h;
//       bool isend;

//       node(char d){
//           data = d;
//           isend = false;
//       }
// };

// class Trie{
//       node* root;

//     public:
//        Trie(){
//            root = new node('\0');
//        }
//        //Insertion
//        void addword(char* word){

//            node* temp = root;
//            for(int i=0;word[i]!='\0';i++){

//                char ch = word[i];

//                if(temp->h.count(ch) == 0){
//                    node* child = new node(ch);
//                    temp->h[ch] = child;
//                    temp = child;
//                }
//                else{
//                    temp = temp->h[ch];
//                }
//            }
//            temp->isend = true;
//        }
//        //lookup
//        bool search(char* word){
//            node* temp = root;

//            for(int i=0;word[i]!='\0';i++){
//                 char ch = word[i];

//                 if(temp->h.count(ch)){
//                     temp = temp->h[ch];
//                 }
//                 else{
//                     return false;
//                 }
//            }
//            return temp->isend;
//        }
// };

const int ALPHABET_SIZE = 26; 

struct TrieNode 
{ 
	struct TrieNode *children[ALPHABET_SIZE]; 
	bool isEndOfWord; 
}; 

struct TrieNode *getNode(void) 
{ 
	struct TrieNode *pNode = new TrieNode; 

	pNode->isEndOfWord = false; 

	for (int i = 0; i < ALPHABET_SIZE; i++) 
		pNode->children[i] = NULL; 

	return pNode; 
} 


void insert(struct TrieNode *root, string key) 
{ 
	struct TrieNode *pCrawl = root; 

	for (int i = 0; i < key.length(); i++) 
	{ 
		int index = key[i] - 'a'; 
		if (!pCrawl->children[index]) 
			pCrawl->children[index] = getNode(); 

		pCrawl = pCrawl->children[index]; 
	} 

	pCrawl->isEndOfWord = true; 
} 


bool search(struct TrieNode *root, string key) 
{ 
	struct TrieNode *pCrawl = root; 

	for (int i = 0; i < key.length(); i++) 
	{ 
		int index = key[i] - 'a'; 
		if (!pCrawl->children[index]) 
			return false; 

		pCrawl = pCrawl->children[index]; 
	} 

	return (pCrawl != NULL && pCrawl->isEndOfWord); 
} 

 
bool isEmpty(TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return false;
    return true;
}
 

TrieNode* remove(TrieNode* root, string key, int depth = 0)
{
    if (!root)
        return NULL;
 
    if (depth == key.size()) {

        if (root->isEndOfWord)
            root->isEndOfWord = false;
 
        if (isEmpty(root)) {
            delete (root);
            root = NULL;
        }
 
        return root;
    }
 
    int index = key[depth] - 'a';
    root->children[index] = 
          remove(root->children[index], key, depth + 1);
 
    if (isEmpty(root) && root->isEndOfWord == false) {
        delete (root);
        root = NULL;
    }
 
    return root;
}

//given a word print all words ass with it as a child.
//i.e; if enter ab , we should see ab,abc,abcd,... if available in trie
bool isLastNode(struct TrieNode* root) 
{ 
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        if (root->children[i]) 
            return 0; 
    return 1; 
} 

void suggestionsRec(struct TrieNode* root, string currPrefix) 
{ 
   
    if (root->isEndOfWord) 
    { 
        cout << currPrefix; 
        cout << endl; 
    } 
  
    if (isLastNode(root)) 
        return; 
  
    for (int i = 0; i < ALPHABET_SIZE; i++) 
    { 
        if (root->children[i]) 
        { 
            currPrefix.push_back(97 + i); 
  

            suggestionsRec(root->children[i], currPrefix); 

            currPrefix.pop_back(); 
        } 
    } 
} 

int printAutoSuggestions(TrieNode* root, const string query) 
{ 
    struct TrieNode* pCrawl = root; 
  

    int level; 
    int n = query.length(); 
    for (level = 0; level < n; level++) 
    { 
        int index = ((int)query[level] - (int)'a'); 
  
        if (!pCrawl->children[index]) 
            return 0; 
  
        pCrawl = pCrawl->children[index]; 
    } 

    bool isWord = (pCrawl->isEndOfWord == true); 
  
    bool isLast = isLastNode(pCrawl); 

    if (isWord && isLast) 
    { 
        cout << query << endl; 
        return -1; 
    } 
  
    if (!isLast) 
    { 
        string prefix = query; 
        suggestionsRec(pCrawl, prefix); 
        return 1; 
    } 
} 



int main() {
     char word[10][100] = {"apple","ape","coder","coding","app","code"};

    struct TrieNode *root = getNode(); 

     for(int i=0;i<6;i++){
         insert(root, word[i]);
     }

      cout<<"wanna remove something";
     char removeword[100];
     cin.getline(removeword,100);

     remove(root,removeword);


     char searchword[100];
     cin.getline(searchword,100);

     if(search(root,searchword)){
         cout<<searchword<<" found "<<'\n';
     }
     else{
         cout<<"not found!"<<'\n';
     }

     char searchsugg[100];
     cin.getline(searchsugg,100);

     int sd = printAutoSuggestions(root,searchsugg);
     if(sd == -1){
         cout<<"chill"; 
     }
     else if(sd == 0){
       cout<<"hill";
     }
    
    return 0;
}