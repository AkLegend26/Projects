scores = randi([80 100], 20, 4);
weights = [40 30 20 10];
avg = scores * weights' / sum(weights)a
