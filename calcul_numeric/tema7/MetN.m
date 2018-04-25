function y = MetN(X, Y, x)
    n = length(X);
    A = zeros(n, n);
    A(:, 1) = 1;
    
    for i = 2:n
        for j = 2:i
            A(i, j) = prod(X(i) * ones(j - 1, 1) - X(1:(j - 1)));
        end
    end
    coefs = SubsAsc(A, Y); 
    y = coefs(1);
    for i = 2:n
        y = y + coefs(i) * prod(x * ones(i - 1, 1) - X(1:(i - 1)));
    end
end