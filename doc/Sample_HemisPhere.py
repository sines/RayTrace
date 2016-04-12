from matplotlib import pyplot as plt;
import numpy  as np;

for i in range(0, 25):
    thea = np.linspace(0, np.pi*0.5, 90);
    d = np.cos(thea)**i;
    #print("thea=", thea, "d=", d);
    plt.plot(thea, d);

plt.title("RayTracing -Sampler HemisPhere");
plt.grid();
plt.text(1.0,0.9,"COS(thea)^e",ha='center', va= 'top',bbox=dict(facecolor='red', alpha=0.5));
plt.xticks(np.arange(0, np.pi*0.5+0.1, 0.1));
plt.yticks(np.arange(0, 1+0.1, 0.1));
axes = plt.gca();
axes.xaxis.grid(color='black', linestyle='-', linewidth=1, alpha=0.5);
axes.yaxis.grid(color='black', linestyle='-', linewidth=1, alpha=0.5);
plt.show();
