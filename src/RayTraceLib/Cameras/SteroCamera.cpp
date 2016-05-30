#include "SteroCamera.h"
#include "Constants.h"
#include "ViewPlane.h"
#include "World.h"

#include <math.h>

StereoCamera::StereoCamera()
{
	 viewing = parallel;
	 pixel_gap = 10;
	 beta = 0.75;
	left_camera_ptr = nullptr;
	right_camera_ptr = nullptr;
};

StereoCamera::~StereoCamera()
{
};
StereoCamera* StereoCamera::clone(void) const
{
	return (new StereoCamera);
};

void StereoCamera::setup_cameras(void)
{
	double r = eye.distance(lookat);
	double x = r * tan(0.5*beta*PI_ON_180);

	left_camera_ptr->set_eye(eye - x *u);
	left_camera_ptr->set_lookat(lookat - x*u);
	left_camera_ptr->compute_uvw();

	right_camera_ptr->set_eye(eye + x *u);
	right_camera_ptr->set_lookat(lookat + x*u);
	right_camera_ptr->compute_uvw();
}

void StereoCamera::render_scene(World& w)
{
	ViewPlane vp = w.vp;

	int hres = vp.hres;
	int vres = vp.vres;
	double r = eye.distance(lookat);
	double x = r * tan(0.5* beta * PI_ON_180);

	if (viewing == parallel)
	{
		// left view on left
		left_camera_ptr->render_stereo(w, x, 0);
		
		w.addlayer();
		// right view on right
		right_camera_ptr->render_stereo(w, -x, pixel_gap);

	}

	if (viewing == transverse)
	{
		// right view on left
		right_camera_ptr->render_stereo(w, -x, 0);

		w.addlayer();
		// left view on right
		left_camera_ptr->render_stereo(w, x, pixel_gap);
	}

}