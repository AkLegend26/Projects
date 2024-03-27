function [person films] = directed(directors,actors)
films = [];
z = unique(directors(:,2));
a=0;
for ii = 1:length(z)
    x = directors(directors(:,2) == z(ii),1);
    y = actors(actors(:,2) == z(ii),1);
    h = intersect(x,y);
    if length(h) > a;
        a = length(h);
        person = z(ii);
        films = h;
    end
end
