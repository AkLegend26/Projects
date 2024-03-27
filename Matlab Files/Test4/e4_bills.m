function bills = e4_bills(total_sum, num_bills, ten_per_twenty, one_minus_five);
A = [1 5 10 20; 1 1 1 1; 0 0 2 1; 2 1 0 0];
b = [total_sum; num_bills ; ten_per_twenty ; one_minus_five];
bills = A\b;
end