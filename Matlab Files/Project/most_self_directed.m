function [person films] = most_self_directed(directors,actors)
person = [];
films  = [];
curr_max = 0;
num_directors = unique(directors(:,2));
for ii = 1:length(num_directors)
    c = directors(:,2) == num_directors(ii);
    m_direc = directors(c,1);
    d = actors(:,2) == num_directors(ii);
    m_actor = actors(d,1);
    
    common = intersect(m_direc,m_actor);
    if length(common)> curr_max
        curr_max = length(common);
        films = common';
        person = num_directors(ii);
        
    end
end