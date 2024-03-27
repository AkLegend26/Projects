function [a, k] = almost_pi(delta)
    delta = abs(delta);
    k=0;
    a = 0;
    while abs(pi-a) > delta
        a = a + sqrt(12)*(-3)^(-k) / (2*k+1);
        k = k + 1;
    end
end