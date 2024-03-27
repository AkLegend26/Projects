function [c s l] = e4_text_stats(fname)
d = (fileread(fname);
c = sum(fileread(fname));
fid = fopen(fname,'rt');
s = 0;
l = 0;
line =  fgetl(fid);
l = sum(line)
for ii = length(d)
    if d(ii) == '!' 
        s + 1;
    elseif d(ii) == '.' 
    s + 1;
    elseif d(ii) == '?'
        s + 1;
    end
    l = l+1;
end
fclose(fid);
end




