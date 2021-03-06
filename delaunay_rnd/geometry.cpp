#include "geometry.hpp"

Point::Point() { }

Point::Point(double x, double y) : Point(0, x, y) { }

Point::Point(double x, double y, double z)
{
	this->x[0] = x;
	this->x[1] = y;
	this->x[2] = z;
}

bool Point::operator==(const Point& p) const
{
	return this->x[0] == p.x[0] && this->x[1] == p.x[1] && this->x[2] == p.x[2];
}

bool Point::operator<(const Point& p) const
{
	return x[1] < p.x[1] || (x[1] == p.x[1] && x[2] < p.x[2]);
}

Point::~Point() { }

Vector::Vector() { }

Vector::Vector(Point p) : o(p) { }

bool Vector::operator==(const Vector& v) const
{
	return this->o.x[0] == v.o.x[0] && this->o.x[1] == v.o.x[1] && this->o.x[2] == v.o.x[2];
}

Vector& Vector::operator-(const Vector& v) const
{
	Vector v_new{ Point{ this->o.x[0] - v.o.x[0], this->o.x[1] - v.o.x[1], this->o.x[2] - v.o.x[2] } };
	return v_new;
}

Vector::~Vector() { }

Plane::Plane() { }

Plane::Plane(Vector p, Vector u, Vector v) : p(p), u(u), v(v) { }

Plane::~Plane() { }