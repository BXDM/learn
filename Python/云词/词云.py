# -*- coding: gb2312 -*-
from wordcloud import WordCloud
import jieba
from PIL import Image
import numpy as np
import os

path = os.getcwd()
print('path = \n',path)
font = r'C:\\Windows\\font\\simkai'
img = Image.open(path+r'\a.jpg')
img_array = np.array(img)
text = (open(path+r'\a.txt','r',encoding='gb2312')).read()
cut = jieba.cut(text)
string = ' '.join(cut)
wc = WordCloud(font_path = font,
				background_color="white",
				width=160, 
				height=128, 
				margin=2,
				mask = img_array,
				).generate(string)

import matplotlib.pyplot as plt
plt.imshow(wc)
plt.axis("on")
plt.show()

wc.to_file(path+r'\test.png')
