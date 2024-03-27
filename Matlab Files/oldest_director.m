function people = oldest_director(directors,persons)
people = [2000];
directors = directors(:,2);
for ii = 1:length(directors)
    if ~isempty(persons(directors(ii)).DOB)
        if str2double((persons(directors(ii)).DOB(1:4))) < people;
            people = ii;
        elseif str2double((persons(directors(ii)).DOB(1:4))) == people;
            people(end+1) = ii;
        end
    end
end
end