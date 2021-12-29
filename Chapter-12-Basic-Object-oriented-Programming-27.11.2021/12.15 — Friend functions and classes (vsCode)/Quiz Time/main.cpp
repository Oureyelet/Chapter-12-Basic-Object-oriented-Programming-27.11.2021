#include <iostream>
#include "Point3d.cpp"
#include "Vector3d.cpp"

int main()
{
    Point3d p{2.0, 2.0, 3.0};
	Vector3d v{77.0, 2.0, -3.0};

	p.print();
	p.moveByVector(v);
	p.print();

    return 0;
}