function a = e3_gcd(a,b)
   
        a = a;
        b = b;
        while a ~= b
            c = max(a,b);
            d = min(a,b);
            e = c-d;
            if a > b
                a = e;
                b = b;
            elseif b > a
                b = e;
                a = a;
            end
        end
        
    end

    
            
