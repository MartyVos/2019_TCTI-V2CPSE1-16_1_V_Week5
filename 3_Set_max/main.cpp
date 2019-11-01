#include "template_set.hpp"
#include <sstream>
#include <string>
#include <iostream>

#define CATCH_CONFIG_MAIN

#include <catch.hpp>

//===Maximum================================================================
TEST_CASE("Comparing 10 positive values [int]"){
	Set<int,10> set;
	std::stringstream out;
	for(int i=0; i<10; i++){
		set.add(i);
	}
	out << set.max();
	REQUIRE(out.str() == "9");
}

TEST_CASE("Comparing 10 negative values [int]"){
	Set<int,10> set;
	std::stringstream out;
	for(int i=-9; i<0; i++){
		set.add(i);
	}
	out << set.max();
	REQUIRE(out.str() == "0");
}

TEST_CASE("Comparing positive and negative values [int]"){
	Set<int,10> set;
	std::stringstream out;
	for(int i=0; i<10; i++){
		if(i % 2 == 0){
			set.add(-i);
		}else{
			set.add(i);
		}
	}
	out << set.max();
	REQUIRE(out.str() == "9");
}