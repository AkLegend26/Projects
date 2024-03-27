function a = odd_eliminator(a)
    a(rem(a,2) == 1) = a(rem(a,2) == 1) +1;
end