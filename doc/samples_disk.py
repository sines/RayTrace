from matplotlib import pyplot as plt;
import numpy  as np;

class point2:
    def __init__(self):
        self.x = 0.0     # x
        self.y = 0.0     # y
        self.phi = 0.0   #phi
        self.r=0.0       #r

def map_samples_to_unit_disk(vec_x=0,vec_y=0):
    r=0.0
    phi = 0.0
    sp=point2()

    sp.x = float(2.0 * float(vec_x) - 1.0);
    sp.y = float(2.0 * float(vec_y) - 1.0);
    if (sp.x > -sp.y):
        if(sp.x > sp.y):
            r = sp.x;
            phi = spy / sp.x;
        else:
            r = sp.y;
            phi = 2 - sp.x / sp.y;
    else:
        if (sp.x < sp.y) :
            r = -sp.x;
            phi = 4 + sp.y / sp.x;
        else:
            r = -sp.y;
            if(sp.y != 0.0):
                phi = 6 - sp.x / sp.y;
            else:
                   phi  = 0.0;

    phi *= np.pi / 4.0;
    disk_point=point2()
    disk_point.x = float(r * np.cos(phi));
    disk_point.y = float(r * np.sin(phi));

    disk_point.phi = phi;
    disk_point.r = r;
    return disk_point;

a_disk = map_samples_to_unit_disk(0.75, 1);

print (a_disk.x, a_disk.y, a_disk.phi, a_disk.r)


plt.figure(1, figsize=(10,8), dpi=80)
plt.scatter(a_disk.x, a_disk.y)
plt.grid();
plt.xticks(np.arange(-1, 1, 0.1));
plt.yticks(np.arange(-1, 1, 0.1));


axes = plt.gca();
axes.spines['right'].set_color('none')
axes.spines['top'].set_color('none')
axes.xaxis.set_ticks_position('bottom')
axes.spines['bottom'].set_position(('data',0))
axes.yaxis.set_ticks_position('left')
axes.spines['left'].set_position(('data',0))
axes.xaxis.grid(color='green');
axes.yaxis.grid(color='red');
plt.title("map_samples_to_unit_disk_POINT2");
'''
    show polar coordinates
'''
plt.figure(2, figsize=(10,8), dpi=80);

ax = plt.axes([0.025,0.025,0.95,0.95], polar=True)


N = 20
theta = np.arange(0.0, 2*np.pi, 2*np.pi/N)
radii = 10*np.random.rand(N)
plt.scatter(a_disk.phi, a_disk.r)

plt.xticks(np.arange(0, np.pi*2, np.pi/4));
plt.yticks(np.arange(0, 10, 1));
axes = plt.gca();
axes.xaxis.grid(color='green');
axes.yaxis.grid(color='red');

plt.show();
