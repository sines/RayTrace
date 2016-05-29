#ifndef __STEROCAMERA_H__
#define __STEROCAMERA_H__

#include "Camera.h"

typedef enum ViewingType
{
	parallel,
	transverse
};

class StereoCamera : public Camera
{
public:
	StereoCamera();
	~StereoCamera();

	virtual StereoCamera* clone(void) const;
public:
	void setup_cameras(void);
	virtual void render_scene(World& w);
	void set_leftcamera( Camera* leftcam);
	void set_rightcamera( Camera* rightcam);

	void set_useviewing(const ViewingType useviewing = parallel);
	void set_pixel_gap(const int gap = 2);
	void set_stereo_angle(const float angle = 0.1);
private:
	ViewingType viewing;
	int pixel_gap;
	float beta;
	Camera* left_camera_ptr;
	Camera* right_camera_ptr;

};

inline void StereoCamera::set_leftcamera( Camera* leftcam)
{
	left_camera_ptr = leftcam;
}

inline void StereoCamera::set_rightcamera( Camera* rightcam)
{
	right_camera_ptr = rightcam;
}

inline void StereoCamera::set_useviewing(const ViewingType useviewing)
{
	viewing = useviewing;
}

inline void StereoCamera::set_pixel_gap(const int gap)
{
	pixel_gap = gap;
}

inline void StereoCamera::set_stereo_angle(const float angle)
{
	beta = angle;
}
#endif