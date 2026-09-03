class MyHashMap {
public:
    vector<list<pair<int,int>>> bucket;
    MyHashMap() {
        bucket.resize(1000);
    }
    
    void put(int key, int value) {
        bool found = false;
        int index = key % 1000;
        for(auto &p : bucket[index]){
            if(p.first == key){
            p.second = value;
            found = true;
            break;
            }
        }
        if(!found){
            bucket[index].push_back({key,value});
        }
    }
    
    int get(int key) {
        int index = key % 1000;
        for(auto &p : bucket[index]){
            if(p.first == key){
                return p.second;
            }
        }
         return -1;
    }
    
    void remove(int key) {
        int index = key % 1000;
        for (auto it = bucket[index].begin(); it != bucket[index].end(); it++){
            if(it -> first == key){
                bucket[index].erase(it);
                break;
            }
        } 
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */