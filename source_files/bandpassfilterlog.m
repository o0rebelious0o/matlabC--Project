M = dlmread('bandPassFilter.txt', '\t');
M';
x=log(ans(1,:));
y1=ans(2,:);
y2=ans(3,:);
plot = plotyy(x,y1,x,y2,'plot');
grid();
title('Band Pass Filter Log Plot','FontWeight','bold');
xlabel('Frequency 2.7^x (Hz)');
axes(plot(1));
ylabel('Magnitude Gain');
axes(plot(2));
ylabel('Phase Shift');