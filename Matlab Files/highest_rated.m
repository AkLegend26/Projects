function films = highest_rated(movies)
films = [];
j = [];
for ii = 1: length(movies)
    j(end+1) = movies(ii).rating; 
end
for jj = 1:length(j)
    if j(jj) == max(j)
        films(end+1) = jj;
    end
end