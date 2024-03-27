function w = larger(v)
    w = [];
    for ii = 1:length(v)
        if v(ii) > ii
            w = [w v(ii)];
        end
    end
end