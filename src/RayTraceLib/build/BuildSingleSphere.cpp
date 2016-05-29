void 												
World::build(void) {
   vp.set_hres(400);
	vp.set_vres(400);
	vp.set_pixel_size(2.00);
	vp.set_gamma(0.50);
	vp.num_samples= 9;
	background_color = white;
	tracer_ptr = new SingleSphere(this); 
	
	sphere.set_center(0.0);
	sphere.set_radius(85);
	sphere.set_color(red);
}
