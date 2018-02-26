function x = newton_method(f, df, x0, eps)
  prev = 0;
  x = x0;
  while abs(x - prev) > eps
    prev = x;
    x = x - f(x) / df(x);
  end
end