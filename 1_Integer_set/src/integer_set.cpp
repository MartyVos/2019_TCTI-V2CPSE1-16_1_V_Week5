#include "integer_set.hpp"

void Set_integer::add(int value){
	if(size == 10 || contains(value)){
		return;
	}
	if(contains(-1)){
		values[contain_index] = value;
		size++;
	}
}

void Set_integer::remove(int value){
	if(!contains(value)){
		return;
	}
	values[contain_index] = -1;
	size--;
}

bool Set_integer::contains(int value){
	for(int i=0; i<10; i++){
		if(values[i] == value){
			contain_index = i;
			return true;
		}
	}
	return false;
}

std::ostream& operator<<(std::ostream &os, const Set_integer &set){
	os << "{";
	for(int i=0; i<10; i++){
		os << set.values[i];
		if(i < 9){
			os << ",";
		}
	}
	os << "}";
	return os;
}