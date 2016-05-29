const int NUM_SAMPLES = 16;
const int VRES = 400;
const int HRES = 400;
const int PIXEL_GAP = 5;
const int STERO_ANGLE = 0.75;

//////////////////////////////////////////////////////////////////////////

void World::build(void) {
	vp.set_hres(2 * HRES + PIXEL_GAP);
	vp.set_vres(VRES);
	vp.set_pixel_size(0.5);
	vp.num_samples = NUM_SAMPLES;
	tracer_ptr = new MultipleObjects(this); 
	
	vp.set_sampler(new MultiJittered(NUM_SAMPLES));

	background_color = RGBColor(black);
	
	// use access functions to set centre and radius
	
	Sphere* sphere_ptr = new Sphere;
	sphere_ptr->set_center(0, -25, 0);
	sphere_ptr->set_radius(80);
	sphere_ptr->set_color(1, 0, 0);  // red
	add_object(sphere_ptr);

	// use constructor to set centre and radius 
	
	sphere_ptr = new Sphere(Point3D(0, 30, 0), 60);
	sphere_ptr->set_color(1, 1, 0);	// yellow
	add_object(sphere_ptr);
	
	Plane* plane_ptr = new Plane(Point3D(0), Normal(0, 0, 1));
	plane_ptr->set_color(0.3, 0.3, 0.3);	// dark green
	add_object(plane_ptr);


	//////////////////////////////////////////////////////////////////////////
	float vpd = 200;

	Pinhole* leftpinhole_ptr = new Pinhole;
 	leftpinhole_ptr->set_view_distance(vpd);
/*

 	leftpinhole_ptr->set_eye(0, 0, 500);
 	leftpinhole_ptr->set_lookat(0, 0, -500);
	leftpinhole_ptr->compute_uvw();
*/

	Pinhole* rightpinhole_ptr = new Pinhole;
	rightpinhole_ptr->set_view_distance(vpd);

	StereoCamera* stero_ptr = new StereoCamera;
	stero_ptr->set_leftcamera(leftpinhole_ptr);
	stero_ptr->set_rightcamera(rightpinhole_ptr);
	stero_ptr->set_useviewing(parallel);
	stero_ptr->set_pixel_gap(PIXEL_GAP);
	stero_ptr->set_eye(0, 0, 500);
	stero_ptr->set_lookat(0, 0, -500);
	stero_ptr->compute_uvw();
	stero_ptr->set_stereo_angle(STERO_ANGLE);
	stero_ptr->setup_cameras();
	camera_ptr = stero_ptr;

}
