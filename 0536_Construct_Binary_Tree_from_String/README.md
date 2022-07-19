### 536.Construct Binary Tree from String

Both iterative and recursive methods have time complexity of O(N) and space complexity of O(H), where N is the length of the string s and H is the height of the tree.

#### 1.Iterative method(35-56ms)

```c++
TreeNode* str2tree(string s) {
  stack<TreeNode*> A;
  int i = 0;
  while(i < s.length()){
    if(s[i] == '('){
      ++i;
    }else if(s[i] == ')'){
      A.pop();
      ++i;
    }else{
      int nextI = s.find_first_of("()", i+1);
      int x = stoi(s.substr(i, nextI-i));
      TreeNode* newNode = new TreeNode(x);
      if(!A.empty()){
        if(A.top()->left == nullptr){
          A.top()->left = newNode;
        }else{
          A.top()->right = newNode;
        }
      }
      A.emplace(newNode);
      i = nextI;
    }
  }
  return A.empty()? nullptr : A.top();
}
```

#### 2.Recursive method(36-56ms)

```c++
int getInteger(string &s, int &i){
  int nextI = s.find_first_of("()", i+1);
  int x = stoi(s.substr(i, nextI-i));
  i = nextI == -1? s.length() : nextI;
  return x;
}
TreeNode* dfs(string &s, int &i){
  int x = getInteger(s, i);
  TreeNode* root = new TreeNode(x);
  if(i == s.length()){
    return root;
  }
  if(s[i] == '('){
    root->left = dfs(s, ++i);        
  }  
  if(root->left != nullptr && s[i] == '('){
    root->right = dfs(s, ++i);
  }
  if(i < s.length() && s[i] == ')'){
    ++i;
  }
  return root;
}
TreeNode* str2tree(string s){
  if(s.empty()){
    return nullptr;
  }
  int i = 0;
  return dfs(s, i);
}
```

