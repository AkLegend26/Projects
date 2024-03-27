function ratings = ratings_per_year(movies)
ratings = [];
c = 2000;
while c < 2022 
avg_rating = [];
for ii = 1:length(movies)
    if str2double(movies(ii).release(1:4)) == c
        avg_rating(end+1) = movies(ii).rating;
    end
end
ratings(end+1) = (sum(avg_rating)/length(avg_rating));
c = c+1;
end
end
        
        