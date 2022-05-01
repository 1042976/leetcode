class FileSystem {
public:
    class Node{
    public:
        bool isFile;
        map<string, Node*> next;
        string content;
        Node():isFile(false){}
        Node(bool _isFile): isFile(_isFile){}
        ~Node(){
            auto it = next.begin();
            while(it != next.end()){
                delete it->second;
                ++it;
            }
        }
    };
    
    Node* root;
    FileSystem():root(new Node()) {}
    
    ~FileSystem(){
        delete root;
    }
    
    //T-O(l+m)
    vector<string> ls(string path) {
        Node* node = getNode(path);
        if(!node->isFile){
            return printDicOrFileName(node);
        }else{
            size_t lastSlashIdx = path.find_last_of('/');
            string fileName = path.substr(lastSlashIdx+1);
            return vector<string>(1, fileName);
        }
    }
    
    //T-O(l)
    void mkdir(string path) {
        path.append("/");
        int l = 1, r = 1;
        Node* node = root;
        while(r < path.length()){
            r = path.find('/', r);
            string dicName = path.substr(l, r-l);
            if(node->next.count(dicName) == 0){
                node->next[dicName] = new Node();
            }
            node = node->next[dicName];
            ++r;
            l = r;
        }
    }
    
    //T-O(l+m)
    void addContentToFile(string filePath, string content) {
        size_t lastSlashIdx = filePath.find_last_of('/');
        string dicPath = filePath.substr(0, lastSlashIdx);
        string fileName = filePath.substr(lastSlashIdx+1);
        Node* node = getNode(dicPath);
        if(node->next.count(fileName) == 0){
            Node* fileNode = new Node(true);
            fileNode->content = content;
            node->next[fileName] = fileNode;
        }else{
            node->next[fileName]->content.append(content);
        }
    }
    
    //T-O(l)
    string readContentFromFile(string filePath) {
        Node* node = getNode(filePath);
        return node->content;
    }
    
    vector<string> printDicOrFileName(Node* node){
        vector<string> res;
        auto it = node->next.begin();
        while(it != node->next.end()){
            res.emplace_back(it->first);
            ++it;
        }
        return res;
    }
    
    Node* getNode(string path){
        if(path.back() == '/'){
            return root;
        }
        path.append("/");
        int l = 1, r = 1;
        Node* node = root;
        while(r < path.length()){
            r = path.find('/', r);
            string dicOrFileName = path.substr(l, r-l);
            node = node->next[dicOrFileName];
            ++r;
            l = r;
        }
        return node;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
