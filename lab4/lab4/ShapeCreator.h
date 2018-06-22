#pragma once
#include "IShape.h"

class ShapeCreator
{
public:
	ShapeCreator(std::istream& input);
	std::shared_ptr<IShape> CreateShape() const;

private:
	std::shared_ptr<IShape> CreateLine(std::istream& args) const;
	std::shared_ptr<IShape> CreateTriangle(std::istream& args) const;
	std::shared_ptr<IShape> CreateRectangle(std::istream& args) const;
	//std::shared_ptr<IShape> CreateCircle(std::istream& args) const;
	typedef std::map<std::string, std::function<std::shared_ptr<IShape>(std::istream& args)>> ActionMap;
	std::istream& m_input;
	const ActionMap m_actionMap;
};
