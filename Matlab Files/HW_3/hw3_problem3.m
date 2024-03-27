function v=hw3_problem3(A)
B = isprime(A);
[a,b] = size(A);
v = [];
for i=1:a
    for j = 1:b
        if B(i,j) == 1
            v=[v, A(i,j)]
        end
    end
end
end