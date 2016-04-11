from matplotlib import pyplot as plt;
import numpy  as np;

def phi(j):
    x = 0;
    f = 0.5;
    while (np.floor(j)):
        x += f *(j % 2);
        j /= 2;
        f *= 0.5; 
    return x;

length = 10;
width = length;
height = length;
num_sampler = 4;

hres = np.arange(width);
vres = np.arange(height);
sampler = np.arange(num_sampler);
pp_x = [];
pp_y =[];

#Hammersley
for c in hres:
    for v in vres:
       for n in range(0,np.square(num_sampler)):
           fphi = phi(n);
           p_x = v - 0.5*width + float(n/num_sampler);
           p_y = c - 0.5*width + fphi;
           print('num_sampler: n=',n,"phi=", fphi);
           plt.scatter(p_x,p_y,color='black', s=0.5,alpha=1);

"""
           #
           p_x = v - 0.5*width + np.random.ranf();
           p_y = c - 0.5*width + np.random.ranf();
           plt.scatter(p_x,p_y,color='black', s=0.5,alpha=1);
"""

"""
        #
        for q in sampler:
            for p in sampler:
                p_x = v - 0.5*width + (p+np.random.ranf())/num_sampler;
                p_y = c - 0.5*width + (q+np.random.ranf())/num_sampler;
                plt.scatter(p_x,p_y,color='black', s=0.5,alpha=1);
"""

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

plt.stem(pp_x, pp_y);

for p_x in pp_x:
    for p_y in pp_y:
        plt.scatter(p_x,p_y,color='red', s=8.0,alpha=1);

plt.title("RayTracing -Sampler Hammersley");
plt.grid();
axes.xaxis.grid(color='r', linestyle='-', linewidth=1);
axes.yaxis.grid(color='b', linestyle='-', linewidth=1);
plt.show();
