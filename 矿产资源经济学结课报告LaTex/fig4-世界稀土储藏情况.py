import matplotlib as mpl
from matplotlib import pyplot as plt
import numpy as np

mpl.rcParams["font.sans-serif"]=["SimHei"]
mpl.rcParams["axes.unicode_minus"] = False

label = ["美国", "俄罗斯独联体", "澳大利亚", "中国", "其他国家" ]
value = [1300, 1900, 540,3600,2475]
color = ['deepskyblue', 'tomato', 'gray', 'moccasin', 'palegreen'] 
font1 = {'color' : 'white'}
plt.pie(
		value,
		labels = label,
		colors = color,
		startangle = 90,
		explode = [0, 0 ,0, 0.1 ,0],
		autopct = '%1.1f%%'
) 
		
#plt.plot(year,iron,color = 'orange',label = ' 铁')
#plt.plot(year,steel,color = 'deepskyblue',label = ' 钢')
#plt.legend(loc = 'upper left')
plt.title('世界稀土储藏情况(万吨）',fontsize = 14,pad = 20)
#plt.xticks(year)
#plt.xlabel('年')
#plt.ylabel('消费量(吨)')
#plt.grid(linestyle = ':',color = 'r')
plt.savefig('figure4.png',dpi = 600)
plt.show()