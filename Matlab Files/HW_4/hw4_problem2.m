function ans = hw4_problem2(v)
    ans = true;
    
    [row, col] = size(v);
    
    if isscalar(v)
        ans = true;
        return
    elseif ~ismatrix(v)
        ans = false;
        return
    elseif row ~= 1
        ans = false;
        return
    else
        for i = 2:length(v)
            if v(1,i) < v(1,i-1)
                ans = false;
            end
        end
    end
end