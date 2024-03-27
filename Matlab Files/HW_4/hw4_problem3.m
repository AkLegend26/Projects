function p=hw4_problem3(k)
p=0;
while(p<1000)
if(isprime(p) && isprime(p+k))
break;
end
p=p+1;
end
if(p==1000)
    p=0;
end
end