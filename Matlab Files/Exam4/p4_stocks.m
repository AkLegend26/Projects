function counts = p4_stocks(count,prices,gains,investment,profit);

num_list = [];
for ii = length(prices)
    a = prices(ii) * (gains(ii)/100);
    num_list(end+1) = a;
end

num_3 = floor(profit / num_list(1));
if rem(profit,num_list(1)) ~= 0
    num_2 = floor(rem(profit , num_list(1)),num_list(0));
    if rem(rem(profit , num_list(2)),num_list(0)) ~= 0
        num_1 = floor(rem(rem(profit , num_list(1))),num_list(0));
    end
end
counts = [num_1,num_2,num_3];
