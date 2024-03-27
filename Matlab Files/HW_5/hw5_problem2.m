function ans = hw5_problem2(a, b)

    if(~ischar(a) || ~ischar(b))
        ans = -1;
        return;
    end
  
    ans = [];
    i = length(a);
    j = length(b);
    carry = 0;
    while i >= 1 && j >= 1

    if(a(i) < '0' || a(i) > '9' || b(j) < '0' || b(j) > '9')
        ans = -1;
        return;
    end
    total = str2num(a(i)) + str2num(b(j)) + carry;
    ans = [num2str(mod(total,10)) ans];
    carry = fix(total/10); 
    i = i - 1; 
    j = j - 1; 
    end
 
    while i >= 1

        if(a(i) < '0' || a(i) > '9')
            ans = -1;
            return;
        end

        total = str2num(a(i)) + carry;

        ans = [num2str(mod(total,10)) ans];
        carry = fix(total/10); 
        i = i - 1; 
    end

    while j >= 1
        if(b(j) < '0' || b(j) > '9')
            ans = -1;
            return;
        end

    total = str2num(b(j)) + carry;

    ans = [num2str(mod(total,10)) ans];
    carry = fix(total/10); 
    j = j - 1;
    end
    if(carry > 0)
        ans = [num2str(carry) ans];
    end
end
