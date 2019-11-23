import matplotlib.pyplot as plt
import numpy as np 
import matplotlib as mpl

mpl.rcParams["font.sans-serif"] = ["SimHei"]
mpl.rcParams["axes.unicode_minus"] = False

x = np.char.array(["美国", "澳大利亚", "巴西", "缅甸", "布隆迪（非洲）", "中国", "印度", "马来西亚", "俄罗斯", "泰国", "越南"])
y = np.array([15000, 20000,	1000, 5000,	1000, 120000, 1800, 200, 2600,	1000, 400])
colors = ['yellowgreen','red','gold','lightskyblue','white','lightcoral','blue','pink', 'darkgreen','yellow','grey','violet','magenta']
porcent = 100.*y/y.sum()

patches, texts = plt.pie(y, colors=colors, startangle=90, radius=1.2)
labels = ['{0} - {1:1.2f} %'.format(i,j) for i,j in zip(x, porcent)]

sort_legend = True
if sort_legend:
    patches, labels, dummy =  zip(*sorted(zip(patches, labels, y),
                                          key=lambda x: x[2],
                                          reverse=True))

plt.legend(patches, labels, loc='upper right', bbox_to_anchor=(-0.1, 1.),
           fontsize=12)
plt.title(u'2018 年世界各国稀土矿产品产量结构',fontsize = 16,
			)
plt.show()