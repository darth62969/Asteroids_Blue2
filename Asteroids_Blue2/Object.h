#pragma once
#include <string>
#include <memory>
#include "mode.h"
#include "Structures.h"

class mode;

class object
{
public:
	const std::string name;
	const std::string description;
	const uint16_t type_class;
	const uint16_t sub_type_class;
	//Virtual Fucntions
	virtual void render() = 0;
	virtual void doAction(mode * md) = 0;
	void tessellate(layer * lyr);

	virtual bool collides(object* other);
	virtual bool collides(std::shared_ptr<object> other);

	//get / set
	//virtual char* getType();
	vector_shape getLocation();
	point getLocationP();
	void setLocation(double x, double y);
	void setLocation(point loc);
	void setLocation(vector_shape loc);
	double getRotationDx();
	double getRotationDy();
	double getRotationDz();
	point getRotation();


	void setRotationDx(double rot);
	void setRotationDy(double rot);
	void setRotationDz(double rot);
	void setRotation(point rot);
	virtual std::vector<point> getBounds();
	virtual std::vector<triangle> getTess();
	double getVectorLength(object* other);
	double getVectorLength(std::shared_ptr<object> other);

protected:
	vector_shape location;


	/*
	 * Base layer 0 is always the bounds of the object.
	 * Use Layer 0 for collision detection
	 */
	std::vector<layer> lyrs;

};

