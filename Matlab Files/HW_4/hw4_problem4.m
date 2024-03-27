function [n, s] = hw4_problem4(limit)
    s = 0;
    k = 1;
    while s <= limit
        s = s + (1/k);
        k = k + 1;
    end
    n = k-1;
end