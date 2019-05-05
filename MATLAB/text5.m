% program was executed by matlab
clear;
clc;

alpha = 0.1;
x = -4:0.1:50;
time = 0:0.1:50;
f = zeros(length(time),length(x));

for i = 1:length(time)
    t = time(i);
    ampli = 0;
    for k  = 1:100
        ampli = ampli + 0.07*(exp(-(0.1*k-3).^2)+exp(-(0.1*k+3).^2)).*...
            cos(0.1*k.*x-0.1*k./sqrt(1+alpha*(0.1*k).^2).*t);    
    end
	f(i,:) = ampli;   
end

%随着时间变化，空间振动形态
figure(1)
ampli = f(1,:);
h1 = plot(x,ampli,'YDataSource','ampli');
hold on
h2 = plot(x(141),ampli(141),'ko','YDataSource','ampli(141)');
line([10,10],[-1.5,1.5],'LineStyle','--','Color','m');
xlabel('x');
ylabel('Amplitude');
xlim([-4,50]);
ylim([-1.5,1.5]);
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

%不同位置的时域图像
figure(2)
%
xPos = [0,10,20,40];
xIdx = round((xPos+4.1)/0.1);
nFFT = 2^nextpow2(length(time));
frequence = 10/2*linspace(0,1,nFFT/2+1);

subplot(4,2,1);
plot(time,f(:,xIdx(1)));
xlabel('t');
ylabel('Amplitude');
title('x = 0 处位移');
ylim([-1.5,1.5]);

subplot(4,2,2);
Y = fft(f(:,xIdx(1)),nFFT)/length(time);
plot(frequence,2*abs(Y(1:nFFT/2+1)));
xlabel('f');
ylabel('Amplitude');

subplot(4,2,3);
plot(time,f(:,xIdx(2)));
xlabel('t');
ylabel('Amplitude');
title('x = 10 处位移');
ylim([-1.5,1.5]);

subplot(4,2,4);
Y = fft(f(:,xIdx(2)),nFFT)/length(time);
plot(frequence,2*abs(Y(1:nFFT/2+1)));
xlabel('f');
ylabel('Amplitude');

subplot(4,2,5);
plot(time,f(:,xIdx(3)));
xlabel('t');
ylabel('Amplitude');
title('x = 20 处位移');
ylim([-1.5,1.5]);

subplot(4,2,6);
Y = fft(f(:,xIdx(3)),nFFT)/length(time);
plot(frequence,2*abs(Y(1:nFFT/2+1)));
xlabel('f');
ylabel('Amplitude');

subplot(4,2,7);
plot(time,f(:,xIdx(4)));
xlabel('t');
ylabel('Amplitude');
title('x = 40 处位移');
ylim([-1.5,1.5]);

subplot(4,2,8);
Y = fft(f(:,xIdx(4)),nFFT)/length(time);
plot(frequence,2*abs(Y(1:nFFT/2+1)));
xlabel('f');
ylabel('Amplitude');

%信号的频域图像
figure(3)
k = 1:100;
angFreq = 0.1*k./sqrt(1+0.1*(0.1*k).^2);
Freq = angFreq/(2*pi);
ampFreq = 0.07*(exp(-(0.1*k-3).^2)+exp(-(0.1*k+3).^2));
velFreq = 1./sqrt(1+alpha*(0.1*k).^2);
subplot(2,1,1);
bar(Freq,ampFreq);
xlabel('f');
ylabel('Amplitude');
subplot(2,1,2);
bar(Freq,velFreq);
xlabel('f');
ylabel('phase velocity');
title('α = 0.1');
% program was executed by matlab
clear;
clc;

alpha = 0.1;
x = -4:0.1:50;
time = 0:0.1:50;
f = zeros(length(time),length(x));

for i = 1:length(time)
    t = time(i);
    ampli = 0;
    for k  = 1:100
        ampli = ampli + 0.07*(exp(-(0.1*k-3).^2)+exp(-(0.1*k+3).^2)).*...
            cos(0.1*k.*x-0.1*k./sqrt(1+alpha*(0.1*k).^2).*t);    
    end
	f(i,:) = ampli;   
end

%随着时间变化，空间振动形态
figure(1)
ampli = f(1,:);
h1 = plot(x,ampli,'YDataSource','ampli');
hold on
h2 = plot(x(141),ampli(141),'ko','YDataSource','ampli(141)');
line([10,10],[-1.5,1.5],'LineStyle','--','Color','m');
xlabel('x');
ylabel('Amplitude');
xlim([-4,50]);
ylim([-1.5,1.5]);
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

%不同位置的时域图像
figure(2)
%
xPos = [0,10,20,40];
xIdx = round((xPos+4.1)/0.1);
nFFT = 2^nextpow2(length(time));
frequence = 10/2*linspace(0,1,nFFT/2+1);

subplot(4,2,1);
plot(time,f(:,xIdx(1)));
xlabel('t');
ylabel('Amplitude');
title('x = 0 处位移');
ylim([-1.5,1.5]);

subplot(4,2,2);
Y = fft(f(:,xIdx(1)),nFFT)/length(time);
plot(frequence,2*abs(Y(1:nFFT/2+1)));
xlabel('f');
ylabel('Amplitude');

subplot(4,2,3);
plot(time,f(:,xIdx(2)));
xlabel('t');
ylabel('Amplitude');
title('x = 10 处位移');
ylim([-1.5,1.5]);

subplot(4,2,4);
Y = fft(f(:,xIdx(2)),nFFT)/length(time);
plot(frequence,2*abs(Y(1:nFFT/2+1)));
xlabel('f');
ylabel('Amplitude');

subplot(4,2,5);
plot(time,f(:,xIdx(3)));
xlabel('t');
ylabel('Amplitude');
title('x = 20 处位移');
ylim([-1.5,1.5]);

subplot(4,2,6);
Y = fft(f(:,xIdx(3)),nFFT)/length(time);
plot(frequence,2*abs(Y(1:nFFT/2+1)));
xlabel('f');
ylabel('Amplitude');

subplot(4,2,7);
plot(time,f(:,xIdx(4)));
xlabel('t');
ylabel('Amplitude');
title('x = 40 处位移');
ylim([-1.5,1.5]);

subplot(4,2,8);
Y = fft(f(:,xIdx(4)),nFFT)/length(time);
plot(frequence,2*abs(Y(1:nFFT/2+1)));
xlabel('f');
ylabel('Amplitude');

%信号的频域图像
figure(3)
k = 1:100;
angFreq = 0.1*k./sqrt(1+0.1*(0.1*k).^2);
Freq = angFreq/(2*pi);
ampFreq = 0.07*(exp(-(0.1*k-3).^2)+exp(-(0.1*k+3).^2));
velFreq = 1./sqrt(1+alpha*(0.1*k).^2);
subplot(2,1,1);
bar(Freq,ampFreq);
xlabel('f');
ylabel('Amplitude');
subplot(2,1,2);
bar(Freq,velFreq);
xlabel('f');
ylabel('phase velocity');
title('α = 0.1');
