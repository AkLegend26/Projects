function s = sparse2matrix(cv)
    row = cv{1}(1);
    col = cv{1}(2);
    val = cv{2};
    s = zeros(row,col) + val;
    for ii = 3:length(cv)
        r = cv{ii}(1);
        c = cv{ii}(2);
        v = cv{ii}(3)
        s(r,c) = v;
    end
end