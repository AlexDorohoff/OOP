#include "stdafx.h"
#include "../FindMaxEx/FindMaxEx.h"

struct Student
{
	std::string name;
	double height;
	double weight;
};

Student One = { "First", 220.5, 100.50 };
Student Two = { "Second", 190, 100 };
Student Three = { "Third", 190, 120 };
Student Four = { "Fourth", 180, 150.5 };
Student Five = { "Fifth", 100, 180 };

std::vector<Student> emptyVector;
std::vector<Student> Students = { One, Two, Three, Four, Five };

bool LessWeight(Student const& left, Student const& right)
{
	return (left.weight < right.weight);
}

bool LessHeight(Student const& left, const Student const& right)
{
	return (left.height < right.height);
}

TEST_CASE("an empty array do not have the required element")
{
	Student maxWeight;
	CHECK(!FindMaxEx(emptyVector, maxWeight, LessWeight));
};

TEST_CASE("returns the maximum weight")
{
	Student maxWeight;
	CHECK(FindMaxEx(Students, maxWeight, LessWeight));
	CHECK(maxWeight.weight == 180);
	CHECK(maxWeight.name == "Fifth");
};

TEST_CASE("returns the maximum height")
{
	Student maxHeight;
	CHECK(FindMaxEx(Students, maxHeight, LessHeight));
	CHECK(maxHeight.height == 220.5);
	CHECK(maxHeight.name == "First");
};
