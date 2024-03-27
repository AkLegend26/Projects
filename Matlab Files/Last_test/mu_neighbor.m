function [num,index] = mu_neighbor(a)

for ii = 1:length(a)-1
if a(ii) == a(ii+1)
    num = a(ii);
    index = ii;
    return
end
end
num = 0;
index = 0;
end