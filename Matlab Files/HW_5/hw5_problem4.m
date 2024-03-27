function ans = hw5_problem4(v)
    ans = false(numel(v));
    for k = 1:numel(v)
        ans(k,v{k}) = true;
    end
end