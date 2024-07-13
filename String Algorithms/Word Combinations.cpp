/*
Problem Name: Word Combinations
Problem Link: https://cses.fi/problemset/task/1731/
Idea:
Complexity:
Resource: https://github.com/ignite312/CpStuff/blob/main/String/Trie.cpp
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 100001;
const int M = 1e9 + 7;
int dp[N];

struct TrieNode {
  TrieNode* child[26];
  bool isLeafNode;

  TrieNode() {
    isLeafNode = false;
    for (int i = 0; i < 26; i++)child[i] = NULL;
  }
};
void addWord(TrieNode* root, string& word, int idx) {
  if (idx == (int)word.length()) {
    root->isLeafNode = true;
    return;
  }
  int ch = word[idx] - 'a';
  if (root->child[ch] == NULL) {
    TrieNode* newNode = new TrieNode();
    root->child[ch] = newNode;
  }
  addWord(root->child[ch], word, idx + 1);
}
ll search(TrieNode *root, int idx, string &key) {
  TrieNode* current = root;
  ll total = 0;
  for (int i = idx; i < (int)key.size(); i++) {
    if (current->child[key[i]-'a'] == NULL)
      break;
    current = current->child[key[i]-'a'];
    if(current->isLeafNode != false) {
      total = (total + dp[i+1]) % M;
    }
  }
  return total;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  tt = 1;
  // cin >> tt;
  while (tt--) {
    TrieNode* root = new TrieNode();
    string s;
    cin >> s;
    int sz = (int)s.size();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      string a;
      cin >> a;
      addWord(root, a, 0);
    }
    dp[sz] = 1;
    for(int i = sz-1; i >= 0; i--) {
      dp[i] = search(root, i, s);
    }
    cout << dp[0] << "\n";
  }
  return 0;
}
