function [time_min] = Solar_time(miles)
    light_min = 300,000 / 60;
    speed_light = light_min;
    miles = miles * 1.609;
    time_min = miles / speed_light;
end