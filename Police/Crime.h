#pragma once
#include <iostream>
#include <string>
#include <map>

const std::map<size_t, std::string> crimes =
{
	{1, "Passing through a red traffic light"},
	{2, "Over speed"},
	{3, "Driving in the opposite lane"},
	{4, "Stop at the crossroads"},
	{5, "Stop at the crossroads"},
	{6, "Parking in the wrong place"}
};


class Crime
{
	size_t id;
	std::string place;
public:
	size_t get_id()const
	{
		return id;
	}
	const std::string& get_place()const
	{
		return place;
	}
	Crime(size_t id, const std::string& place) : id(id), place(place) {}
	~Crime() {}

}; 

std::ostream& operator<<(std::ostream& os, const Crime& obj);
