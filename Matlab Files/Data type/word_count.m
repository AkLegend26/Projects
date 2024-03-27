function n = word_count(txt,word)
    n = 0;
    for ii = 1: length(txt)
        n = n + length(strfind(txt{ii},word));
    end
end