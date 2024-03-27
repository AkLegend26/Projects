function [A avg] = myrandi(n,row,col)
   if nargin < 1
       error('Expected atleast one input')
   end
   if nargin == 1
       row = 1;
       col = 1;
   elseif nargin == 2
       col = row;
   end
   A = ceil(n * rand(row,col));  
   if nargout > 1
       avg = mean(A(:));
end