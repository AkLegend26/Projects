function [a] = psquare(n)
    a = [1:n];
    b = [1:n]';
    c = (a.*b);
    d = diag(c);
    j =d(n>=d);
    f = j'
end
    
    