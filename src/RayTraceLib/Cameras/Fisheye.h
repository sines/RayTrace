#ifndef __FISHEYE_H__
#define __FISHEYE_H__

#include "Camera.h"
#include "Vector3D.h"
#include "Point2D.h"

class Fisheye : public Camera
{
public:
	Fisheye();
	~Fisheye();

public:
	Vector3D ray_direction(const Point2D& p, 
							const int hres, 
							const int vres, 
							const float s, 
							float& r)const;
	
	virtual void render_scene(World& w);

private:
	float psi_max;

};

inline Fisheye::Fisheye() :psi_max(0)
{
}

inline Fisheye::~Fisheye()
{
	psi_max = 0;
}
#endif