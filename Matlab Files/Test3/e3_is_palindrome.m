function z = e3_is_palindrome(a)
    z = false;
    a = upper(a);
    b = length(a);
    tc = 0;
    for ii = 1:length(a)
        c = a(abs(ii-(length(a)))+1)
        if a(ii) == a(abs(ii -(length(a)))+1)
            tc = tc + 1;
        end
    end
    if tc == b
        z = true;
    end
end

        