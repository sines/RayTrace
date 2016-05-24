#ifndef __SPHERICAL_H__
#define __SPHERICAL_H__

#include "Camera.h"
#include "Vector3D.h"
#include "Point2D.h"

class Spherical : public Camera
{
public:
	Spherical();
	~Spherical();

public:
	Vector3D ray_direction(const Point2D& p,
		const int hres,
		const int vres,
		const float s)const;

	virtual void render_scene(World& w);

private:
	float lambda_max;
	float psi_max;

};

inline Spherical::Spherical() :psi_max(0)
{
}

inline Spherical::~Spherical()
{
	psi_max = 0;
}
#endif