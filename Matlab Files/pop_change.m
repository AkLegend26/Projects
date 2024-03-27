function [increase, pct_increase] = pop_change(initial_total, years)
    seconds = 60 * 60 * 24 *365;
    seconds = years * seconds;
    births = round(seconds / 8);
    deaths = round(seconds / 12);
    migrants = round(seconds / 645);
    
    increase = births + migrants - deaths;
    pct_increase = 100 * increase / initial_total;
end