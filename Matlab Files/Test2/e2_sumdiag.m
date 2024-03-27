function ans = e2_sumdiag(A)
   [r, c] = size(A);
   x = []; 
   for ii = 1:r
        for jj = 1:c
            x(end+1) = A(ii,jj);
        end
   end
   ans = sum(x);
            