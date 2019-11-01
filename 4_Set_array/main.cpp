#include "template_set.hpp"
#include <sstream>
#include <string>
#include <array>

#define CATCH_CONFIG_MAIN

#include <catch.hpp>

//===Comparing 1 std::array>char,3> Set is not full=========================
TEST_CASE("Comparing 1 array and 1 empty array [std::array<char,3>]"){
	Set<std::array<char,3>,2> set;
	std::stringstream out;
	set.add(std::array<char,3>{'a','b','c'});
	out << set.max();
	REQUIRE(out.str() == "{a,b,c}");
}

//===Comparing 2 std::array>char,3>=========================================
TEST_CASE("Comparing 2 arrays [std::array<char,3>]"){
	Set<std::array<char,3>,2> set;
	std::stringstream out;
	set.add(std::array<char,3>{'a','b','c'});
	set.add(std::array<char,3>{'x','y','z'});
	out << set.max();
	REQUIRE(out.str() == "{x,y,z}");
}

//===Comparing 3 std::array>char,3>=========================================
TEST_CASE("Comparing 3 arrays [std::array<char,3>]"){
	Set<std::array<char,3>,3> set;
	std::stringstream out;
	set.add(std::array<char,3>{'A','B','C'});
	set.add(std::array<char,3>{'1','2','3'});
	set.add(std::array<char,3>{'<','=','>'});
	out << set.max();
	REQUIRE(out.str() == "{A,B,C}");
}