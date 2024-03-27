function [y,k]=hw4_problem5(delta)
y=0;
k=0;
t=1;
while(1)
    y=y+1/t;
if(abs(y-exp(1))<delta)
    break;
end
k=k+1;
t=t*k;
end
end