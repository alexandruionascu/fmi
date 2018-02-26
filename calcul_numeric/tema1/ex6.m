f = @(x) x.^3 - 7 * x.^ 2 + 14 * x - 6;
df = @(x) 3 * x^2 - 14 * x + 14;
hold on;
fplot(f, [0 4]);
eps = 10^(-3);
x1 = newton_method(f, df, 1, eps);
x2 = newton_method(f, df, 2, eps);
x3 = newton_method(f, df, 4, eps);

plot(x1, f(x1), 'ro');
plot(x2, f(x2), 'ro');
plot(x3, f(x3), 'ro');

hold off;