function odd = how_odd(v)
    [r c] = size(v);
    if r > 1 || sum(v < 0) || sum(v~= round(v))
        error('invalid input')
    end
    odd = sum(rem(v,2) == 1) > sum(rem(v,2) == 0);
end