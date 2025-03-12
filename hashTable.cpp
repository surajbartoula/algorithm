#include <iostream>
#include <list>
#include <vector>

class HashTable {
private:
	static const int SIZE = 10;
	std::vector<std::list<std::pair<int, int>>> table;
	int hashFunction(int key) {return key % SIZE;}
public:
	HashTable() : table(SIZE) {}

	void insert(int key, int value) {
		int index = hashFunction(key);
		for (auto& pair: table[index]) {
			if (pair.first == key) {
				pair.second = value;
				return ;
			}
		}
		table[index].emplace_back(key, value);
	}

	int get(int key) {
		int index = hashFunction(key);
		for (const auto& pair:table[index]) {
			if (pair.first == key) return pair.second;
		}
		return -1;
	}

	void remove(int key) {
		int index = hashFunction(key);
		table[index].remove_if([key](const std::pair<int, int>& p) {return p.first == key;});
	}
};

int main() {
	HashTable ht;
	ht.insert(1, 100);
	ht.insert(2, 200);
	std::cout << ht.get(1) << std::endl;
	ht.remove(1);
	std::cout << ht.get(1) << std::endl;
	return 0;
}