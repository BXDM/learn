clear;
clc;

k2 = 1.0;
x = -4:0.1:50;
time = 0:0.1:30;
f = zeros(length(time),length(x));

for i = 1:length(time)
    t = time(i);
%     f(i,:) = cos(x-t) + cos(1.2*x-k2*t);
    f(i,:) = cos(x-t); 
end

%随着时间变化，空间振动形态
figure(1)
ampli = f(1,:);
h1 = plot(x,ampli,'YDataSource','ampli');
hold on
h2 = plot(x(141),ampli(141),'ko','YDataSource','ampli(141)');
line([10,10],[-2,2],'LineStyle','--','Color','m');
xlabel('x');
ylabel('y');
title('y = cos(ωt-kx)');
xlim([-4,50]);
ylim([-2,2]);
set(gca,'DataAspectRatio',[5 1 1])
filename = 'spatialVibration.gif';
for i = 1:length(time)
    ampli = f(i,:);
    refreshdata(h1,'caller') 
    refreshdata(h2,'caller') 
	drawnow
    frame = getframe(1);
    im = frame2im(frame);
    [A,map] = rgb2ind(im,256); 
	if i == 1
		imwrite(A,map,filename,'gif','LoopCount',Inf,'DelayTime',0.00001);
	else
		imwrite(A,map,filename,'gif','WriteMode','append','DelayTime',0.00001);
    end
    %pause(0.0001)
end
