function s = e2_numbers(k)
    if ~isscalar(k) || k<1 || floor(k) ~= k
        s = -1;
        return;
    end
    if k == 1
        s = 1;
        return
    end
    s(1) = 1;
    s(2) = 10;
    for ii = 3:k
        s(ii)= 2*(s(ii-1)) - s(ii-2) + ii^2;
    end
end