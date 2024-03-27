function s = e2_sumdiag_answer(A)
    lng = length(A);
    s = 0;
    for ii = 1:lng
        s = s+A(ii,ii) + A(ii,end-ii+1);
    end
    if rem(leng,2) ==1
        s = s-A((lng+1)/2,(lng+1)/2);
    end
end