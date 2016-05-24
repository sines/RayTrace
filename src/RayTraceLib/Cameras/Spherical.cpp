#include "Spherical.h"

#include <math.h>
#include "Constants.h"
#include "ViewPlane.h"
#include "World.h"

void Spherical::render_scene(World& w)
{
	RGBColor L;
	ViewPlane vp(w.vp);
	int hres = vp.hres;
	int vres = vp.vres;
	float s = vp.s;
	Ray ray;
	int depth = 0;
	Point2D sp;
	Point2D pp;
	float r_squared;

	ray.o = eye;
	for (int r = 0; r < vp.vres; r++)
	{
		for (int c = 0; c < vp.hres; c++)
		{
			L = black;
			for (int j = 0; j < vp.num_samples; j++)
			{
				sp = vp.sampler_ptr->sample_unit_square();
				pp.x = vp.s * (c - 0.5 * vp.hres + sp.x);
				pp.y = vp.s * (r - 0.5 * vp.vres + sp.y);
				ray.d = ray_direction(pp, hres, vres, s);
				if (r_squared <= 1.0)
				{
					L += w.tracer_ptr->trace_ray(ray, depth);
				}
			}
			L /= vp.num_samples;
			L *= exposure_time;
			w.display_pixel(r, c, L);
		}
	}
}

Vector3D Spherical::ray_direction(const Point2D& pp, const int hres, const int vres, const float s)const
{
	// compute the normalized device coordinates

	// calculate distance f;
	Point2D pn(2.0 / (s*hres) * pp.x, 2.0 / (s*vres) * pp.y);
	
	float lambda = pn.x * lambda_max * PI_ON_180;
	float psi = pn.x * psi_max * PI_ON_180;
	
	float phi = PI - lambda;
	float theta = 0.5*PI - psi;

	float sin_phi = sin(phi);
	float cos_phi = cos(phi);
	float sin_theta = sin(theta);
	float cos_theta = cos(theta);

	Vector3D dir = sin_theta *sin_phi *u + cos_theta *v + sin_theta * cos_phi*w;
	return (dir);
}