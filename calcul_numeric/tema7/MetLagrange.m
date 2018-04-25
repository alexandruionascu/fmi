function y = MetLagrange(X, Y, x)
    y = 0;
    n = length(X);
    for k = 1:n
        r = X(1:(k - 1));
        if k < n
          r = [r; X((k + 1):n)];
        end
        top = prod(x * ones(n - 1, 1) - r);
        bot = prod(X(k) * ones(n - 1, 1) - r);
        L = top / bot;
        y = y + L * Y(k);
    end
end