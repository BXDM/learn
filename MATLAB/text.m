cla;

for i = 300;
    x = -2*pi:pi/10:2*pi;
    y = sin(x);
    comet(x,y);
    pause(0.1);
    %画图程序
    frame=getframe(gcf);    %以截图的方式保留绘制过程
    imind=frame2im(frame);
    [imind,cm] = rgb2ind(imind,256);
    if i==1
         imwrite(imind,cm,'test.gif','gif', 'Loopcount',inf,'DelayTime',1e-4);
    else
         imwrite(imind,cm,'test.gif','gif','WriteMode','append','DelayTime',1e-4);
    end
end