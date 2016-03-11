#ifndef __VIEW_PLANE__
#define __VIEW_PLANE__

#include "Sampler.h"
#include "MultiJittered.h"
#include "Regular.h"

//-------------------------------------------------------------------------------------- class ViewPlane

class ViewPlane {
	public:
		int 			hres;   					// horizontal image resolution 
		int 			vres;   					// vertical image resolution
		float			s;							// pixel size
		
		float			gamma;						// gamma correction factor
		float			inv_gamma;					// the inverse of the gamma correction factor
		bool			show_out_of_gamut;			// display red if RGBColor out of gamut
		int				num_samples;
									
		Sampler*		sampler_ptr;
	public:
	
		ViewPlane();   								// default Constructor
				
		ViewPlane(const ViewPlane& vp);				// copy constructor

		ViewPlane& operator= (const ViewPlane& rhs);		// assignment operator
		
		~ViewPlane();   							// destructor
						
		void 													
		set_hres(const int h_res);
		
		void 													
		set_vres(const int v_res);
				
		void
		set_pixel_size(const float size);
		
		void
		set_gamma(const float g);
		
		void
		set_gamut_display(const bool show);

		void
		set_num_samples(const int num);

		void 
		set_sampler(Sampler* sampler);
};




// ------------------------------------------------------------------------------ set_hres

inline void 													
ViewPlane::set_hres(const int h_res) {
	hres = h_res;
}


// ------------------------------------------------------------------------------ set_vres

inline void 													
ViewPlane::set_vres(const int v_res) {
	vres = v_res;
}


// ------------------------------------------------------------------------------ set_pixel_size

inline void 													
ViewPlane::set_pixel_size(const float size) {
	s = size;
}


// ------------------------------------------------------------------------------ set_gamma

inline void
ViewPlane::set_gamma(const float g) {
	gamma = g;
	inv_gamma = 1.0 / gamma;
}


// ------------------------------------------------------------------------------ set_gamut_display

inline void
ViewPlane::set_gamut_display(const bool show) {
	show_out_of_gamut = show;
}

// ------------------------------------------------------------------------------ set_num_samples

inline void
ViewPlane::set_num_samples(const int num) {
	num_samples = num;

	if (sampler_ptr)
	{
		delete sampler_ptr;
		sampler_ptr = NULL;
	}
	
	if (num_samples > 1)
	{
		sampler_ptr = new MultiJittered(num_samples);
	}
	else
	{
		sampler_ptr = new Regular(1);
	}
}


inline void
ViewPlane::set_sampler(Sampler* sampler)
{
	if (sampler == NULL)
		return;
	sampler_ptr = sampler;
}

#endif
