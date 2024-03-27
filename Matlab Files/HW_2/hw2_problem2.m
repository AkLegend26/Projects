function x = hw2_problem2(y1, m1, d1, y2, m2, d2)
tmp1 = y1*10000+m1*100+d1;
tmp2 = y2*10000+m2*100+d2;
if tmp1>tmp2
    x=-1;
elseif tmp1<tmp2
    x=1;
else
    x=0;
end
