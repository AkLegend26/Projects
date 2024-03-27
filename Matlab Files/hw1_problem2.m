function [v] = hw1_problem2(dist, spd)
    x = dist
    y = (spd / 1.60934)
    v = (x/y) * 60
end