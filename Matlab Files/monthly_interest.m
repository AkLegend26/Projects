function amount = monthly_interest
    balance = input('Enter balance:');
    apr = input('Enter interest rate (APR):');
    monthly_rate = (apr*0.01) / 12;
    amount = balance *monthly_rate;
end