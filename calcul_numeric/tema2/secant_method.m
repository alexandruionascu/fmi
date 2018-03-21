function root = secant_method(f, a, b, x0, x1, eps)
  k=2;
  x(1) = x0;
  x(2) = x1;
  while abs(x(k) - x(k-1)) / (abs(x(k-1))) >= eps
    k = k + 1;
    x(k) = (x(k-2) * f(x(k-1)) - x(k-1) * f(x(k-2))) / (f(x(k-1)) - f(x(k-2)));
    if x(k) < a || x(k) > b
      disp('Dati alte valori pt x0, x1');
      break;
    end
  end
  root = x(k);
end