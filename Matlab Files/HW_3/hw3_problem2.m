function ans = hw3_problem2(A)
    ans = -Inf
    for j = 1:length(A(:))
        if A(A > ans) 
            ans = A(j);
        end
    end