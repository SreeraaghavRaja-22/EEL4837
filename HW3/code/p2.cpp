#include <bits/stdc++.h>
#include <iostream>
// uses Separate Chaining 
template<typename KeyType, typename DataType>
class HashTable {
private:
    // Vector to hold the buckets
    std::vector<std::vector<std::pair<KeyType, DataType>>> table;
    int max_size; 
    int num_elements; 
    int getBucketIndex(const KeyType& key) const{
        // use this to change the key to a random integer
        std::hash<KeyType> hasher;
        size_t raw_hash_val = hasher(key);

        // shrink the key to fit the table
        return raw_hash_val % table.size();
    }
    
public:
    HashTable(int initial_capacity);
    bool insert(const KeyType& key, DataType value);

    bool contains(const KeyType& key) const;

    bool get(const KeyType& key, DataType& out_value) const;
    
    bool remove(const KeyType& key);
    
    int size(void) const;

    double load_factor(void) const;
};

// Initializes the table with a given number of buckets
// Assume initial_capacity > 0
template<typename KeyType, typename DataType> // requires this for every function
HashTable<KeyType, DataType>::HashTable(int initial_capacity){
    // resize the array with w
    table.resize(initial_capacity);
    num_elements = 0; 
    max_size = initial_capacity;
}

// Inserts a key-value pair into the hash table.
// If the key is new, insert it and return true.
// If the key already exists, overwrite the stored value and return false.
template<typename KeyType, typename DataType>
bool HashTable<KeyType, DataType>::insert(const KeyType& key, DataType value){
    // get the bucket index from the key 
    int inx = getBucketIndex(key);
    // loop through and see if it exists and replace it 
    for(int i = 0; i < table[inx].size(); ++i){
        if(table[inx][i].first == key){
            table[inx][i].second = value;
            return false;
        }
    }
    // add the key and value pair to the table
    table[inx].push_back(std::make_pair(key, value));

    // increment the number of elements
    num_elements++; 
    return true; 
}

// Returns true if the key is present in the table, false otherwise
template<typename KeyType, typename DataType>
bool HashTable<KeyType, DataType>::contains(const KeyType& key) const{
    int inx = getBucketIndex(key); 
    for(int i = 0; i < table[inx].size(); ++i){
        if(table[inx][i].first == key){
            return true; 
        }
    }
    return false; 
} 

// Reads the value stored at the given key.
// Returns true if the key is present and writes the value to out_value.
// Returns false otherwise.
template<typename KeyType, typename DataType>
bool HashTable<KeyType, DataType>::get(const KeyType& key, DataType& out_value) const{
    int inx = getBucketIndex(key);
    for(int i = 0; i < table[inx].size(); ++i){
        if(table[inx][i].first == key){
            out_value = table [inx][i].second;
            return true; 
        }
    }
    return false; 
} 

// Removes a key-value pair by key.
// Returns true if removal succeeds.
// Returns false if the key is not present.
template<typename KeyType, typename DataType>
bool HashTable<KeyType, DataType>::remove(const KeyType& key){
   int inx = getBucketIndex(key);
    for(int i = 0; i < table[inx].size(); ++i){
        if(table[inx][i].first == key){
            table[inx].erase(table[inx].begin() + i);
            // reduce the number of elements
            num_elements--;
            return true;
        }
    } 
    return false;
} 

// Returns the number of stored key-value pairs
template<typename KeyType, typename DataType>
int HashTable<KeyType, DataType>::size() const{
    return num_elements;
}

// Returns the load factor of the hash table
template<typename KeyType, typename DataType>
double HashTable<KeyType, DataType>::load_factor() const{
    // cast num elements to double so that the value is output as a double
    return static_cast<double>(num_elements) / max_size;
}

// int main(void){
//     HashTable<int, int> stuff(10);

//     stuff.insert(10, 1);
//     stuff.insert(20, 2);
//     stuff.insert(30, 3);

//     double big_guy = stuff.load_factor();

//     std::cout << big_guy << std::endl; 


//     return 0; 
// }