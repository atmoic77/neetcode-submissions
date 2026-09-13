class LRUCache {
public:
    class Node {
        public:
        int key , val;
        Node* prev;
        Node* next;
        Node(int k,int v){
            key = k;
            val = v;
            prev = next = NULL;
        }
    };
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    unordered_map<int, Node*> map;
    int limit;  
    void addNode(Node* newNode){
        Node* oldNext = head -> next;
        head -> next = newNode;
        oldNext -> prev = newNode;

        newNode -> next = oldNext;
        newNode -> prev = head;
    }
    void delNode(Node* oldNode) {
        Node* oldPrev = oldNode -> prev;
        Node* oldNext = oldNode -> next;

        oldPrev -> next = oldNext;
        oldNext -> prev = oldPrev;
    }
    LRUCache(int capacity) {
        limit = capacity;
        head -> next = tail;
        tail-> prev = head;
    }
    
    int get(int key) {
        if(map.find(key) == map.end()){ 
            return -1;
        }
        int ans = map[key] -> val;
        Node* ansnode =  map[key];
        map.erase(key);
        delNode(ansnode);
        addNode(ansnode);
        map[key] = ansnode;
        return ans;
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end()){
           Node* oldNode = map[key];
           delNode(oldNode);
           map.erase(key); 
        }
        if(map.size() == limit){
            //delete lru data
            map.erase(tail -> prev -> key);   
            delNode(tail -> prev);
        }
        Node* newNode = new Node(key,value); 
        addNode(newNode);
        map[key] = newNode;
    }
};