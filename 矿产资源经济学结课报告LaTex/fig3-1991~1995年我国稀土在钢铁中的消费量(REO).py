import matplotlib as mpl
from matplotlib import pyplot as plt
import numpy as np

mpl.rcParams["font.sans-serif"]=["SimHei"]
mpl.rcParams["axes.unicode_minus"] = False

year = np.arange(1991,1996,)
iron = [2800, 2970, 3000, 3480, 3500]
steel = [566 , 710, 750 , 300, 300]
plt.plot(year,iron,color = 'orange',label = ' 铁')
plt.plot(year,steel,color = 'deepskyblue',label = ' 钢')
plt.legend(loc = 'upper left')
plt.title('1991~1995年我国稀土在钢铁中的消费量(REO)',fontsize = 14,pad = 20)
plt.xticks(year)
plt.xlabel('年')
plt.ylabel('消费量(吨)')
plt.grid(linestyle = ':',color = 'r')
plt.savefig('figure3.png',dpi = 600)
plt.show()