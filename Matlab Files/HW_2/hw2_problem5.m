function res=hw2_problem5(key,answers)
if size(key)==size(answers)
  n=key==answers;
  res=(length(n(n>0)));
else
   res = -1; 
end