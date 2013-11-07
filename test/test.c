#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <queue>
using namespace std;


struct TrieNode{
public:
	vector<TrieNode*> child;
	TrieNode(){
		child = vector<TrieNode*>(26, NULL);
	}
};

void insert(string s, TrieNode* root){
	int index = 0;
	int n = s.size();
	while(index < n){
		if(root->child[s[index] - 'a']){
			root = root->child[s[index++] - 'a'];
		}
		else{
			TrieNode *t = new TrieNode;
			root->child[s[index++]- 'a'] = t;
			root = t;
		}
	}
}

bool find(string s, TrieNode* root){
	int index = 0;
	int n = s.size();
	while(index < n){
		if(root->child[s[index] - 'a']){
			root = root->child[s[index++] - 'a'];
		}
		else{
			return false;
		}
	}
	return true;
}
int main(){
	TrieNode *root = new TrieNode;
	insert("abc", root);
	insert("def", root);
	insert("abd", root);
	insert("ded", root);
	if(find("abc", root))
		printf("abc found\n");
	else
		printf("abc not found\n");
	if(find("deg", root))
		printf("deg found\n");
	else
		printf("deg not found\n");
	return 0;
	

}

