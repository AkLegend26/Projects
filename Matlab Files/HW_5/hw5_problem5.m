function ans = hw5_problem5(M)
[row, col] = size(M);
ans = cell(row,1);
for i = 1:row
    vector = [];
    for j = 1:col 
        if M(i, j) == 1
            vector = [vector j]; 
        end
    end
    ans{i} = vector; 
end