def get_inmage(html_code):
    reg = r'src = "(.+?\.jpg)" width'
    reg_img = re.compile(reg)
    img_list = reg_img.findall(html_code)
    x = 0
    for img in img_list:
        urllib.urlretrieve(img,'%s.jpg' % x)
        x += 1
    print ('please input a burl:')
    url = raw_input()
    if url:
        pass
    else:
        url = 'http://tieba.baidu.com/p/1753935195'
    html_code = get_html(url)
    get_image(html_code)