#include "template_set.hpp"
#include <sstream>
#include <string>

#define CATCH_CONFIG_MAIN

#include <catch.hpp>

//===Adding=================================================================
	//===Float=============================================================
TEST_CASE("Adding 1 element [float]"){
	Set<float,4> set;
	set.add(42.42f);
	REQUIRE(set.contains(42.42f));
}

TEST_CASE("Adding 10 elements [float]"){
	Set<float,10> set;
	std::stringstream out;
	for(int i=0; i<10; i++){
		set.add(i*1.1f);
	}
	out << set;
	REQUIRE(out.str() == "{0,1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9}");
}

TEST_CASE("Adding duplicate elements [float]"){
	Set<float,4> set;
	std::stringstream out;
	set.add(42.42f);
	set.add(42.42f);
	out << set;
	REQUIRE(out.str() == "{42.42,0,0,0}");
}

	//===Int===============================================================
TEST_CASE("Adding 1 element [int]"){
	Set<int,4> set;
	set.add(42);
	REQUIRE(set.contains(42));
}

TEST_CASE("Adding 10 elements [int]"){
	Set<int,10> set;
	std::stringstream out;
	for(int i=0; i<10; i++){
		set.add(i*11);
	}
	out << set;
	REQUIRE(out.str() == "{0,11,22,33,44,55,66,77,88,99}");
}

TEST_CASE("Adding duplicate elements [int]"){
	Set<int,4> set;
	std::stringstream out;
	set.add(42);
	set.add(42);
	out << set;
	REQUIRE(out.str() == "{42,0,0,0}");
}

//===Removing===============================================================
	//===Float=============================================================
TEST_CASE("Removing 1 element [float]"){
	Set<float,4> set;
	set.add(12.34f);
	set.add(0.0f);
	set.add(42.42f);
	set.add(42.43f);
	set.remove(42.42f);
	REQUIRE(!set.contains(42.42f));
}

TEST_CASE("Removing 10 elements [float]"){
	Set<float,10> set;
	std::stringstream out;
	for(int i=0; i<10; i++){
		set.add(i*1.1f);
	}
	for(int i=0; i<10; i++){
		set.remove(i*1.1f);
	}
	out << set;
	REQUIRE(out.str() == "{0,0,0,0,0,0,0,0,0,0}");
}

TEST_CASE("Removing duplicate elements [float]"){
	Set<float,4> set;
	std::stringstream out;
	set.add(1.2f);
	set.add(42.42f);
	set.add(7.8f);
	set.remove(42.42f);
	set.remove(42.42f);
	out << set;
	REQUIRE(out.str() == "{1.2,0,7.8,0}");
}

	//===Int===============================================================
TEST_CASE("Removing 1 element [int]"){
	Set<int,4> set;
	set.add(1234);
	set.add(0);
	set.add(42);
	set.add(43);
	set.remove(42);
	REQUIRE(!set.contains(42));
}

TEST_CASE("Removing 10 elements [int]"){
	Set<int,10> set;
	std::stringstream out;
	for(int i=0; i<10; i++){
		set.add(i*11);
	}
	for(int i=0; i<10; i++){
		set.remove(i*11);
	}
	out << set;
	REQUIRE(out.str() == "{0,0,0,0,0,0,0,0,0,0}");
}

TEST_CASE("Removing duplicate elements [int]"){
	Set<int,4> set;
	std::stringstream out;
	set.add(12);
	set.add(42);
	set.add(78);
	set.remove(42);
	set.remove(42);
	out << set;
	REQUIRE(out.str() == "{12,0,78,0}");
}


































