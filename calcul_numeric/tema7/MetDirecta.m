function y = MetDirecta(X,Y,x)
    n = length(X);
    A = zeros(n, n);
    for i = 1:n
        A(:, i) = X .^ (i - 1);
    end
    b = Y;
    
    a = GaussPivTot(A, b);
    
    y = 0;
    for i=1:n
        y = y + a(i) * x .^ (i - 1);
    end
    y = polyval(fliplr(a), x);
end