function m = e2_maxmultipleanswer(A,k)
    m = 0;
    v= v(~rem(v,k));
    if ~isempty(v)
        m= max(v);
    end
end