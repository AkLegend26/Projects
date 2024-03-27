function ans = e3_audio_convert(a)
    ans = double([]);
    for ii = 1:length(a)
       
    if a(ii) == 0
        ans = -1;
    elseif a(ii) ~= 0
        ans = double(a/65535)
    end
    end
end
        
    