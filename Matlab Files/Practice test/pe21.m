function x = pe21(hr, min)
    
    if hr ~= floor(hr) || min ~= floor(min)
        x = false;
    elseif sum(size(hr))>2 | sum(size(min))>2
        x = false;
    elseif (0<= hr) && (hr<=23)
        hr = hr;
        if (0<= min) && (min <=59)
            min = min;
        x = true;
        else
        x = false;
        end
    else 
        x = false
    end