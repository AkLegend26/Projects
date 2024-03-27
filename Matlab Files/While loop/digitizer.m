function digits = digitizer(num)
    if ~isscalar(num) || num < 0 || floor(num) ~= num
        error('Invalid input');
    end
    digits = [];
    while num > 0
        digits = [rem(num,10) digits];
        num = floor(num/10);
    end
end