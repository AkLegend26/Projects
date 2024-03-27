function ans = hw5_problem1(ans)
    i = isstrprop(ans,'upper');
    ans(i) = char(155-ans(i));
    i = isstrprop(ans,'lower');
    ans(i) = char(219-ans(i));
end