#pragma once
#include "Vector3.hpp"
#include <iostream>

class NodeData
{
public:
	NodeData(Vector3 location, std::string name) : Location(location), Name(name) {  };
	Vector3 GetLocation() { return this->Location; }

	friend std::ostream& operator<<(std::ostream& output, const NodeData& data)
	{
		output <<  data.Name << ": ( " << data.Location.X << " , " << data.Location.Y << " , " << data.Location.Z << " )";
		return output;
	}
private:
	Vector3 Location;
	std::string Name;
};