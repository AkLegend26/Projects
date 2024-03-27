function films = r_rated(movies)
films = [];
for ii = 1:length(movies)
    if movies(ii).mpaa == 'R'
        films(end+1) = ii;
    end
end
end