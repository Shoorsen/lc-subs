class TimeMap {
public:
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> mp;

    TimeMap() {
    }
    

    int search(const string& key, const int& timestamp, const string& caller) {
        int l = 0;
        int r = mp[key].size()-1;        
        while (l <= r) {
            int mid = (l + r) / 2;
            int mid_ele = mp[key][mid].first;
            if (mid_ele == timestamp) {
                return mid;
            }
            else if (mid_ele > timestamp) {
                r = mid-1;
            }
            else {
                l = mid + 1;
            }
        }
        if (caller == "set") {
            return r+1;
        }
        else {
            return r;
        }
    }
    void set(string key, string value, int timestamp) {
        std::pair<int, std::string> tup = std::make_pair(timestamp, value);
        int insert_idx = search(key, timestamp, "set");
        auto it = mp[key].begin() + insert_idx;
        mp[key].insert(it, tup);
        // tups.push_back(tup);
    }
    
    string get(string key, int timestamp) {
        int get_idx = search(key, timestamp, "get");
        return get_idx >=0 && get_idx < mp[key].size() ? mp[key][get_idx].second : "";
        // return std::get<1>(tup);
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */