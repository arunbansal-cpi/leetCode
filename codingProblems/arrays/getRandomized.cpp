#include<iostream>
#include<map>
#include<list>
using namespace std;
class RandomizedSet {
public:
    map<int, int> randomMap;

    RandomizedSet() {
      
    }
    
    bool insert(int val) {
        pair<map<int,int>::iterator, bool> ret = randomMap.insert({val, val});
        return ret.second;
    }
    
    bool remove(int val) {
        int erased = randomMap.erase(val);
        return (bool)erased;

    }
    
    int getRandom() {
        int index = rand() % randomMap.size();
        map<int, int>::iterator mit = randomMap.begin();
        for(int i = 0;i < index; i++){
            mit++;
        }

        return (*mit).first;
    }
};

/**
 * Your Randomi zedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */