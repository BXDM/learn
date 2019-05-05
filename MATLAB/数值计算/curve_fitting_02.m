x=[0.0 0.1 0.2 0.3 0.5 0.8 1.0]
y=[1.0 0.41 0.50 0.61 0.91 2.02 2.46]
xishu1=polyfit(x,y,3)
xishu2=polyfit(x,y,4)
y1=polyval(xishu1,x)
y2=polyval(xishu2,x)
plot(x,y,'-',x,y1,'o',x,y2,'*')
legend('y','fit1','fit2')
