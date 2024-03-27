function f = fiibo(n)
    f = [1 1];
    for ii = 3:n
        f(ii) = f(ii-2) + f(ii-1);
    end
    f = f(1:n);
end