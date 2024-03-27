function [maxi mini] = max_min(A)
    mini = min(min(A));
    maxi = max(A(:));
end