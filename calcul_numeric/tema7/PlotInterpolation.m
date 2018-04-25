function [x_grafic, E] = PlotInterpolation(n, a, b, f, met, name)
    sample_size = 100;
    x_grafic = linspace(a, b, sample_size)';
    x_calcul = linspace(a, b, n + 1)';
    y_calcul = f(x_calcul);
    hold on;
    plot(x_grafic, f(x_grafic), 'r-');
    plot(x_calcul, y_calcul, 'ro');
    y_polinom = zeros(sample_size, 1);
    for i = 1:sample_size
        y_polinom(i) = met(x_calcul, y_calcul, x_grafic(i));
    end
    plot(x_grafic, y_polinom, 'b-');
    
    title(name);
    
    E = f(x_grafic) - y_polinom;
end