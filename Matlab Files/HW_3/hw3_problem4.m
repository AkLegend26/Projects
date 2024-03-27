function summa = hw3_problem4(M)
[a b] = size(M);
if a>1
    
 for n = 1:a;
    for m = 1:b;
        if n>m;
            M(n,m) = 0;
            summa = sum(sum(M));
        end
    end
 end 
else 
    summa = sum(M);
end
        
