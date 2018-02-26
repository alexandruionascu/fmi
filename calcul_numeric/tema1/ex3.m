hold on;
a = 0.5;
b = 1.5;
limit = [a b];
fplot(@(x) e.^x - 2, limit);
fplot(@(x) cos(e.^x - 2), limit);
eps = 10^(-5);
f = @(x) (e.^x - 2 - cos(e.^x - 2));
x = binary_search(f, a, b, eps)
plot(x, f(x), 'ro');
hold off; 