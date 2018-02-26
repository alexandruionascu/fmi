f = @(x) 8*x.^3 + 4*x - 1;
a = 0;
b = 1;
# dupa primul pas 
x = 0.5;
f(x) * f(0) < 0; # deci cautam in [a, x]
x = 0.25;