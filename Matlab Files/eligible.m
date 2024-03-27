function [house senate] = eligible(age, citizen)
    if age < 0 || citizen < 0
        error('invalid input');
    end
    house = false;
    senate = false;
    if age >=30 && citizen >= 9
        fprintf('senate')
        senate = true
    else
        fprintf('Not eligible boi')
    end
    
    if age >=25 && citizen >= 7
        fprintf('house')
        house = true
    else
        fprintf('not eligible boi')
    end
end