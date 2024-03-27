function ans = e2_hockey(t1, t2)
        if sum(t1)>sum(t2)
            ans = 1
        elseif sum(t2)>sum(t1)
            ans = 2
        else
            ans = 0
        end
  