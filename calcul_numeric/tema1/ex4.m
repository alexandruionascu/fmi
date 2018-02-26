f = @(x) x.^2 - 3;
x = binary_search(f, 0, 2, 10^(-5))