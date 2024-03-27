function S = summation_a(x,N)
    S = 0;
    for ii = 0:N
        S = S + x.^ii;
    end
end
    