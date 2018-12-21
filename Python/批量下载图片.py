# -*- coding: utf-8 -*-

import requests
import re
import os
from scrapy.selector import Selector


headers = {
    'User-Agent': 'Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:53.0) Gecko/20100101 Firefox/53.0'
}

class GetSexGirl(object):

    # 获取所有的url
    def get_all_urls(self):
        urls_list = []
        for i in range(1,82):
            url = "http://www.mzitu.com/xinggan/page/{0}".format(i)
            # print(url)
            urls_list.append(url)
        return urls_list

    # 获取当前页的所有url和标题
    def get_title_urls(self,url):
        map_title_url = {}
        selector = self.get_selector(url)
        url = selector.css("#pins span a::attr(href)").extract()
        title = selector.css("#pins span a::text").extract()

        size = len(url)
        for i in range(size):
            map_title_url[url[i]] = title[i]
        return map_title_url

    # 获取当前主题下的所有图片url
    def get_image_urls(self,url):
        print('get_image_urls url is :'+url)
        selector = self.get_selector(url)

        # 获取当前主题的图片总页数
        pages_nav = selector.css(".pagenavi a span").extract()
        total_page = pages_nav[len(pages_nav)-2]
        match_obj = re.match("<span>(\d+)</span>", total_page)
        if match_obj:
            total_page = match_obj.group(1)

        # 获取当前主题的所有图片url
        origin_img_url = selector.css(".main-image img::attr(src)").extract()[0] #当前主题首页的图片
        return self.get_image_urls_step(origin_img_url, total_page)

    # 按照规律推算当前的主题所有的图片url
    def get_image_urls_step(self,image_url,page_number):
        import re
        image_url_list = []
        match_obj = re.match('.*/(.*).jpg', image_url)  # 解析出当前的图片后缀名,用于后面的替换
        if match_obj:
            match_result = match_obj.group(1)
            for i in range(1, int(page_number)+1): # range方法默认从0开始
                if i < 10:
                    next_image_url = match_result.replace(match_result[-2:], "0" + str(i), 1)
                else:
                    next_image_url = match_result.replace(match_result[-2:], str(i), 1)

                next_image_url = image_url.replace(match_result, next_image_url, 1)
                # print(next_image_url)
                image_url_list.append(next_image_url)
        return image_url_list

    # 下载给定url的图片到本地
    def download_image(self, base_dir, image_url):
        print('basedir is :'+base_dir+'  image_url is :'+image_url)
        image_name = image_url[-9:-4]
        # 获取图片的名称, image_url = http://i.meizitu.net/2017/04/24b01.jpg 这种格式
        file_name = base_dir+image_name+"{}.jpg".format(image_name)
        print('file_name is :'+file_name)
        try:
            img_response = requests.get(image_url, headers=headers)
        except:
            return
        f = open(file_name, 'ab')
        f.write(img_response.content)  # 多媒体文件要是用conctent
        f.close()

    def get_selector(self,url):
        response = requests.get(url, headers=headers)
        selector = Selector(text=response.text)
        return selector

if __name__ == '__main__':
    get_sex_girl = GetSexGirl() #获取当前sex模块的所有页面url
    total_url_list = get_sex_girl.get_all_urls()

    for i in range(len(total_url_list)):
        # 获取单个页面的url和title,title用来创建文件夹，map_title_url是一个字典
        map_title_url = get_sex_girl.get_title_urls('http://www.mzitu.com/xinggan/page/2')
        urls = map_title_url.keys()
        for url in urls:
            #对每一个主题创建一个文件夹,文件夹名称就是title
            base_dir = "F:/文本文件/代码文件/Python/{0}/".format(map_title_url.get(url))
            if os.path.exists(base_dir) == False:
                print(map_title_url.get(url)+'  主题的文件夹不存在, 创建它...base_dir is：' + base_dir)
                # 创建文件夹存放图片
                os.makedirs(base_dir)

            #获取当前页的所有图片url地址
            image_url_list = get_sex_girl.get_image_urls(url)
            for i in range(len(image_url_list)):
                # 保存当前页的所有图片到该主题的目录下
                get_sex_girl.download_image(base_dir, image_url_list[i])
