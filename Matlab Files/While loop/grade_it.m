function score = grade_it(scores)
    scores = flip(sort(scores));
    w = [40 25 20 10 5]'/100;
    score = scores * w;
end