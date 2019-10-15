#include "integer_set.hpp"
#include <iostream>
#include <sstream>

#define CATCH_CONFIG_MAIN

#include <catch.hpp>

//===Adding=================================================================
TEST_CASE("Adding 1 element"){
	Set_integer set;
	set.add(42);
	REQUIRE(set.contains(42));
}

TEST_CASE("Adding 10 elements"){
	Set_integer set;
	std::stringstream out;
	for(int i=0; i<10; i++){
		set.add(i);
	}
	out << set;
	REQUIRE(out.str() == "{0,1,2,3,4,5,6,7,8,9}");
}

TEST_CASE("Adding more than 10 elements"){
	Set_integer set;
	std::stringstream out;
	for(int i=0; i<15; i++){
		set.add(i);
	}
	out << set;
	REQUIRE(out.str() == "{0,1,2,3,4,5,6,7,8,9}");
}

TEST_CASE("Adding duplicate elements"){
	Set_integer set;
	std::stringstream out;
	for(int i=0; i<10; i++){
		set.add(42);
	}
	out << set;
	REQUIRE((set.contains(42) && out.str() == "{42,-1,-1,-1,-1,-1,-1,-1,-1,-1}"));
}

//===Removing===============================================================
TEST_CASE("Removing 1 element"){
	Set_integer set;
	set.add(42);
	set.remove(42);
	REQUIRE(!set.contains(42));
}

TEST_CASE("Removing 10 elements"){
	Set_integer set;
	std::stringstream out;
	for(int i=0; i<10; i++){
		set.add(i);
	}
	for(int i=0; i<10; i++){
		set.remove(i);
	}
	out << set;
	REQUIRE(out.str() == "{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}");
}

TEST_CASE("Removing more than 10 elements"){
	Set_integer set;
	std::stringstream out;
	for(int i=0; i<15; i++){
		set.add(i);
	}
	for(int i=0; i<15; i++){
		set.remove(i);
	}
	out << set;
	REQUIRE(out.str() == "{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}");
}

TEST_CASE("Removing element twice"){
	Set_integer set;
	std::stringstream out;
	set.add(42);
	set.remove(42);
	set.remove(42);
	out << set;
	REQUIRE((!set.contains(42) && out.str() == "{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}"));
}


















