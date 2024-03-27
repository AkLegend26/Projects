function films = search_for_movie(movies,keyword)
 films = [];
 keyword = upper(keyword); 
 for ii = 1:length(movies)
 if ~isempty(strfind(upper(movies(ii).title),keyword))
 films(end+1) = ii;
 end
 end
end