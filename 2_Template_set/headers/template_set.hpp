#ifndef TEMPLATE_SET_HPP
#define TEMPLATE_SET_HPP

#include <array>
#include <iostream>

template<typename T, int N>
class Set{
private:
	std::array<T, N> values;
	int size = 0;
	int contain_index = 0;
	bool has_default = false;		// Flag voor de default initialzed value.
									// Voor int is dit 0 en voor char ''.
									// Wordt true als deze wordt toegevoegd.
	int default_index = -1;			// Index van deze default value.
	
public:
	Set(){
		values.fill(T());
	};

	void add(T value){
		if(size >= N){
			std::cout << "Max size [" << size << "] reached" << std::endl;
			return;
		}
		if((contains(value) && (value == T() && has_default)) ||
		   (contains(value) && value != T())
		){
			std::cout << "Value [" << value << "] already in set" << std::endl;
			return;
		}
		if(contains(T())){			// Zoek voor lege plek
			if(value == T()){
				default_index = contain_index;
				has_default = true;
			}
			values[contain_index] = value;
			size++;
		}		
	}
	
	void remove(T value){
		if(contains(value)){
			if(value == T()){
				has_default = false;
				default_index = -1;
			}
			values[contain_index] = T();
			size--;
		}
	}

	bool contains(T value){
		for(int i=0; i<N; i++){
			if(values[i] == value){
				if(default_index == i){
					continue;
				}
				contain_index = i;
				return true;
			}
		}
		if(value == T() && has_default){
			contain_index = default_index;
			return true;
		}
		return false;	
	}
	
	friend std::ostream& operator<<(std::ostream &os, const Set<T,N> &set){
		os << "{";
		for(int i=0; i<N; i++){
			os << set.values[i];
			if(i < N-1){
				os << ",";
			}
		}
		os << "}";
		return os;
	}
};

#endif // TEMPLATE_SET_HPP