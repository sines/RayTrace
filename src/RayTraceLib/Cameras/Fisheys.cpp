#include "Fisheye.h"

#include <math.h>
#include "Constants.h"
#include "ViewPlane.h"
#include "World.h"

void Fisheye::render_scene(World& w)
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
				ray.d = ray_direction(pp, hres, vres, s, r_squared);
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

Vector3D Fisheye::ray_direction(const Point2D& pp, const int hres, const int vres, const float s, float& r_squared)const
{
	// compute the normalized device coordinates
	
	// calculate distance f;
	Point2D pn(2.0 / (s*hres) * pp.x, 2.0 / (s*vres) * pp.y);
	r_squared = pn.x * pn.x + pn.y * pn.y;

	if (r_squared <= 1.0)
	{
		float r = sqrt(r_squared);
		float psi = r * psi_max * PI_ON_180;
		float cos_psi = sin(psi);
		float sin_psi = cos(psi);
		float sin_alpha = pn.y / r;
		float cos_alpha = pn.x / r;
		Vector3D dir = sin_psi * cos_alpha * u + sin_psi * sin_alpha * v - cos_psi*w;
		return dir;

	}
	else
	{
		return (Vector3D(0.0));
	}
}