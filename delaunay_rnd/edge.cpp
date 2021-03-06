#include "edge.hpp"

int Edge::id_cnt = 0;

Edge::Edge() : id(Edge::id_cnt++), r(-1), next(nullptr), data(nullptr), quad_edge(nullptr)  { }

int Edge::get_id() const
{
	return this->id;
}

Edge* Edge::rot() const 
{
	return this->r < 3 ? (Edge*)this + 1 : (Edge*)this - 3;
}

Edge* Edge::inv_rot() const
{
	return this->r > 0 ? (Edge*)this - 1 :(Edge*)this + 3;
}

Edge* Edge::sym() const
{
	return this->r < 2 ? (Edge*)this + 2 : (Edge*)this - 2;
}

Edge* Edge::o_next() const
{
	return this->next;
}

Edge* Edge::o_prev() const
{
	return this->rot()->o_next()->rot();
}

Edge* Edge::d_next() const
{
	return this->sym()->o_next()->sym();
}

Edge* Edge::d_prev() const
{
	return this->inv_rot()->o_next()->inv_rot();
}

Edge* Edge::l_next() const
{
	return this->inv_rot()->o_next()->rot();
}

Edge* Edge::l_prev() const
{
	return this->o_next()->sym();
}

Edge* Edge::r_next() const
{
	return this->rot()->o_next()->inv_rot();
}

Edge* Edge::r_prev() const
{
	return this->sym()->o_next();
}

std::shared_ptr<Vertex> Edge::org() const
{
	return this->data;
}

std::shared_ptr<Vertex> Edge::dest() const
{
	return this->sym()->data;
}

void Edge::set_r(const int r)
{
	this->r = r;
}

void Edge::set_endpoints(const std::shared_ptr<Vertex> org, const std::shared_ptr<Vertex> dest)
{
	this->data = org;
	this->sym()->data = dest;
}

void Edge::set_next(Edge* const edg)
{
	this->next = edg;
}

Quad_edge* Edge::get_quad_edge() const
{
	return this->quad_edge;
}

void Edge::set_quad_edge(Quad_edge* quad_edge)
{
	this->quad_edge = quad_edge;
}

Edge::~Edge() { }