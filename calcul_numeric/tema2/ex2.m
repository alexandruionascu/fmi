# exercitiul a
f = @(x) x.^3 - 18 * x - 10;
# f'(x) = 3x^2 - 18 -> x ~= 2.44
a = -5;
b = 5;
eps = 10^(-3);
figure 1;
hold on;
fplot(f, [a b]);
# exercitiul d
x1 = secant_method(f, -5, -2.5, -5, -4, eps);
x2 = secant_method(f, -2.3, 2.3, -2.3, 2.3, eps);
x3 = secant_method(f, 3, 5, 3, 5, eps);
plot(x1, f(x1), 'ro');
plot(x2, f(x2), 'ro');
plot(x3, f(x3), 'ro');
hold off;

% f''(x) = 0 -> 6x = 0 -> x = 0
x1 = false_position_method(f, -5, -2.5, eps);
x2 = false_position_method(f, -2.5, -0.2, eps);
x3 = false_position_method(f, 3, 5, eps);
figure 2;
hold on;
fplot(f, [a b]);
plot(x1, f(x1), 'ro');
plot(x2, f(x2), 'ro');
plot(x3, f(x3), 'ro');
hold off;
