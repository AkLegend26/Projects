function [c,b] = hw1_problem3(a)
    c = a
    b = a
    c([1,2], [end-1,end]) = 0
    b([1,2],[1:end-2]) = 0
    b([3:end],[1:end]) = 0
end