from matplotlib import pyplot as plt;
import numpy  as np;

class point2:
    def __init__(self):
        self.x = 0.0     # x
        self.y = 0.0     # y
        self.phi = 0.0   #phi
        self.r=0.0       #r


class vector3:
    def __init__(self,x=0.0,y=0.0,z=0.0):
        self.x = x     # x
        self.y = y     # y
        self.z = z     # z

class src_data:
    def __init__(self,va='',pos=vector3(),rot=vector3()):
        self.index = ''     # index
        self.pos = pos    #pos
        self.rot = rot   #rot

def map_samples_to_sphere(vec_x=0,vec_y=0):
    r1 	= vec_x;
    r2 	= vec_y;
    z 	= 1.0 - 2.0 * r1;
    r 	= np.sqrt(1.0 - z * z);
    phi = 2*np.pi * r2;
    x 	= r * np.cos(phi);
    y 	= r * np.sin(phi);
    disk_point=point2();

    disk_point.phi = phi;
    disk_point.r = r;
    disk_point.x=x;
    disk_point.y=y;
    return(disk_point)

def map_samples_to_unit_disk(vec_x=0,vec_y=0):
    r=0.0;
    phi = 0.0;
    sp=point2();

    sp.x =vec_x;# float(2.0 * float(vec_x) - 1.0);
    sp.y = vec_y;#float(2.0 * float(vec_y) - 1.0);
    if (sp.x > -sp.y):
        if(sp.x > sp.y):
            r = sp.x;
            phi = sp.y / sp.x;
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
    disk_point=point2();
    disk_point.x = float(r * np.cos(phi));
    disk_point.y = float(r * np.sin(phi));

    disk_point.phi = phi
    disk_point.r = r
    return disk_point

# center Position
# center R

# False
# True

if True:
    center = vector3(20.0, 20.0, 20.0);
    R = 10;

    subcell_width = 1.0 / ((float)(R));
    subcell_height = 1.0 / ((float)(R));

    x = float(20.104980 - center.x)/R;
    y = float(-11.434570 - center.y)/R;

    a_disk = map_samples_to_unit_disk(x,y)
    print (a_disk.x, a_disk.y, a_disk.phi, a_disk.r)
'''
    sphere = map_samples_to_sphere(0.5,0.5)
    print (sphere.x, sphere.y, sphere.phi, sphere.r)
'''

# False
# True
if True :
    file = open(r'E:\\test.txt', 'r')
    center = vector3(20.0, -10.0, -100.0);
    r = 1.0
    subcell = 1.0 / ((float)(r));
    a_disk=[]
    s_data=[]
    for line in  file:
        parts=line.split()
        if (len(parts) >6):
            txtdata = src_data()
            txtdata.index = parts[0] 
            txtdata.pos = vector3(parts[1], parts[2],parts[3])
            txtdata.rot = vector3(parts[4], parts[5],parts[6])

            s_data.append(txtdata);
            #print(len(parts));
            #print(parts);
            #print(txtdata.index, 'pos_x=',txtdata.pos.x, 'pos_y=', txtdata.pos.y, 'pos_z=',txtdata.pos.z, 'rot_x=',txtdata.rot.x,'rot_y= ',txtdata.rot.y, 'rot_z=',txtdata.rot.z, end='');
            x = float((float(txtdata.pos.x) - float(center.x)) *subcell);
            y = float((float(txtdata.pos.y)- float(center.y)) *subcell);
            if x >=-1 and x <=1 and y >=-1 and y <= 1 :
                data = map_samples_to_unit_disk(x, y);
                a_disk.append(data);
                print (data.x, data.y, data.phi, data.r)
            #plt.text(0.0,0.0,"X = "+str(center.x)+"Y = "+str(center.y),ha='center', va= 'center',bbox=dict(facecolor='red', alpha=0.1));


    '''
      #  figure 0
    '''
    #src show
    plt.figure(0, figsize=(10,8), dpi=80)
    plot_x=[];
    plot_y=[];
    for pd in s_data:
        plot_x.append(pd.pos.x);
        plot_y.append(pd.pos.y);

    plt.plot(plot_x, plot_y);
    plt.grid();


    '''
        #  figure 1
    '''
    plt.figure(1, figsize=(10,8), dpi=80)
    plot_x=[];
    plot_y=[];
    for pd in a_disk:
        plot_x.append(pd.x);
        plot_y.append(pd.y);

    plt.scatter(plot_x, plot_y);
    plt.grid();

    plt.xticks(np.arange(-5, 5, 1));
    plt.yticks(np.arange(-5, 5, 1));


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
      #  show polar coordinates
       #  figure 2
    '''
    plt.figure(2, figsize=(10,8), dpi=80);

    ax = plt.axes([0.025,0.025,0.95,0.95], polar=True)


    N = 20
    theta = np.arange(0.0, 2*np.pi, 2*np.pi/N)
    radii = 10*np.random.rand(N)

    for pd in a_disk:
       plt.scatter(pd.phi, pd.r)


    plt.xticks(np.arange(0, np.pi*2, np.pi/4));
    plt.yticks(np.arange(0, 10, 1));
    axes = plt.gca();
    axes.xaxis.grid(color='green');
    axes.yaxis.grid(color='red');

    plt.show();

