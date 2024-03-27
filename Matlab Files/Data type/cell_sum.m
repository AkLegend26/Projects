function s = cell_sum(in)
    s = 0;[r c] = size(in);
    for ii = 1:r
        for jj = 1:c
            if isnumeric(in{i,jj})
                s = s + sume(in{ii,jj}(:));
            end
        end
    end
end