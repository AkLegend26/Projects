function f = fibo(n)
    if n == 1
        f = 1;
    else
        f = [1 1];
        for ii = 3:n
            f(ii) = f(ii-2) + f(ii-1);
        end
    end
end