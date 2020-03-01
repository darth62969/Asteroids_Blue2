#include "Object.h"

bool intersect(point v1, point v2, point v3, point v4)
{
	double ua_num = ((v3.x - v1.x) * -(v4.y - v3.y)) - (-(v4.x - v3.x) * (v3.y - v1.y));
	double den = ((v2.x - v1.x) * -(v4.y - v3.y)) - (-(v4.x - v3.x) * (v2.y - v1.y));

	double ub_num = ((v2.x - v1.x) * (v3.y - v1.y)) - ((v3.x - v1.x) * (v2.y - v1.y));

	double ua = ua_num / den;
	double ub = ub_num / den;

	if ((ua > 0.0) && (ua < 1.0) && (ub > 0.0) && (ub < 1.0))
	{
		return true;
	}

	return false;
}

double sign(point p1, point p2, point p3)
{
	return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

bool PointInTriangle(point pt, point v1, point v2, point v3)
{
	bool b1, b2, b3;

	b1 = sign(pt, v1, v2) < 0.0;
	b2 = sign(pt, v2, v3) < 0.0;
	b3 = sign(pt, v3, v1) < 0.0;

	return ((b1 == b2) && (b2 == b3));
}

void object::tessellate(layer* lyr)
{
	std::vector<point> temp = lyr->points;
	point A = temp[0];
	point B = temp[1];
	point C = temp[2];
	uint32_t Ai = 0;
	uint32_t Bi = 1;
	uint32_t Ci = 2;
	triangle tri;
	double z;

	uint32_t i = 0;
	// While there are more than three vertices left in points, run the following code.
	while (temp.size() >= 3)
	{
		//cout << intersect (temp[0], temp[1], A, B) << endl;

		bool insect = false;
		for (uint32_t i1 = 0; i1 < lyr->points.size(); i1++)
		{
			switch (i1)
			{
			case 0:
				if (intersect(lyr->points[i1], lyr->points[lyr->points.size() - 1], A, B))
					insect = true;
				if (intersect(lyr->points[i1], lyr->points[lyr->points.size() - 1], B, C))
					insect = true;
				if (intersect(lyr->points[i1], lyr->points[lyr->points.size() - 1], C, A))
					insect = true;
				break;
			default:
				if (intersect(lyr->points[i1], lyr->points[i1 - 1], A, B))
					insect = true;
				if (intersect(lyr->points[i1], lyr->points[i1 - 1], B, C))
					insect = true;
				if (intersect(lyr->points[i1], lyr->points[i1 - 1], C, A))
					insect = true;
				break;
			}
			if (insect)
			{
				break;
			}
		}

		for (uint32_t i1 = 0; i1 < lyr->triangles.size(); i1++)
		{
			point temp1[3] = { lyr->triangles[i1].a, lyr->triangles[i1].b, lyr->triangles[i1].c };
			for (uint32_t j1 = 0; j1 < 3; j1++)
			{
				switch (j1)
				{
				case 0:
					if (intersect(temp1[j1], temp1[2], A, B))
						insect = true;
					if (intersect(temp1[j1], temp1[2], B, C))
						insect = true;
					if (intersect(temp1[j1], temp1[2], C, A))
						insect = true;
					break;
				default:
					if (intersect(temp1[j1], temp1[j1 - 1], A, B))
						insect = true;
					if (intersect(temp1[j1], temp1[j1 - 1], B, C))
						insect = true;
					if (intersect(temp1[j1], temp1[j1 - 1], C, A))
						insect = true;
					break;
				}
			}
			if (insect)
				break;
		}
		if (insect)
		{
			Ci++;
			if (Ci >= temp.size())
			{
				Bi++;
				if (Bi >= temp.size() - 1)
				{
					temp.erase(temp.begin());
					Bi = Ai + 1;
					Ci = Bi + 1;
					A = temp[Ai];
					B = temp[Bi];
					C = temp[Ci];


				}
				else
				{
					Ci = Bi + 1;
					B = temp[Bi];
					C = temp[Ci];
				}
			}
			else
			{
				C = temp[Ci];
			}
		}

		if (!insect)
		{
			point l1;
			l1.x = A.x - B.x;
			l1.y = A.y - B.y;

			point l2;
			l2.x = C.x - B.x;
			l2.y = C.y - B.y;

			z = l1.x * l2.y - l2.x * l1.y;

			bool within = false;
			for (uint32_t i = 0; i < temp.size(); i++)
			{
				if (PointInTriangle(temp[i], A, B, C) && Ai != i && Bi != i && Ci != i)
					within = true;
			}

			if (z < 0 && !within)
			{
				tri.a = A;
				tri.b = B;
				tri.c = C;
				lyr->triangles.push_back(tri);

				Bi = Ci;
				B = temp[Bi];

				Ci++;
				C = temp[Ci];

			}
			else
			{
				Ci++;
				if (Ci >= temp.size())
				{
					Bi++;
					if (Bi >= temp.size() - 1)
					{
						temp.erase(temp.begin());
						Bi = Ai + 1;
						Ci = Bi + 1;
						A = temp[Ai];
						B = temp[Bi];
						C = temp[Ci];
					}
					else
					{
						Ci = Bi + 1;
						B = temp[Bi];
						C = temp[Ci];
					}
				}
				else
				{
					C = temp[Ci];
				}
			}

		}
	}

	for (uint32_t i = 0; i < lyr->triangles.size(); i++)
	{
	}
}


//Colition model
bool object::collides(object* other)
{
	return false;
}

//colition model 2
bool object::collides(std::shared_ptr<object> other)
{
	return false;
}


//Returns the location of the object includting Rotational Information and velocity.
vector_shape object::getLocation()
{
	return location;
}
point object::getLocationP()
{
	return location.l;
}

void object::setLocation(double x, double y)
{
	location.l.x = x;
	location.l.y = y;
}

void object::setLocation(point loc)
{
	location.l = loc;
}

void object::setLocation(vector_shape loc)
{
	location = loc;
}

double object::getRotationDx()
{
	return location.r.x;
}
double object::getRotationDy()
{
	return location.r.y;
}
double object::getRotationDz()
{
	return location.r.z;
}

point object::getRotation()
{
	return location.r;
}

void object::setRotationDx(double rot)
{
	location.r.x = rot;
}

void object::setRotationDy(double rot)
{
	location.r.y = rot;
}
void object::setRotationDz(double rot)
{
	location.r.z = rot;
}
void object::setRotation(point rot)
{
	location.r = rot;
}

std::vector<point> object::getBounds()
{
	return std::vector<point>();
}

std::vector<triangle> object::getTess()
{
	return std::vector<triangle>();
}

double object::getVectorLength(object* other)
{
	return sqrt(pow(abs(location.l.x - other->getLocation().l.x), 2) + pow(abs(location.l.y - other->getLocation().l.y), 2));
}
double object::getVectorLength(std::shared_ptr<object> other)
{
	return sqrt(pow(abs(location.l.x - other->getLocation().l.x), 2) + pow(abs(location.l.y - other->getLocation().l.y), 2));
}


