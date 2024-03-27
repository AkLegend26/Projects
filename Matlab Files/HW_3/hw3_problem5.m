function Arr = hw3_problem5(X)
[m n] = size(X);
vec = [];
for i = 1:m
    for j = 1:n
        sum = i+j;
        if (X(i,j) > sum)
            var = [i j];
            vec = [vec;var];
        end
    end
end

Arr = vec;
end