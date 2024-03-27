function m= hw2_problem3(hr1,min1,dur1,hr2,min2,dur2) 
    start_movie_1 = hr1*60 + min1;
    end_movie_1 = start_movie_1 + dur1;
    start_movie_2 = hr2*60 + min2;
    end_movie_2 = start_movie_2 + dur2;

    if start_movie_1 < start_movie_2 && end_movie_1 > end_movie_2
        m = false;
    elseif start_movie_1 < start_movie_2 && end_movie_1 > start_movie_2
        m = false;
    elseif start_movie_2 < start_movie_1 && end_movie_2 > end_movie_1
        m = false;
    elseif start_movie_2 < start_movie_1 && end_movie_2 > start_movie_1
        m = false;
    else 
        if start_movie_1 < start_movie_2 && (start_movie_2 - end_movie_1) <= 30
            m = true;
        else if (start_movie_2 < start_movie_1) && (start_movie_1 - end_movie_2) <= 30
            m = true;
        else
            m = false;
        end
    end
end
