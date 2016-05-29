from matplotlib import pyplot as plt;
import numpy  as np;

length = 10;
width = length;
height = length;
sampler = 4;

hres = np.arange(width);
vres = np.arange(height);
num_samples = np.arange(sampler);
pp_x = [];
pp_y =[];

pp_x = hres - 0.5*width + 0.5;
pp_y = vres - 0.5*height + 0.5;

grid_hres = np.linspace(-0.5*width, 0.5*width, 11);
grid_vres = np.linspace(-0.5*height, 0.5*height,11);

print(grid_hres);
print('vres=',pp_x,'\nhres=', pp_y);

plt.xticks(grid_hres);
plt.yticks(grid_vres);
axes = plt.gca();
axes.set_xlim(-width*0.5, width*0.5);
axes.set_ylim(-height*0.5, height*0.5);
axes.spines['right'].set_color('none')
axes.spines['top'].set_color('none')
axes.xaxis.set_ticks_position('bottom')
axes.spines['bottom'].set_position(('data',0))
axes.yaxis.set_ticks_position('left')
axes.spines['left'].set_position(('data',0))

plt.stem(pp_x,pp_y,linefmt='b-', markerfmt='bo', basefmt='r-');
plt.title("RayTracint -Sampler Regular");
plt.grid();
axes.xaxis.grid(color='r', linestyle='-', linewidth=1);
axes.yaxis.grid(color='b', linestyle='-', linewidth=1);
plt.show();
