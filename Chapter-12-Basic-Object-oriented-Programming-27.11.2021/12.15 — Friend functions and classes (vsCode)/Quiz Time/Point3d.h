#ifndef POINT_H
#define POINT_H

class Vector3d;

class Point3d
{
private:
	double m_x{};
	double m_y{};
	double m_z{};

public:
	Point3d(double, double, double);
	void print() const;
	void moveByVector(const Vector3d& v);
};

#endif // end of POINT_H