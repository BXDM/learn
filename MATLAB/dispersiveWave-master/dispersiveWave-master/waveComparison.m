clear;
clc;

x = -4:0.1:50;
time = 0:0.1:50;
f1 = zeros(length(time),length(x));
f2 = zeros(length(time),length(x));

for i = 1:length(time)
    t = time(i);
    ampli1 = 0;
    ampli2 = 0;
    for k  = 1:100
        ampli1 = ampli1 + 0.07*(exp(-(0.1*k-3).^2)+exp(-(0.1*k+3).^2)).*...
            cos(0.1*k.*x-0.1*k./sqrt(1+0.0*(0.1*k).^2).*t);
        ampli2 = ampli2 + 0.07*(exp(-(0.1*k-3).^2)+exp(-(0.1*k+3).^2)).*...
            cos(0.1*k.*x-0.1*k./sqrt(1+0.1*(0.1*k).^2).*t);
    end
	f1(i,:) = ampli1; 
    f2(i,:) = ampli2;
end

%随着时间变化，空间振动形态
figure(1)
ampli1 = f1(1,:);
h1 = plot(x,ampli1,'YDataSource','ampli1');
hold on
ampli2 = f2(1,:);
h2 = plot(x,ampli2,'YDataSource','ampli2');
h3 = plot(x(141),ampli1(141),'ko','YDataSource','ampli1(141)');
h4 = plot(x(141),ampli2(141),'ro','YDataSource','ampli2(141)');

line([10,10],[-1.5,1.5],'LineStyle','--','Color','m');
title('波的空间振动');
legend('α = 0','α = 0.1');
xlabel('x');
ylabel('Amplitude');
xlim([-4,50]);
ylim([-1.5,1.5]);
set(gca,'DataAspectRatio',[5 1 1])

filename = 'spatialVibration.gif';
for i = 1:length(time)
    ampli1 = f1(i,:);
    ampli2 = f2(i,:);
    refreshdata(h1,'caller') 
    refreshdata(h2,'caller') 
    refreshdata(h3,'caller') 
    refreshdata(h4,'caller') 
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

