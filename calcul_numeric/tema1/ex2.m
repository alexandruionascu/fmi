f = @(x) (x.^3 - 7 * (x.^2) + (14 * x) - 6)
fplot(f, [0, 4])
hold on 
eps = 0.00001
x1 = binary_search(f, 0, 1, eps)
x2 = binary_search(f, 1, 3.2, eps)
x3 = binary_search(f, 3.2, 4, eps)
plot(x1, f(x1),'r*')
plot(x2, f(x2), 'r*')
plot(x3, f(x3), 'r*')
