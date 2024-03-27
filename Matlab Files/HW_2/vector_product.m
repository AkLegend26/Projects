function P = array_product(A, B)
    [row col] = size(A);
    for ii = 1:row
        for jj = 1:col
            p(ii,jj) = A(ii,jj) * B(ii,jj);
        end
    end
end
