function d = mu_movavg(a,b)
d = [];
e = b-1;
for ii = 1:length(a)-(e)
    c = a(ii:e+1);
    d(end+1) = sum(c)/b;
    e = e+1;
end
    