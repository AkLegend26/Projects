function x = find_the_primes(v)
    x = 0;    
    for ii = 1:length(v)
        if isprime(v(ii))
            x = x +1;
            fprintf('Elemnt #%d is %d, a prime\n'ii, v(ii));
        end
    end
end   
        
        