function median = e4_median(a)
a = sort(a)
if rem(length(a),2) ~= 0
for ii = 1:2
    f = floor(length(a)/2)+1;
    median = a(f);
end
else
    for ii = 1:2
        c = length(a)/2;
        d = a(c);
        e = a(c+1);
        median = (d+e)/2;
    end
end
end
