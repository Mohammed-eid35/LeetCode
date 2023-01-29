class LFUCache {
    int capacity, minFreq;

    struct Element {
        int value, fr;
        list<int>::iterator it;
    };

    unordered_map<int, Element> cache;
    unordered_map<int, list<int> > freq;

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (!cache.count(key)) return -1;
        
        freq[cache[key].fr].erase(cache[key].it);

        cache[key].fr++;
        freq[cache[key].fr].push_back(key);
        cache[key].it = prev(freq[ cache[key].fr].end());

        minFreq += freq[minFreq].empty();

        return cache[key].value;
    }

    void put(int key, int value) {
        if (!capacity) return;

        if (get(key) != -1) {
            cache[key].value = value;
            return;
        }

        if (cache.size() == capacity){
            cache.erase(freq[minFreq].front());
            freq[minFreq].pop_front();
        }

        freq[1].push_back(key);
        cache[key] = {value, 1, prev(freq[1].end())};
        minFreq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
