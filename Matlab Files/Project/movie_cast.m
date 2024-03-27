function people = movie_cast(actors,movie)
    people = [];
    for ii = 1:length(actors())
        if actors(ii) == movie
                    people(end+1) = actors(ii+length(actors));
        end
    end
    people = people';
end