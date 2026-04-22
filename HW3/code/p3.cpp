#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
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

    void write_file(std::ofstream& out_file) const;
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

template<typename KeyType, typename DataType>
void HashTable<KeyType, DataType>::write_file(std::ofstream& out_file) const{
    for(int i = 0; i < table.size(); ++i){
        for(int j = 0; j < table[i].size(); ++j){
            out_file << table[i][j].first << " " << table[i][j].second << std::endl;
        }
    }
}

bool buildWordFrequencyReport(const std::string& input_filename, const std::string& output_filename){

    // create HashTable with string and int types with max size of 1000
    HashTable<std::string, int>word_table(1000);
    std::vector<std::string> word_order_list;

    std::ifstream in_file(input_filename);
    std::ofstream out_file(output_filename);
    // check if the file has successfully opened
    if(in_file.is_open()){

        // create variable for current word
        std::string current_word; 
        int total_valid = 0;
        int total_duplicates = 0;
        int total_distinct = 0; 

        // grabs a word at a time and stores it in current word
        while(in_file >> current_word){
            // create the clean word
            std::string clean_word = "";
            // normalize the tokens
            // lower if alphabetical 
            for(char c : current_word){
                // is alphanumeric just like in python
                if(std::isalnum(c)){
                    clean_word += std::tolower(c);
                }
            }

            if(clean_word.length() == 0){
                    continue;
            }

            total_valid++;

            int current_count = 0;
            // see if the word alredy exists in the HashTable 
            if(word_table.get(clean_word, current_count)){
                word_table.insert(clean_word, current_count+1);
            }
            else{
                total_distinct++;
                word_order_list.push_back(clean_word);
                word_table.insert(clean_word, 1);
            }
        }


        // close the file at the very end
        in_file.close();

        if(out_file.is_open()){
                // output the older values
                out_file << "Total valid words: " << total_valid << std::endl;
                out_file << "Distinct words: " << total_distinct << std::endl;
                out_file << "Words in order of first appearance:" << std::endl;

                // write the values in the hash table to the file
                for(int i = 0; i < word_order_list.size(); ++i){
                    int final_count = 0; 
                    word_table.get(word_order_list[i], final_count);

                    out_file << word_order_list[i] << " " << final_count << std::endl;
                }

                out_file.close();
        }
        else{
            // std::cout << "error opening out_file\n";
            return false;
        }
        // return true if everything passes
        return true; 
    }
    // return false if the file can't be opened
    // std::cout << "error opening file" << '\n';
    return false;
}


int main(){
    buildWordFrequencyReport("in_file.txt", "out_file.txt");
    return 0;
}