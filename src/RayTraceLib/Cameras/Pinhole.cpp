#include "Pinhole.h"
#include "RGBColor.h"
#include "ViewPlane.h"
#include "Ray.h"
#include "World.h"

Pinhole::Pinhole() :distance(1), zoom(1)
{
};

Pinhole::~Pinhole()
{};

Vector3D Pinhole::ray_direction(const Point2D& p)const{
	Vector3D dir = p.x *u + p.y*v - distance*w;
	dir.normalize();
	return(dir);
};

void Pinhole::render_scene(World& w){
	RGBColor L;
	ViewPlane vp(w.vp);
	Ray ray;
	int depth = 0;
	Point2D sp;
	Point2D pp;

	vp.s /= zoom;
	ray.o = eye;

	for (int r = 0; r < vp.vres; r++)
	{
		for (int c = 0; c < vp.hres; c++)
		{
			L = black;
			for (int j = 0; j < vp.num_samples; j++)
			{
				sp = vp.sampler_ptr->sample_unit_square();
				pp.x = vp.s * (c -0.5 * vp.hres + sp.x);
				pp.y = vp.s * (r - 0.5 * vp.vres + sp.y);
				ray.d = ray_direction(pp);
				L += w.tracer_ptr->trace_ray(ray);
			}

			L /= vp.num_samples;
			L *= exposure_time;
			w.display_pixel(r, c, L);
		}
	}
};

void Pinhole::set_view_distance(const float dis)
{
	distance = dis;
}

Pinhole*Pinhole::
clone(void) const{

	return (new Pinhole);
};