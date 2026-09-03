class MyHashSet {
public:
    vector<list<int>> bucket;
    MyHashSet() {
        bucket.resize(1000);
    }
    
    void add(int key) {
        int index = key % 1000;
        auto it = find(bucket[index].begin(),bucket[index].end(),key);
            if(it  == bucket[index].end()){
                bucket[index].push_back(key);
            }
    }
    
    void remove(int key) {
        int index = key % 1000;
        for (auto it = bucket[index].begin(); it != bucket[index].end(); it++){
            if(*it == key){
                bucket[index].erase(it);
                break;
            }
        } 
    }
    
    bool contains(int key) {
    int index = key % 1000;
    for (auto it = bucket[index].begin(); it != bucket[index].end(); it++){
        if(*it == key){
            return true;
        }
    }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */