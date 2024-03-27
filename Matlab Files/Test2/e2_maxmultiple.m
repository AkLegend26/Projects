function ans = e2_maxmultiple(A, k)
A = A';
ans = A(mod(A,k)==0)';
ans = max(ans)
if ans == [];
    ans = 0;
end
    