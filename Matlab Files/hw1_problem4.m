function [income] = hw1_problem4(rate,price)
    income_per_product = (rate*112).*(price)
    income = sum(income_per_product)
end