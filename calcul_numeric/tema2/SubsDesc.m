function [x] = SubsDesc(A, b)
  n = length(A);
  k = n - 1;
  x(n) = 1 / A(n, n) * b(n);
  while k > 0
    s = 0;
    for j = k + 1:n
      s += A(k, j) * x(j);
    end
    x(k) = 1 / A(k, k) * (b(k) - s);
    k = k - 1;
  end
end