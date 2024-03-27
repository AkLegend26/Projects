function result = closest_planet(planets)
curr_min = Inf;
idx = 0;
for ii = 1:length(planets)
    distance = planets(ii).dist_from_sun;
    if dist< curr_mn
        curr_mn = distance;
        idx = ii;
    end
end
result = planets(idx);
end
    