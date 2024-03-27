function ans = e4_border(a)
if isvector(a)
    ans = sum(a)
else
    [row col]= size(a);
    b = sum(a(1,1:row));
    c = sum(a(1:col));
    d = sum(a(:,col));
    e = sum(a(row,:));
    f = b +c+d+e;
    
    g = a(1,1);
    h = a(row,1);
    i = a(row,col);
    j = a(1,col);
    k = g+h+i+j;
    
    ans = f - k;
    
end