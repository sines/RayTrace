#ifndef __PINHOLE_H__
#define __PINHOLE_H__

#include "Camera.h"
#include "Point2D.h"

class Pinhole : public Camera
{
public:
	Pinhole();
	~Pinhole();

	virtual Pinhole* clone(void) const;
	Vector3D ray_direction(const Point2D& p)const;

	virtual void render_scene(World& w);
	virtual void render_stereo(World& w, float x, int offset);
	void set_view_distance(const float dis);
private:
	float distance;
	float zoom;
};

#endif