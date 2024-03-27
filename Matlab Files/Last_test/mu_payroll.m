function my_payroll(hours_worked, holidays,rate)

work = [];
[rows col] = size(hours_worked);
for ii = 1:rows
    for jj = 1: col
        work(end+1) = hours_worked(ii,jj);
    end
end

more_hours = [];
    
for ii = 1:length(work)
    if work(ii) > 8
        more_hours(end+1) = work(ii) *1.25;
    else
        more_hours(end+1) = work(ii);
    end
end

rates = [];
for ii = 1:length(holidays)
    if holidays(ii) == true
        rates(end+1) = more_hours(ii) * 1.25;
    else
        rates(end+1) = more_hours(ii);
    end
end

gross = [];

for ii = 1:rows
    gross(end+1) = rates(ii) * rate(ii);
end

ans = sum(gross)