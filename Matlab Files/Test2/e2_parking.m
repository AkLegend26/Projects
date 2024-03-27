function ans = e2_parking(day, hour)
    if days >=1 && day <=5
        if hour >= 9 && hour < 19
            ans = false
        else ans = true
        end
    elseif day==6
        if hour >=10 && hour <14
            ans = false
        else ans = true
        end
    else ans = true
    end
end
            