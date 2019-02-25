# 导入tkinter包，为其定义别名tk
import tkinter as tk
 
# 定义Application类表示应用/窗口，继承Frame类
class Application(tk.Frame):
    # Application构造函数，master为窗口的父控件
    def __init__(self, master=None):
        # 初始化Application的Frame部分
        tk.Frame.__init__(self, master)
        # 显示窗口，并使用grid布局
        self.grid()
        # 创建控件
        self.createWidgets()
 
    # 创建控件
    def createWidgets(self):
        # 创建一个文字为'Quit'，点击会退出的按钮
        self.quitButton = tk.Button(self, text='Quit', command=self.quit)
        # 显示按钮，并使用grid布局
        self.quitButton.grid()
 
# 创建一个Application对象app
app = Application()
# 设置窗口标题为'First Tkinter'
app.master.title = 'First Tkinter'
# 主循环开始
app.mainloop()
 