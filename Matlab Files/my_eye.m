function I = my_eye(n)
    I = zeros(n);
    I(1:n+1:end) = 1;
end