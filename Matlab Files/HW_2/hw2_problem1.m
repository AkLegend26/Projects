function [a] = hw2_problem1(score)
    if score >= 91
        a = ('A')
    elseif score >= 81
        a = ('B')
    elseif score >= 71
        a = ('C')
    elseif score >= 61
        a = ('D')
    else
        a = ('F')
    end
end