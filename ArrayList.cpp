#include <iostream>

class ArrayList {
private:
	int *data;
	size_t capacity;
	size_t size;

	void resize(size_t newCapacity) {
		int *newData = new int[newCapacity];
		for (size_t i = 0; i < size; i++) {
			newData[i] = data[i];
		}
		delete[] data;
		data = newData;
		capacity = newCapacity;
	}
public:
	ArrayList(size_t initCapacity = 4)
		: size(0), capacity(initCapacity) {
		data = new int[capacity];
	}

	~ArrayList() {delete[] data;}

	void push_back(int value) {
		if (size == capacity)
			resize(capacity * 2);
		data[size++] = value;
	}

	void pop_back() {
		if (size > 0) size--;
	}

	int get(size_t index) const {
		if (index >= size) throw std::out_of_range("Index out of range");
		return data[index];
	}

	size_t getSize() const {return size;}
};

int main() {
	ArrayList arr;
	arr.push_back(10);
	arr.push_back(20);
	arr.push_back(30);
	std::cout << arr.get(1) << std::endl;
	arr.pop_back();
	std::cout << arr.getSize() << std::endl;
	return 0;
}