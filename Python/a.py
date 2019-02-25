"""
* 0008 && 0009 && 0013
  by VegB
  2017/1/26
"""

from bs4 import BeautifulSoup
import requests
import urllib.request

"""
request这个模块可以处理HTML请求，GET/POST/DELETE/PUT等都可以
调用上述函数之后，会返回一个Response类对象
"""

raw_url = "http://tieba.baidu.com/p/4945979003?see_lz=1&pn="
cnt = 0

for pageNum in range(1, 2):
    url = raw_url + str(pageNum)

    response = requests.get(url)
    response.encoding = "utf-8" 
    # 原来百度的编码方式可能是gb2312啥的 windows的编码方式是gbk，用gbk的方式去解释就会出问题，还是设置为utf-8好了
    # print(response.text)

    html_code = response.text; # Response类对象的text属性，得到html原文
    soup = BeautifulSoup(html_code, "html.parser")

    # websiteCode = urllib.request.urlopen(url).read()
    # soup = BeautifulSoup(websiteCode, "html.parser") # 建立一个BeautifulSoup对象，参数是html文件 或者BeautifulSoup(open('index.html'))

    # 爬链接
    # 输出到文件？
    """
    links = []
    links = soup.findAll('a')
    cnt = 0; 
    for link in links:
        print("LINK %d:", cnt)
        print(link.get('href'))
        print(link.string)
        cnt += 1
    """

    # 下载图片
    imgs = []
    imgs = soup.findAll('img', {'class' : "BDE_Image"}) # 定好类名，不要那些广告的图片
    for img in imgs:
        src = img.get('src')
        print("IMAGE %d:"%cnt)
        print(src)
        fileName = str(cnt) + ".jpg"
        urllib.request.urlretrieve(src, fileName)
        cnt += 1

    pageNum += 1


# 找正文并写入文件
url = "http://162.105.146.180:8130/" # 爬自己写的网站好了哈哈哈
response = requests.get(url)
response.encoding = 'utf-8'
html_code = response.text

soup = BeautifulSoup(html_code)
html_body = soup.findAll('body')
print(html_body)

fp = open('html_body.txt','w')
for li
fp.close()
--------------------- 
作者：VegB 
来源：CSDN 
原文：https://blog.csdn.net/daphne566/article/details/54767235 
版权声明：本文为博主原创文章，转载请附上博文链接！