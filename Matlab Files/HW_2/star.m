function star(n)
v = [1:n n-1:1];
for numstar = v
    for k = 1:numstar
        fprintf('*');
    end
    fprintf('\n');
end
end