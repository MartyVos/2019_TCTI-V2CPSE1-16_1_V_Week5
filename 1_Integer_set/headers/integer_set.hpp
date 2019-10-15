#ifndef INTEGER_SET_HPP
#define INTEGER_SET_HPP

#include <array>
#include <iostream>

class Set_integer{
private:
	std::array<int, 10> values;
	int size = 0;
	int contain_index = -1;
	
public:
	Set_integer(){
		values.fill(-1);
	};
	void add(int value);
	void remove(int value);
	bool contains(int value);
	friend std::ostream& operator<<(std::ostream &os, const Set_integer &set);
};

std::ostream& operator<<(std::ostream &os, const Set_integer &set);

#endif // INTEGER_SET_HPP