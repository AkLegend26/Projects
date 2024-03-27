function gernerationxyz(birth_year)
    birth_year = input();
    if birth_year < 1966
        fprintf('Too old!\n')
    
    elseif birth_year >= 2012
        print('Too young!')
    end
end