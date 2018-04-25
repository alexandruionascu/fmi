f = @(x) sin(x);
n = 10;
a = -pi / 2;
b = pi / 2;

figure;
subplot(4, 1, 1);
[x_dir, e_dir] = PlotInterpolation(n, a, b, f, @MetDirecta, "metoda directa");
subplot(4, 1, 2);
[x_lag, e_lag] = PlotInterpolation(n, a, b, f, @MetLagrange, "metoda Lagrange");
subplot(4, 1, 3);
[x_n, e_n] = PlotInterpolation(n, a, b, f, @MetN, "metoda Newton");
subplot(4, 1, 4);
[x_ndd, e_ndd] = PlotInterpolation(n, a, b, f, @MetNDD, "metoda NDD");

figure;

subplot(4, 1, 1);
plot(x_dir, e_dir, 'b-');
title("metoda directa");

subplot(4, 1, 2);
plot(x_lag, e_lag, 'b-');
title("metoda Lagrange");

subplot(4, 1, 3);
plot(x_n, e_n, 'b-');
title("metoda Newton");

subplot(4, 1, 4);
plot(x_ndd, e_ndd, 'b-');
title("metoda NDD");

% N maxim
% Metoda Newton           | 62
% Metoda Lagrange         | 66
% Metoda NDD              | 71
% Metoda Directă          | 71