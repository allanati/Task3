#include <iostream>

void set(unsigned char* value, unsigned char valueToWrite, unsigned char index) {	//where we store 2 numbers
	unsigned char shift = (index * 2) * 2;			// shift will be 0 or 4
	*value &= ~(0b1111 << shift);					// *value = 0000 0000
	*value |= valueToWrite << shift;				// if index = 0 this will store first number in binary form on the right
	// if index = 1 this will store first number in binary form on the left
}

unsigned char get(unsigned char value, unsigned char index) {	// get a number knowing index 
	if (index == 0) {
		value &= ~(0b1111 << 4);		// (bit and) 0000 1111
		return value;
	}

	value &= ~0b1111;		// (bit and) 1111 0000
	value >>= 4;
	return value;
}

int main() {
	unsigned char value = 0;
	set(&value, 10, 0);		// pack 2 numbers in 1 byte
	set(&value, 11, 1);

	std::cout << +value << std::endl;		// stores 2 numbers
	std::cout << +get(value, 1) << " " << +get(value, 0) << std::endl;		// get 2 numbers out of value
}