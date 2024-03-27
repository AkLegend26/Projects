function m = hw5_problem3(year,month,days,startDay)
monthNames={'January', 'February', 'March', 'April', 'May', 'June', 'July','August', 'September', 'October', 'November', 'December'};
dayNames={'Sunday','Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday'};
day=startDay;
for i=1:days
    m(i).year=year;
    m(i).month=monthNames{month};
    m(i).date=i;
    m(i).day=dayNames{day};
    day=day+1;
    if day>7
        day=1;
    end
end
end

