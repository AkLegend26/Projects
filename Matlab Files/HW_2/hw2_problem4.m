function p=hw2_problem4(c0,c,x)
    N = length(c);
    n=1:1:N;
    d=size(c);
    if(isempty(c))
            p=c0;
    end
    if N==1
            p= c0+(c*x);
    end 
    if N>1
        if d(1)==1
            p = c0+(sum(c(n).*(power(x,n))));
        else 
            c=c'
            p = c0+(sum(c(n).*(power(x,n))));
          end
      end