import matplotlib.pyplot as plt
import matplotlib
# 设置中文字体和负号正常显示
matplotlib.rcParams['font.sans-serif'] = ['SimHei']
matplotlib.rcParams['axes.unicode_minus'] = False

label_list = ['新材料', '玻璃', '石油化工', '冶金、机械', '其他']    
# 横坐标刻度显示值
num_list1 = [54900, 15000, 14000, 10500,5200]      # 纵坐标值1
num_list2 = [38500, 14000, 13500, 9000, 4000]      # 纵坐标值2
num_list3 = [1750,  6500,  8500,  8250,0]
left = range(len(label_list))
"""
绘制条形图
left:长条形中点横坐标
height:长条形高度
width:长条形宽度，默认值0.8
label:为后面设置legend准备
"""
rects3 = plt.bar(x = left, height=num_list3, width=0.2, alpha=0.8, 			color='green',label="2005年（估计）")
rects2 = plt.bar(x = [i + 0.2 for i in left], height=num_list2, width=0.2, color='orange', label="2000年")
rects1 = plt.bar(x = [i + 0.4 for i in left], height=num_list1, width=0.2, color='red', label="1980年")
# plt.ylim(0, 50)     # y轴取值范围
plt.ylabel("数量")
"""
设置x轴刻度显示值
参数一：中点坐标
参数二：显示值
"""
plt.xticks([index + 0.2 for index in left], label_list)
plt.xlabel("产品")
plt.title("全球稀土消费结构（吨）",pad = 20)
plt.legend()     # 设置题注
# 编辑文本
for rect in rects1:
    height = rect.get_height()
    plt.text(rect.get_x() + rect.get_width() / 2, height+1, str(height), ha="center", va="bottom",fontsize  = 6)
for rect in rects2:
    height = rect.get_height()
    plt.text(rect.get_x() + rect.get_width() / 2, height+1, str(height), ha="center", va="bottom",fontsize =  6)
for rect in rects3:
    height = rect.get_height()
    plt.text(rect.get_x() + rect.get_width() / 2, height+1, str(height), ha="center", va="bottom",fontsize =  6)
plt.savefig('figure6.png',dpi = 600)
