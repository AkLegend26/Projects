function people = find_person(persons, name)
    people = [];;
    for ii = 1:length(persons)
        if ~isempty(strfind(upper(persons(ii).name),upper(name)))
            people(end+1) = ii;
        end
    end
end