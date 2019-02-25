close all;
clear all;
clc;
clf;    %
%白色背景
axis([-2,2,-2,2]);
xlabel('X轴');
ylabel('Y轴');
%四周的边框
box on;

%绘图区域
t=0:0.02:10;  
Nt=size(t,2);
x=2*cos(t(1:Nt));
y=sin(t(1:Nt));
%循环绘图
for i=1:Nt;
    cla;        %清除坐标去
    hold on;
    plot(x,y)
    plot(x(i),y(i),'o');
    frame=getframe(gcf);    %以截图的方式保留绘制过程
    imind=frame2im(frame);
    [imind,cm] = rgb2ind(imind,256);
    if i==1
         imwrite(imind,cm,'test.gif','gif', 'Loopcount',inf,'DelayTime',1e-4);
    else
         imwrite(imind,cm,'test.gif','gif','WriteMode','append','DelayTime',1e-4);
    end
end
% --------------------- 
% 作者：Deng笨蛋 
% 来源：CSDN 
% 原文：https://blog.csdn.net/u010480899/article/details/78234884 
% 版权声明：本文为博主原创文章，转载请附上博文链接！