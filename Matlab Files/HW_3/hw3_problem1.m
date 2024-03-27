function ans = hw3_problem1(A)
if A(1:end)>0 & floor(A(1:end))== A(1:end)
   A(rem(A(1:end),2)~=0) = 2*A(rem(A(1:end),2)~=0);
   ans = A;
else
    ans = [];
end

