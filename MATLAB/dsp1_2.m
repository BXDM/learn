%dsp1_2
x = -2*pi:pi/100:2*pi;
y = sin(x);
stem(x,y);
xlabel('x'),ylabel('sin(x)');
grid on