function [c] = bigly(A,B)
    c = A;
    c(A<B) = B( A< B);
end