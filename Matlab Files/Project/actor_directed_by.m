function films = actor_directed_by(directors,actors,director,actor)
d_movie = [];
a_movie = [];
for ii = 1:length(directors)
    if director == directors(ii,2)
        d_movie(end+1) = directors(ii);
    end
end
for ii = 1:length(actors)
    if actor == actors(ii,2)
        a_movie(end+1) = actors(ii);
    end

end
films = intersect(d_movie,a_movie);

        