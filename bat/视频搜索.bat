::输入一个关键字，同时在多个网站中搜索

@echo off
echo 请输入关键字：
set/p word=
start chrome https://search.bilibili.com/all?keyword=%word%&from_source=banner_search

start chrome https://v.qq.com/x/search/?q=%word%&stag=0&smartbox_ab=

start chrome http://so.iqiyi.com/so/q_%word%?source=input&sr=748646819168

start chrome http://so.youku.com/search_video/q_python?spm=a2hww.11359951.#qheader_search~10
