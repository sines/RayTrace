#ifndef __THINLENS_H__
#define __THINLENS_H__

#include "Camera.h"
#include "Point2D.h"
#include "Sampler.h"
#include "Ray.h"
#include "ViewPlane.h"
#include "World.h"


class ThinLens : public Camera
{
public:
	ThinLens();
	~ThinLens();
	void set_sampler(Sampler* sp);
	Vector3D ray_direction(const Point2D& pixel_point, const Point2D& lens_point)const;
	
public:
	virtual void render_scene(World& w);
	virtual ThinLens* clone(void) const;

	void set_view_distance(float viewdis);
	void set_focal_distance(float focaldis);
	void set_lens_radius(float lensradius);
private:
	float lens_radius;
	float d;
	float f;
	float zoom;
	Sampler* sampler_ptr;
};


inline void ThinLens::set_view_distance(float viewdis) {d = viewdis;};
inline void ThinLens::set_focal_distance(float focaldis) {f = focaldis; };
inline void ThinLens::set_lens_radius(float lensradius) {lens_radius = lensradius; };
#endif