#include <iostream>
#include <cstring>

class StringBuilder {
private:
	char *buffer;
	size_t capacity;
	size_t length;

	void expandCapacity(size_t newCapacity) {
		char *newBuffer = new char[newCapacity];
		strcpy(newBuffer, buffer);
		delete[] buffer;
		buffer = newBuffer;
		capacity = newCapacity;
	}
public:
	StringBuilder(size_t initCapacity = 16)
	: length(0), capacity(initCapacity) {
		buffer = new char[capacity];
		buffer[0] = '\0';
	}
	~StringBuilder() {delete[] buffer;}

	void append(const char *str) {
		size_t strLen = strlen(str);
		if (length + strLen + 1 > capacity) {
			expandCapacity((length + strLen) * 2);
		}
		strcat(buffer, str);
		length += strLen;
	}

	std::string toString() const {return std::string(buffer);}

	void clear() {
		length = 0;
		buffer[0] = '\0';
	}
};

int main() {
	StringBuilder sb;
	sb.append("Hello, ");
	sb.append("world!");
	std::cout << sb.toString() << std::endl;
	return 0;
}