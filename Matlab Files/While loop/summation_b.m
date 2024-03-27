function k = summation_b(x,Smin)
    S = 0;
    k = 0;
    while S < Smin && k < 1e6
        S = S + x.^k;
        k = k + 1;
        if k >= 1e6
            fprintf('sum does not seem to converge..')
            return;
        end
        k = k - 1;
    end
end
    