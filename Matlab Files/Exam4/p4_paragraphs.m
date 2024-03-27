function p4_paragraphs(fname)
para = 0;
for ii = length(sum(fget1(fname)))
     if fget1(fname) == []
         para = para+1;
     end
end