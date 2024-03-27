function people = movie_directors(directors,movie)
people = [];
name = [];
for ii =1:length(directors)
    if directors(ii) == movie
        people(end+1) =directors(ii+length(directors));
    end
end

