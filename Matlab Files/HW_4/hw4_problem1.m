function [ s,index ] = hw4_problem1( v,n)

s=sum(v(1:n));
index=1;
for ii=1:length(v)-n+1
    if sum(v(ii:ii+n-1))>s;
    s =sum(v(ii:ii+n-1));
    index = ii;
    end
end
end