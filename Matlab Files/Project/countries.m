function states = countries(movies)
states = {};
for ii = 1:length(movies)
    j = split(movies(ii).countries);
    for kk = 1:length(j)
        states{end+1} = j{kk};
    end
end
states = unique(states);
states = char(states(~cellfun('isempty', states)));

end
